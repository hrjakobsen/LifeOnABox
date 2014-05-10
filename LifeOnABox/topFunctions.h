#include "generateWorld.h"

void UpdateWorldBlocksForAirLook(int WorldSize);
void physicSetup(bool VelocityReset);
void UpdateMiniMapView(bool onlyOneBlock, int y, int z);
void UpdateSingleAirBlock(int x, int y, int z);
void saveWorld();
void loadWorld();
void ResetTime();
void display();

void ProgramInit() {
	srand((unsigned int)time(NULL));
	seed = rand();
	srand(seed);
	physicSetup(true);
}

void UpdateSingleAirBlock(int X, int Y, int Z) {
	for (int x = X - 1; x <= X + 1; x++) {
		for (int y = Y - 1; y <= Y + 1; y++) {
			for (int z = Z - 1; z <= Z + 1; z++) {
				if (World32[x + 1][y][z].Type == BLOCK_AIR || World32[x - 1][y][z].Type == BLOCK_AIR || World32[x][y + 1][z].Type == BLOCK_AIR || World32[x][y - 1][z].Type == BLOCK_AIR || World32[x][y][z + 1].Type == BLOCK_AIR || World32[x][y][z - 1].Type == BLOCK_AIR) {
					World32[x][y][z].AirBesids = true;
				} else {
					World32[x][y][z].AirBesids = false;
				}
			}
		}
	}
}

void UpdateWorldBlocksForAirLook(int WorldSize) {
	for (int x = 1; x < WorldSize - 1; x++) {
		for (int y = 1; y < WorldSize - 1; y++) {
			for (int z = 1; z < WorldSize - 1; z++) {
				if (World32[x + 1][y][z].Type == BLOCK_AIR || World32[x - 1][y][z].Type == BLOCK_AIR || World32[x][y + 1][z].Type == BLOCK_AIR || World32[x][y - 1][z].Type == BLOCK_AIR || World32[x][y][z + 1].Type == BLOCK_AIR || World32[x][y][z - 1].Type == BLOCK_AIR) {
					World32[x][y][z].AirBesids = true;
				} else {
					World32[x][y][z].AirBesids = false;
				}
			}
		}
	}
}

void UpdateMiniMapView(bool onlyOneBlock, int y, int z) {
	if (onlyOneBlock) {
		for (int x = WorldBounds / 2; x >= 1; x--) {
			if (World32[x][y][z].Type != BLOCK_AIR) {
				MiniMapView[y - WorldBounds / 4][z - WorldBounds / 4] = World32[x][y][z].Type;
			}
		}
	} else {
		for (int x = WorldBounds / 2; x >= 1; x--) {
			for (int y = WorldBounds / 4; y < WorldBounds / 4 * 3; y++) {
				for (int z = WorldBounds / 4; z < WorldBounds / 4 * 3; z++) {
					if (World32[x][y][z].Type != BLOCK_AIR) {
						MiniMapView[y - WorldBounds / 4][z - WorldBounds / 4] = World32[x][y][z].Type;
					}
				}
			}
		}
	}
}

void SwapTwoVariabels(int &A, int &B) {
	A = A + B;
	B = A - B;
	A = A - B;
}

void RotateWorld(int Direction) {
	Blocks Temp;
	for (int x = 0; x < WorldBounds; x++) {
		for (int y = 0; y < WorldBounds / 2; y++) {
			for (int z = 0; z < WorldBounds / 2; z++) {
				if (Direction == 0) {
					Temp = World32[y][z][x];
					World32[y][z][x] = World32[WorldBounds - z - 1][y][x];
					World32[WorldBounds - z - 1][y][x] = World32[WorldBounds - y - 1][WorldBounds - z - 1][x];
					World32[WorldBounds - y - 1][WorldBounds - z - 1][x] = World32[z][WorldBounds - y - 1][x];
					World32[z][WorldBounds - y - 1][x] = Temp;
				} else if (Direction == 1) {
					Temp = World32[z][WorldBounds - y - 1][x];
					World32[z][WorldBounds - y - 1][x] = World32[WorldBounds - y - 1][WorldBounds - z - 1][x];
					World32[WorldBounds - y - 1][WorldBounds - z - 1][x] = World32[WorldBounds - z - 1][y][x];
					World32[WorldBounds - z - 1][y][x] = World32[y][z][x];
					World32[y][z][x] = Temp;
				} else if (Direction == 2) {
					Temp = World32[y][x][z];
					World32[y][x][z] = World32[WorldBounds - z - 1][x][y];
					World32[WorldBounds - z - 1][x][y] = World32[WorldBounds - y - 1][x][WorldBounds - z - 1];
					World32[WorldBounds - y - 1][x][WorldBounds - z - 1] = World32[z][x][WorldBounds - y - 1];
					World32[z][x][WorldBounds - y - 1] = Temp;
				} else if (Direction == 3) {
					Temp = World32[z][x][WorldBounds - y - 1];
					World32[z][x][WorldBounds - y - 1] = World32[WorldBounds - y - 1][x][WorldBounds - z - 1];
					World32[WorldBounds - y - 1][x][WorldBounds - z - 1] = World32[WorldBounds - z - 1][x][y];
					World32[WorldBounds - z - 1][x][y] = World32[y][x][z];
					World32[y][x][z] = Temp;
				}
			}
		}
	}
	RotateCoolDown = FramesPerSecond;
}

