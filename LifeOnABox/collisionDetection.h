#include "topFunctions.h"

void physicSetup() {
	//Unti position is fixed
	Position *= -1;
	for (int i = 0; i < 8; i++){
		bodyParticles[i].acceleration = vector3D(g, 0, 0); //-g for acceleration towards Earth
		bodyParticles[i].velocity = vector3D(0,0,0);
	}
	bodyParticles[0].position = vector3D(Position.x, Position.y - playerRadius, Position.z - playerRadius);
	bodyParticles[1].position = vector3D(Position.x, Position.y - playerRadius, Position.z + playerRadius);
	bodyParticles[2].position = vector3D(Position.x, Position.y + playerRadius, Position.z - playerRadius);
	bodyParticles[3].position = vector3D(Position.x, Position.y + playerRadius, Position.z + playerRadius);
	bodyParticles[4].position = vector3D(Position.x + playerHeight, Position.y - playerRadius, Position.z - playerRadius);
	bodyParticles[5].position = vector3D(Position.x + playerHeight, Position.y - playerRadius, Position.z + playerRadius);
	bodyParticles[6].position = vector3D(Position.x + playerHeight, Position.y + playerRadius, Position.z - playerRadius);
	bodyParticles[7].position = vector3D(Position.x + playerHeight, Position.y + playerRadius, Position.z + playerRadius);

	Position *= -1;
}

void physicTick(float deltaTime){
	for (int divider = 2; divider <= 8; divider *= 2) {
		bool impossibru = false;
		particle bodyParticlesCopy[8];
		for (int i = 0; i < 8; i++) {
			bodyParticlesCopy[i] = bodyParticles[i];
			bodyParticlesCopy[i].update(deltaTime / divider);
		}
		for (int i = 0; i < 8; i++) {
			int x = bodyParticlesCopy[i].position.x-2;
			int y = bodyParticlesCopy[i].position.y;
			int z = bodyParticlesCopy[i].position.z;
			if (World32[x][y][z].Type != BLOCK_AIR) {
				impossibru = true;
			}
		}
		if (!impossibru) {
			for (int i = 0; i < 8; i++) {
				bodyParticles[i] = bodyParticlesCopy[i];
			}
		}
		else {
			for (int i = 0; i < 8; i++) {
				bodyParticles[i].velocity = vector3D();
			}
		}
	}
	Position *= -1;
	Position.x = bodyParticles[0].position.x;
	Position.y = bodyParticles[0].position.y + playerRadius;
	Position.z = bodyParticles[0].position.z + playerRadius;
	Position *= -1;
	
}

void movePlayer(float movement, int XYZ) {
	for (int divider = 2; divider <= 8; divider *= 2) {
		bool impossibru = false;
		particle bodyParticlesCopy[8];
		for (int i = 0; i < 8; i++) {
			bodyParticlesCopy[i] = bodyParticles[i];
			if (XYZ == 0) {
				bodyParticlesCopy[i].position.x += movement / divider;
			} else if(XYZ == 1) {
				bodyParticlesCopy[i].position.y += movement / divider;
			} else if(XYZ == 2) {
				bodyParticlesCopy[i].position.z += movement / divider;
			}
		}
		for (int i = 0; i < 8; i++) {
			int x = bodyParticlesCopy[i].position.x - 2;
			int y = bodyParticlesCopy[i].position.y;
			int z = bodyParticlesCopy[i].position.z;
			if (World32[x][y][z].Type != BLOCK_AIR) {
				impossibru = true;
			}
		}
		if (!impossibru) {
			for (int i = 0; i < 8; i++) {
				bodyParticles[i] = bodyParticlesCopy[i];
			}
		}
	}
	Position *= -1;
	Position.x = bodyParticles[0].position.x;
	Position.y = bodyParticles[0].position.y + playerRadius;
	Position.z = bodyParticles[0].position.z + playerRadius;
	Position *= -1;

}