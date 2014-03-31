#include "variables.h"

void generate(int Size) {
	for (int x = 0; x < 32; x++) {
		for (int y = 0; y < 32; y++) {
			for (int z = 0; z < 32; z++) {
				World32[x][y][z].Type = 0;
				if (x < 24 && x > 8 && y < 24 && y > 8 && z < 24 && z > 8) {
					World32[x][y][z].Type = 1;
				}
			}
		}
	}
}