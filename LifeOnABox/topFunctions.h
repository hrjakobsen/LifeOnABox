#include "generateWorld.h"

void UpdateWorldBlocksForAirLook(int WorldSize);
void physicSetup();
void ProgramInit() {
	srand((unsigned int)time(NULL));
	generate(WorldBounds);
	UpdateWorldBlocksForAirLook(WorldBounds);
	physicSetup();
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