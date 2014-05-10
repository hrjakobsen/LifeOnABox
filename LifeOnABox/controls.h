#include "collisionDetection.h"

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
	if (HeadRotation.y > 90) {
		HeadRotation.y = 90;
	}
	if (HeadRotation.y < -90) {
		HeadRotation.y = -90;
	}
}

void keyBoardCallBackUp(unsigned char key, int x, int y) {
	KEYS[key] = false;
	if (key == 'W' || key == 'A' || key == 'S' || key == 'D' || key == 'Z') {
		KEYS[key + 32] = false;
	}
}

void keyBoardCallBackDown(unsigned char key, int x, int y) {
	KEYS[key] = true;
	if (key == 'W' || key == 'A' || key == 'S' || key == 'D' || key == 'Z') {
		KEYS[key] = false;
		KEYS[key + 32] = true;
	}
}

void MenuControls() {
	if (KEYS['1']) {
		ChosenMenuItem = 1;
	}
	if (KEYS['2']) {
		ChosenMenuItem = 2;
	}
	if (KEYS['3']) {
		ChosenMenuItem = 3;
	}
	if (KEYS['4']) {
		ChosenMenuItem = 4;
	}
	if (KEYS[32]) {
		if (!IsSpaceHoldIn) {
			IsSpaceHoldIn = true;
			if (ChosenMenuItem == 4) {
				glutDestroyWindow(glutGetWindow());
				exit(0);
			}
			if (gamestate == 0) {
				worldNumber = ChosenMenuItem;
				if (DoesWorldExist()) {
					Gamestate4Text = "LOADING";
					gamestate = 4;
					display();
					loadWorld();
				} else {
					gamestate = 2;
				}
			} else if (gamestate == 2) {
				if (ChosenMenuItem == 1) {
					WorldBounds = 64;
				} else if (ChosenMenuItem == 2) {
					WorldBounds = 128;
				} else if (ChosenMenuItem == 3) {
					WorldBounds = 256;
				}
				generate(WorldBounds);
				UpdateWorldBlocksForAirLook(WorldBounds);
				UpdateMiniMapView(false, 0, 0);
				Position = vector3D(-WorldBounds / 4, -WorldBounds / 4, -WorldBounds / 4);
				ProgramInit();
				gamestate = 1;
			} else if (gamestate == 3) {
				if (ChosenMenuItem == 1) {
					Gamestate4Text = "SAVING";
					gamestate = 4;
					display();
					saveWorld();
					glutDestroyWindow(glutGetWindow());
					exit(0);
				} else if (ChosenMenuItem == 2) {
					Gamestate4Text = "SAVING";
					gamestate = 4;
					display();
					saveWorld();
					gamestate = 0;
				} else if (ChosenMenuItem == 3) {
					Gamestate4Text = "SAVING";
					gamestate = 4;
					display();
					saveWorld();
					gamestate = 1;
				}
			}
			ChosenMenuItem = 1;
		}
	} else {
		IsSpaceHoldIn = false;
	}
}

void updatePlayerMotion() {
	if (KEYS[27]) { // ESC
		gamestate = 3;
	}
	float XX = 0;
	float ZZ = 0;
	float YY = 0;
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
	if (KEYS[32] && IsPlayerOnGround) {
		YY += 5;
		IsPlayerOnGround = false;
		
	}
	for (int i = 49; i < 58; i++) {
		if (KEYS[i]) {
			chosenBlock = i - 47;
		}
	}
	/*if (KEYS['z'] && RotateCoolDown <= 0) {
		RotateWorld(3);
		RotateCoolDown = FramesPerSecond;
	}*/
	AddVelocityToPlayer(-YY, 0);
	movePlayer(-XX, 1);
	movePlayer(-ZZ, 2);
}
void mouseClick(int button, int state, int x, int y) {
	std::cout << button << ", " << state << "\n";
	if (button == 0 && state == 0) {
		BreakBlock();
	}
	if (button == 2 && state == 0) {
		PlaceBlock();
	}
}