void PlayerRotationCheck() {
	Position *= -1;
	if (Position.x > WorldBounds / 4 && RotateCoolDown <= 0) {
		if (Position.z < WorldBounds / 4) {
			RotateWorld(2);
			float Temp = Position.x;
			Position.x = Position.z;
			Position.z = WorldBounds - Temp;
			Temp = bodyParticles[0].velocity.x;
			bodyParticles[0].velocity.x = bodyParticles[0].velocity.z;
			bodyParticles[0].velocity.z = -Temp;
			Position *= -1;
			physicSetup(false);
			Position *= -1;
			UpdateMiniMapView(false, 0, 0);
		} else if (Position.z > WorldBounds / 4 * 3) {
			RotateWorld(3);
			float Temp = Position.x;
			Position.x = WorldBounds - Position.z;
			Position.z = Temp;
			Temp = bodyParticles[0].velocity.x;
			bodyParticles[0].velocity.x = bodyParticles[0].velocity.z;
			bodyParticles[0].velocity.z = Temp;
			Position *= -1;
			physicSetup(false);
			Position *= -1;
			UpdateMiniMapView(false, 0, 0);
		} else if (Position.y < WorldBounds / 4) {
			RotateWorld(0);
			float Temp = Position.x;
			Position.x = Position.y;
			Position.y = WorldBounds - Temp;
			Temp = bodyParticles[0].velocity.x;
			bodyParticles[0].velocity.x = bodyParticles[0].velocity.y;
			bodyParticles[0].velocity.y = -Temp;
			Position *= -1;
			physicSetup(false);
			Position *= -1;
			UpdateMiniMapView(false, 0, 0);
		} else if (Position.y > WorldBounds / 4 * 3) {
			RotateWorld(1);
			float Temp = Position.x;
			Position.x = WorldBounds - Position.y;
			Position.y = Temp;
			Temp = bodyParticles[0].velocity.x;
			bodyParticles[0].velocity.x = bodyParticles[0].velocity.y;
			bodyParticles[0].velocity.y = Temp;
			Position *= -1;
			physicSetup(false);
			Position *= -1;
			UpdateMiniMapView(false, 0, 0);
		}
	}
	Position *= -1;
}

void LookingAt() {
	vector3D HeadPos = Position * -1;
	HeadPos.x -= playerHeight;
	vector3D Direction;
	Direction.x = sinf(HeadRotation.y*DECTORAD);
	Direction.y = sinf(-HeadRotation.x*DECTORAD)*cosf(HeadRotation.y*DECTORAD);
	Direction.z = cosf(-HeadRotation.x*DECTORAD)*cosf(HeadRotation.y*DECTORAD);
	//std::cout << "x: " << Direction.x << ", y: " << Direction.y << ", z: " << Direction.z << std::endl;
	Direction.normalize();
	
	bool Found = false;

	for (float i = 0; i < reach; i += 0.01) {
		vector3D newPosition = HeadPos + Direction * i;
		if (World32[(int)newPosition.x][(int)newPosition.y][(int)newPosition.z].Type != BLOCK_AIR) {
			BlockLookingAt = vector3D((int)newPosition.x, (int)newPosition.y, (int)newPosition.z);
			newPosition = HeadPos + Direction * (i-0.01);
			BlockPlacePos = vector3D((int)newPosition.x, (int)newPosition.y, (int)newPosition.z);
			Found = true;
			break;
		}
	}
	if (!Found) {
		BlockLookingAt = vector3D(-1, -1, -1);
		BlockPlacePos = vector3D(-1, -1, -1);
	}
}

void BreakBlock() {
	if (BlockLookingAt.x > 0) {
		if (World32[(int)BlockLookingAt.x][(int)BlockLookingAt.y][(int)BlockLookingAt.z].Type != BLOCK_AIR && World32[(int)BlockLookingAt.x][(int)BlockLookingAt.y][(int)BlockLookingAt.z].Type != BLOCK_BED_ROCK) {
			World32[(int)BlockLookingAt.x][(int)BlockLookingAt.y][(int)BlockLookingAt.z].Type = BLOCK_AIR;
			UpdateSingleAirBlock((int)BlockLookingAt.x, (int)BlockLookingAt.y, (int)BlockLookingAt.z);
			UpdateMiniMapView(true, (int)BlockLookingAt.y, (int)BlockLookingAt.z);
		}
	}
}
void PlaceBlock() {
	if (BlockPlacePos.x > 0 && BlockPlacePos.y > WorldBounds / 4 && BlockPlacePos.z > WorldBounds / 4 && BlockPlacePos.y < 3 * WorldBounds / 4-1 && BlockPlacePos.z < 3 * WorldBounds / 4-1) {
		World32[(int)BlockPlacePos.x][(int)BlockPlacePos.y][(int)BlockPlacePos.z].Type = chosenBlock;
		bool impossibru = false;
		for (int i = 0; i < 12; i++) {
			int x = bodyParticles[i].position.x - 2;
			int y = bodyParticles[i].position.y;
			int z = bodyParticles[i].position.z;
			if (World32[x][y][z].Type != BLOCK_AIR) {
				impossibru = true;
			}
		}
		if (!impossibru) {
			UpdateSingleAirBlock((int)BlockPlacePos.x, (int)BlockPlacePos.y, (int)BlockPlacePos.z);
			UpdateMiniMapView(true, (int)BlockPlacePos.y, (int)BlockPlacePos.z);
		} else {
			World32[(int)BlockPlacePos.x][(int)BlockPlacePos.y][(int)BlockPlacePos.z].Type = BLOCK_AIR;
		}
	}
}