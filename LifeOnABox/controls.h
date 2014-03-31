#include "topFunctions.h"

bool FirstTime = true;
int lastX, lastY;

void mouseMotion(int x, int y) {
	if (FirstTime) {
		FirstTime = false;
		lastY = y;
		lastX = x;
	}
	else {
		FirstTime = true;
		HeadRotation.x += (x - lastX) / CameraSensitivity;
		HeadRotation.y += (y - lastY) / CameraSensitivity;
		SetCursorPos(ScreenWidth / 2, ScreenHeight / 2);
		lastY = ScreenHeight / 2;
		lastX = ScreenWidth / 2;
	}
	if (HeadRotation.y > 45) {
		HeadRotation.y = 45;
	}
	if (HeadRotation.y < -45) {
		HeadRotation.y = -45;
	}
}

void keyBoardCallBackUp(unsigned char key, int x, int y) {
	KEYS[key] = false;
	if (key == 'W' || key == 'A' || key == 'S' || key == 'D' || key == 'E') {
		KEYS[key + 32] = false;
	}
}

void keyBoardCallBackDown(unsigned char key, int x, int y) {
	KEYS[key] = true;
	if (key == 'W' || key == 'A' || key == 'S' || key == 'D' || key == 'E') {
		KEYS[key] = false;
		KEYS[key + 32] = true;
	}
}

void updatePlayerMotion() {
	if (KEYS[27]) { // ESC
		glutDestroyWindow(glutGetWindow());
		exit(0);
	}
	float XX = 0;
	float ZZ = 0;
	if (KEYS['w']) {
		XX += sin(DECTORAD * HeadRotation.x) * Speed;
		ZZ += -cos(DECTORAD * HeadRotation.x) * Speed;
	}
	if (KEYS['s']) {
		XX += -sin(DECTORAD * HeadRotation.x) * Speed;
		ZZ += cos(DECTORAD * HeadRotation.x) * Speed;
	}
	if (KEYS['a']) {
		XX += -cos(DECTORAD * HeadRotation.x) * Speed;
		ZZ += -sin(DECTORAD * HeadRotation.x) * Speed;
	}
	if (KEYS['d']) {
		XX += cos(DECTORAD * HeadRotation.x) * Speed;
		ZZ += sin(DECTORAD * HeadRotation.x) * Speed;
	}
	Position.y += XX;
	Position.z += ZZ;
}