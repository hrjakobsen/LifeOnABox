#include "variables.h"

Blocks Plane16[128][128][128];
short HeightPorfile[128][128];

void ClearPlaneAndHeightProfile(int WorldSize);
void CreateTrees(int WorldSize, float HowOffen, int LeaveBlock, int WoodBlock);
void CreateHillyTerrain(int WorldSize, int Hilly, int TopBlock, int RestBlock, int MiddelBlock, int NumberOfLayersWithMiddelBlock, int NumberOfLayersWithTopBlock);

void generate(int Size) {
	for (int x = 0; x < Size; x++) {
		for (int y = 0; y < Size; y++) {
			for (int z = 0; z < Size; z++) {
				if (x < Size * 3 / 4 && x >= Size * 1 / 4 && y < Size * 3 / 4 && y >= Size * 1 / 4 && z < Size * 3 / 4 && z >= Size * 1 / 4) {
					World32[x][y][z].Type = BLOCK_BED_ROCK;
				} else {
					World32[x][y][z].Type = BLOCK_AIR;
				}
			}
		}
	}
	ClearPlaneAndHeightProfile(Size / 2);
	CreateHillyTerrain(Size / 2, Size / 6, BLOCK_GRASS, BLOCK_STONE, BLOCK_DIRT, 3, 1);
	CreateTrees(Size / 2, .02, BLOCK_LEAVES, BLOCK_WOOD);
	for (int x = 0; x < Size / 2; x++) {
		for (int y = 0; y < Size / 2; y++) {
			for (int z = 0; z < Size / 2; z++) {
				if (Plane16[x][y][z].Type != BLOCK_AIR) {
					World32[(Size / 2 - 1) - z][y + Size / 4][x + Size / 4].Type = Plane16[x][y][z].Type;
				}
			}
		}
	}
	ClearPlaneAndHeightProfile(Size / 2);
	CreateHillyTerrain(Size / 2, Size / 8, BLOCK_SAND, BLOCK_STONE, BLOCK_SAND, 2, 1);
	for (int x = 0; x < Size / 2; x++) {
		for (int y = 0; y < Size / 2; y++) {
			for (int z = 0; z < Size / 2; z++) {
				if (Plane16[x][y][z].Type != BLOCK_AIR) {
					World32[x + Size / 4][y + Size / 4][z + Size / 2].Type = Plane16[x][y][z].Type;
				}
			}
		}
	}
	ClearPlaneAndHeightProfile(Size / 2);
	CreateHillyTerrain(Size / 2, Size / 6, BLOCK_DARKSTONE, BLOCK_DARKSTONE, BLOCK_DARKSTONE, 1, 1);
	CreateTrees(Size / 2, .05, BLOCK_DARKSTONE, BLOCK_STONE);
	for (int x = 0; x < Size / 2; x++) {
		for (int y = 0; y < Size / 2; y++) {
			for (int z = 0; z < Size / 2; z++) {
				if (Plane16[x][y][z].Type != BLOCK_AIR) {
					World32[(Size / 2) + z][y + Size / 4][x + Size / 4].Type = Plane16[x][y][z].Type;
				}
			}
		}
	}
	ClearPlaneAndHeightProfile(Size / 2);
	CreateHillyTerrain(Size / 2, 5, BLOCK_GRASS, BLOCK_STONE, BLOCK_DIRT, 3, 1);
	CreateTrees(Size / 2, .25, BLOCK_LEAVES, BLOCK_WOOD);
	for (int x = 0; x < Size / 2; x++) {
		for (int y = 0; y < Size / 2; y++) {
			for (int z = 0; z < Size / 2; z++) {
				if (Plane16[x][y][z].Type != BLOCK_AIR) {
					World32[x + Size / 4][y + Size / 4][(Size / 2 - 1) - z].Type = Plane16[x][y][z].Type;
				}
			}
		}
	}
	ClearPlaneAndHeightProfile(Size / 2);
	CreateHillyTerrain(Size / 2, 5, BLOCK_YELLOW_GRASS, BLOCK_STONE, BLOCK_DIRT, 3, 1);
	CreateTrees(Size / 2, .01, BLOCK_LEAVES, BLOCK_WOOD);
	for (int x = 0; x < Size / 2; x++) {
		for (int y = 0; y < Size / 2; y++) {
			for (int z = 0; z < Size / 2; z++) {
				if (Plane16[x][y][z].Type != BLOCK_AIR) {
					World32[y + Size / 4][(Size / 2 - 1) - z][x + Size / 4].Type = Plane16[x][y][z].Type;
				}
			}
		}
	}
	ClearPlaneAndHeightProfile(Size / 2);
	CreateHillyTerrain(Size / 2, Size / 8, BLOCK_STONE, BLOCK_DARKSTONE, BLOCK_STONE, 3, 1);
	for (int x = 0; x < Size / 2; x++) {
		for (int y = 0; y < Size / 2; y++) {
			for (int z = 0; z < Size / 2; z++) {
				if (Plane16[x][y][z].Type != BLOCK_AIR) {
					World32[y + Size / 4][(Size / 2) + z][x + Size / 4].Type = Plane16[x][y][z].Type;
				}
			}
		}
	}
	/*World32[WorldBounds / 2][WorldBounds / 2][WorldBounds / 2].SpecialNumber = 1;
	World32[WorldBounds / 2][WorldBounds / 2][WorldBounds / 2 - 1].SpecialNumber = 2;
	World32[WorldBounds / 2][WorldBounds / 2 - 1][WorldBounds / 2].SpecialNumber = 3;
	World32[WorldBounds / 2][WorldBounds / 2 - 1][WorldBounds / 2 - 1].SpecialNumber = 4;
	World32[WorldBounds / 2 - 1][WorldBounds / 2][WorldBounds / 2].SpecialNumber = 5;
	World32[WorldBounds / 2 - 1][WorldBounds / 2][WorldBounds / 2 - 1].SpecialNumber = 6;
	World32[WorldBounds / 2 - 1][WorldBounds / 2 - 1][WorldBounds / 2].SpecialNumber = 7;
	World32[WorldBounds / 2 - 1][WorldBounds / 2 - 1][WorldBounds / 2 - 1].SpecialNumber = 8;*/
}

