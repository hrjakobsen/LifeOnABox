#include "variables.h"

Blocks Plane16[16][16][8];

void CreateTrees(int WorldSize, float HowOffen);

void generate(int Size) {
	for (int x = 0; x < 32; x++) {
		for (int y = 0; y < 32; y++) {
			for (int z = 0; z < 32; z++) {
				World32[x][y][z].Type = 0;
				if (x < 24 && x >= 8 && y < 24 && y >= 8 && z < 24 && z >= 8) {
					World32[x][y][z].Type = BLOCK_GRASS;
				}
			}
		}
	}
	CreateTrees(16, .2);
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			for (int z = 0; z < 8; z++) {
				World32[7 - z][y + 8][x + 8].Type = Plane16[x][y][z].Type;
			}
		}
	}
}

void CreateTrees(int WorldSize, float HowOffen) {
	int Chance = 1 / HowOffen;
	for (int x = 0; x < WorldSize; x++) {
		for (int y = 0; y < WorldSize; y++) {
			bool OtherNearBy = false;
			for (int XX = -2; XX <= 2; XX++) {
				for (int YY = -2; YY <= 2; YY++) {
					int X = x + XX;
					int Y = y + YY;
					if (Plane16[X][Y][0].Type == BLOCK_WOOD) {
						OtherNearBy = true;
					}
				}
			}
			if (rand() % Chance == 0 && x >= 2 && y >= 2 && x <= WorldSize - 3 && y <= WorldSize - 3 && !OtherNearBy) {
				vector3D MidPoint; 
				int Height = rand() % 3 + 3;
				for (int z = 0; z < Height; z++) {
					Plane16[x][y][z].Type = BLOCK_WOOD;
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
							if (Distance.squareMagnitude() <= LeavesRadius * LeavesRadius && Plane16[X][Y][z].Type == BLOCK_AIR) {
								Plane16[X][Y][z].Type = BLOCK_LEAVES;
							}
						}
					}
				}
			}
		}
	}
}