#include "generateWorld.h"

void UpdateWorldBlocksForAirLook(int WorldSize);
void physicSetup(bool VelocityReset);
void ProgramInit() {
	srand((unsigned int)time(NULL));
	generate(WorldBounds);
	UpdateWorldBlocksForAirLook(WorldBounds);
	physicSetup(true);
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
			if (HeadRotation.y > 0) {
				HeadRotation.y -= 90;
			} else {
				HeadRotation.y = -90;
			}
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
			if (HeadRotation.y > 0) {
				HeadRotation.y -= 90;
			} else {
				HeadRotation.y = -90;
			}
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
			if (HeadRotation.y > 0) {
				HeadRotation.y -= 90;
			} else {
				HeadRotation.y = -90;
			}
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
			if (HeadRotation.y > 0) {
				HeadRotation.y -= 90;
			} else {
				HeadRotation.y = -90;
			}
		}
	}
	Position *= -1;
}