void ClearPlaneAndHeightProfile(int WorldSize) {
	for (int i = 0; i < WorldSize; i++) {
		for (int ii = 0; ii < WorldSize; ii++) {
			HeightPorfile[i][ii] = WorldSize / 2;
		}
	}
	for (int x = 0; x < WorldSize; x++) {
		for (int y = 0; y < WorldSize; y++) {
			for (int z = 0; z < WorldSize; z++) {
				Plane16[x][y][z].Type = BLOCK_AIR;
			}
		}
	}
}

void CreateTrees(int WorldSize, float HowOffen, int LeaveBlock, int WoodBlock) {
	int Chance = 1 / HowOffen;
	for (int x = 0; x < WorldSize; x++) {
		for (int y = 0; y < WorldSize; y++) {
			bool OtherNearBy = false;
			for (int XX = -2; XX <= 2; XX++) {
				for (int YY = -2; YY <= 2; YY++) {
					int X = x + XX;
					int Y = y + YY;
					if (Plane16[X][Y][HeightPorfile[X][Y]].Type == WoodBlock) {
						OtherNearBy = true;
					}
				}
			}
			if (rand() % Chance == 0 && x >= 3 && y >= 3 && x <= WorldSize - 4 && y <= WorldSize - 4 && !OtherNearBy) {
				vector3D MidPoint; 
				int Height = rand() % 3 + 3;
				for (int z = 0; z < Height; z++) {
					Plane16[x][y][z + HeightPorfile[x][y]].Type = WoodBlock;
					MidPoint = vector3D(x, y, z);
				}
				int LeavesRadius = rand() % 2 + 1;
				if (WorldSize == 16 && Height == 5 && LeavesRadius == 3) { // To make sure the tree dos not go outste the world bounderis
					LeavesRadius--;
				}
				for (int z = 0; z < WorldSize / 2; z++) {
					for (int XX = -LeavesRadius; XX <= LeavesRadius; XX++) {
						for (int YY = -LeavesRadius; YY <= LeavesRadius; YY++) {
							int X = x + XX;
							int Y = y + YY;
							vector3D Distance = vector3D(X - MidPoint.x, Y - MidPoint.y, z - MidPoint.z);
							if (Distance.squareMagnitude() <= LeavesRadius * LeavesRadius && Plane16[X][Y][z + HeightPorfile[x][y]].Type == BLOCK_AIR) {
								Plane16[X][Y][z + HeightPorfile[x][y]].Type = LeaveBlock;
							}
						}
					}
				}
			}
		}
	}
}

