#include "variables.h"

void generate(int Size) {
	for (int x = 0; x < 32; x++) {
		for (int y = 0; y < 32; y++) {
			for (int z = 0; z < 32; z++) {
				World32[x][y][z] = 0;
				if (x == 0) {
					World32[x][y][z] = 1;
				}
			}
		}
	}
}