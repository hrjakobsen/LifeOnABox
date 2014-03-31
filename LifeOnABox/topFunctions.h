#include "generateWorld.h"

void UpdateWorldBlocksForAirLook(int WorldSize);

void ProgramInit() {
	generate(32);
	UpdateWorldBlocksForAirLook(32);
}

void UpdateWorldBlocksForAirLook(int WorldSize) {
	for (int x = 0; x < WorldSize; x++) {
		for (int y = 0; y < WorldSize; y++) {
			for (int z = 0; z < WorldSize; z++) {
				if (World32[x + 1][y][z].Type == BLOCK_AIR || World32[x - 1][y][z].Type == BLOCK_AIR || World32[x][y + 1][z].Type == BLOCK_AIR || World32[x][y - 1][z].Type == BLOCK_AIR || World32[x][y][z + 1].Type == BLOCK_AIR || World32[x][y][z - 1].Type == BLOCK_AIR) {
					World32[x][y][z].AirBesids = true;
				} else {
					World32[x][y][z].AirBesids = false;
				}
			}
		}
	}
}