void CreateHillyTerrain(int WorldSize, int Hilly, int TopBlock, int RestBlock, int MiddelBlock, int NumberOfLayersWithMiddelBlock, int NumberOfLayersWithTopBlock) {
	if (WorldSize > 32) {
		for (int x = 0; x <= WorldSize / 16; x++) {
			for (int y = 0; y <= WorldSize / 16; y++) {
				HeightPorfile[x * 15 + 2][y * 15 + 2] = rand() % (Hilly + 1) + WorldSize / 2;
				if (x == 0 || y == 0 || x == WorldSize / 16 || y == WorldSize / 16) {
					HeightPorfile[x * 15 + 2][y * 15 + 2] = WorldSize / 2;
				}
			}
		}
		for (int x = 0; x <= WorldSize / 16; x++) {
			for (int y = 0; y < WorldSize / 16; y++) {
				int X = x * 15 + 2;
				int Y = y * 15 + 2;
				int H1 = HeightPorfile[X][Y];
				int H2 = HeightPorfile[X][Y + 15];
				float Step = ((float)(H1 - H2)) / 15;
				for (int YY = 1; YY <= 14; YY++) {
					HeightPorfile[X][Y + YY] = (-Step * YY) + H1;
				}
			}
		}
		for (int x = 0; x < WorldSize / 16; x++) {
			for (int y = 0; y <= WorldSize; y++) {
				int X = x * 15 + 2;
				int Y = y;
				int H1 = HeightPorfile[X][Y];
				int H2 = HeightPorfile[X + 15][Y];
				float Step = ((float)(H1 - H2)) / 15;
				for (int XX = 1; XX <= 14; XX++) {
					HeightPorfile[X + XX][Y] = (-Step * XX) + H1;
				}
			}
		}
	}

	// Create ground
	for (int z = 1; z < WorldSize / 2; z++) {
		int RemaningToBorder = WorldSize / 2 - z;
		for (int x = 0; x < (z) * 2; x++) {
			for (int y = 0; y < (z) * 2; y++) {
				Plane16[x + RemaningToBorder][y + RemaningToBorder][z].Type = RestBlock;
			}
		}
	}
	for (int x = 1; x < WorldSize - 1; x++) {
		for (int y = 1; y < WorldSize - 1; y++) {
			for (int z = WorldSize / 2; z < WorldSize; z++) {
				if (z < HeightPorfile[x][y]) {
					Plane16[x][y][z].Type = RestBlock;
				}
			}
		}
	}
	for (int x = 1; x < WorldSize - 1; x++) {
		for (int y = 1; y < WorldSize - 1; y++) {
			int Left = NumberOfLayersWithTopBlock;
			int LeftM = NumberOfLayersWithMiddelBlock;
			for (int z = WorldSize - 1; z > 0; z--) {
				if (Plane16[x][y][z].Type != BLOCK_AIR) {
					if (Left > 0) {
						Plane16[x][y][z].Type = TopBlock;
						Left--;
					} else if (LeftM > 0) {
						Plane16[x][y][z].Type = MiddelBlock;
						LeftM--;
					} else {
						z = 0;
					}
				}
			}
		}
	}
}