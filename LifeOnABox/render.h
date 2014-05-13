#include "controls.h"

void drawString(char letter[], int length) {
	for (int i = 0; i < length; i++) {
		glTranslatef(8 * i, 0, 0);
		drawChar(letter[i]);
		glTranslatef(-8 * i, 0, 0);
	}
}

void drawRealString(std::string letter, int length) {
	for (int i = 0; i < length; i++) {
		glTranslatef(8 * i, 0, 0);
		drawChar(letter[i]);
		glTranslatef(-8 * i, 0, 0);
	}
}

void CreateSquare(float SideLength) {
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0, 0);
	glVertex2f(0, SideLength);
	glVertex2f(SideLength, SideLength);
	glVertex2f(SideLength, 0);
	glEnd();
}

void CreateArrow(float Length, float Angle) {
	glRotatef(Angle, 0, 0, 1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0, Length / 2);
	glVertex2f(-Length / 4, -Length / 2);
	glVertex2f(0, -Length / 4);
	glVertex2f(Length / 4, -Length / 2);
	glEnd();
	glRotatef(-Angle, 0, 0, 1);
}

void MiniMap() {
	glColor3f(.1, .1, .1);
	glTranslatef(.00475 *2, .002 *2, -.02);
	if (WorldBounds == 32) {
		CreateSquare(.0040);
	} else {
		CreateSquare(.0042);
	}
	glTranslatef(-.00475, -.002, .01);
	for (int z = 1; z < 16; z++) {
		for (int y = 1; y < 16; y++) {
			
			if (WorldBounds == 32 && (z == 15 || y == 15)) {
				// Her skla vi ikke tage kanten med
			} else {
				glTranslatef(.002 / 16 * z, .002 / 16 * y, 0);
				if (MiniMapView[y * (WorldBounds / 32)][z * (WorldBounds / 32)] == BLOCK_GRASS) {
					glColor3f(0, 1, 0);
				} else if (MiniMapView[y * (WorldBounds / 32)][z * (WorldBounds / 32)] == BLOCK_WOOD) {
					glColor3f(0.55, 0.27, 0.08);
				} else if (MiniMapView[y * (WorldBounds / 32)][z * (WorldBounds / 32)] == BLOCK_LEAVES) {
					glColor3f(0.4, .8, 0.4);
				} else if (MiniMapView[y * (WorldBounds / 32)][z * (WorldBounds / 32)] == BLOCK_BED_ROCK) {
					glColor3f(0.1, 0.1, 0.1);
				} else if (MiniMapView[y * (WorldBounds / 32)][z * (WorldBounds / 32)] == BLOCK_DIRT) {
					glColor3f(0.44, 0.37, 0.15);
				} else if (MiniMapView[y * (WorldBounds / 32)][z * (WorldBounds / 32)] == BLOCK_STONE) {
					glColor3f(0.5, 0.5, 0.5);
				} else if (MiniMapView[y * (WorldBounds / 32)][z * (WorldBounds / 32)] == BLOCK_SAND) {
					glColor3f(0.93, 0.79, 0.38);
				} else if (MiniMapView[y * (WorldBounds / 32)][z * (WorldBounds / 32)] == BLOCK_DARKSTONE) {
					glColor3f(0.3, 0.3, 0.3);
				} else if (MiniMapView[y * (WorldBounds / 32)][z * (WorldBounds / 32)] == BLOCK_LIGHT_WOOD) {
					glColor3f(0.75, 0.47, 0.28);
				} else if (MiniMapView[y * (WorldBounds / 32)][z * (WorldBounds / 32)] == BLOCK_YELLOW_GRASS) {
					glColor3f(0.7, 1, 0);
				}
				CreateSquare(.002 / 16);
				glTranslatef(-.002 / 16 * z, -.002 / 16 * y, 0);
			}
			
		}
	}
	glColor3f(1, 1, 1);
	glTranslatef(-(Position.z) / ((WorldBounds / 2) * 1.125) * .002, -(Position.y) / ((WorldBounds / 2) * 1.125) * .002, .001);
	glTranslatef(-.0013, -.00104, 0);
	CreateArrow(.002 / 16, -HeadRotation.x - 90);
	glTranslatef(.0013, .00104, 0);
	glTranslatef((Position.z) / ((WorldBounds / 2) * 1.125) * .002, (Position.y) / ((WorldBounds / 2) * 1.125) * .002, -.001);
	glTranslatef(-.00475, -.002, .01);
}

void ItemPicker() {
	glTranslatef(0, -.0038, -.01);
	glColor3f(.4, .4, .4);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(-.0024, .0003);
	glVertex2f(-.0024, -.0003);
	glVertex2f(.0024, -.0003);
	glVertex2f(.0024, .0003);
	glEnd();
	glTranslatef(0, 0, .0005);
	for (int i = BLOCK_STONE; i <= BLOCK_YELLOW_GRASS; i++) {
		float r = 0;
		float g = 0;
		float b = 0;
		if (i == BLOCK_GRASS) {
			g = 1;
		} else if (i == BLOCK_WOOD) {
			r = .55; g = .27; b = .08;
		} else if (i == BLOCK_LEAVES) {
			r = .4; g = .8; b = .4;
		} else if (i == BLOCK_DIRT) {
			r = .44; g = .37; b = .15;
		} else if (i == BLOCK_STONE) {
			r = .5; g = .5; b = .5;
		} else if (i == BLOCK_SAND) {
			r = .93; g = .79; b = .38;
		} else if (i == BLOCK_DARKSTONE) {
			r = .3; g = .3; b = .3;
		} else if (i == BLOCK_LIGHT_WOOD) {
			r = .75; g = .47; b = .28;
		} else if (i == BLOCK_YELLOW_GRASS) {
			r = .7; g = 1;
		}
		glTranslatef(.0005 * (i - 6) - .0002, 0, 0);
		glColor3f(r, g, b);
		CreateSquare(.0004);
		if (i == chosenBlock) {
			glTranslatef(.000155 - .00002 * (i -2), .00022, .0004);
			glColor3f(r - .1, g - .1, b - .1);
			CreateSquare(.00025);
			glTranslatef(-.000155 + .00002 * (i - 2), -.00022, -.0004);
		}
		glTranslatef(-.0005 * (i - 6) + .0002, 0, 0);
	}
	glTranslatef(0, 0, -.0005);
	glTranslatef(0, .0038, .01);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	
	if (gamestate == 1) {
		MiniMap();
		ItemPicker();

		glColor3f(1, 0, 0);
		glTranslatef(0, 0, -.02);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(0.00003, 0.0003);
		glVertex2f(0.00003, -0.0003);
		glVertex2f(-0.00003, -0.0003);
		glVertex2f(-0.00003, 0.0003);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(0.0003, 0.00003);
		glVertex2f(0.0003, -0.00003);
		glVertex2f(-0.0003, -0.00003);
		glVertex2f(-0.0003, 0.00003);
		glEnd();
		glTranslatef(0, 0, .02);

		glRotatef(HeadRotation.y, 1, 0, 0);
		glRotatef(HeadRotation.x, 0, 1, 0);

		RotateCoolDown--;
		if (RotateCoolDown < 0) {
			RotateCoolDown = -1;
		}

		glColor3f(0.3, .3, 1);
		glutSolidSphere(RenderDistance +5, 20, 20);

		glTranslatef(-Position.y - .5, -Position.x - .5 - playerHeight, -Position.z - .5);

		int XD = -Position.x - RenderDistance;
		int YD = -Position.y - RenderDistance;
		int ZD = -Position.z - RenderDistance;

		int XO = -Position.x + RenderDistance;
		int YO = -Position.y + RenderDistance;
		int ZO = -Position.z + RenderDistance;

		if (XD < 1) { XD = 1; }
		if (YD < 1) { YD = 1; }
		if (ZD < 1) { ZD = 1; }

		if (XO > WorldBounds - 2) { XO = WorldBounds - 2; }
		if (YO > WorldBounds - 2) { YO = WorldBounds - 2; }
		if (ZO > WorldBounds - 2) { ZO = WorldBounds - 2; }

		float YY = sinf(HeadRotation.x * DECTORAD);
		float ZZ = cosf(HeadRotation.x * DECTORAD);


		if (abs(ZZ) > abs(YY)) {
			if (ZZ > 0) {
				ZD = Position.z * -1 - 3;
			}
			else {
				ZO = Position.z * -1 + 3;
			}
		}
		else {
			if (YY > 0) {
				YO = Position.y * -1 + 3;
			}
			else {
				YD = Position.y * -1 - 3;
			}
		}

		for (int x = XD; x < XO; x++) {
			for (int y = YD; y < YO; y++) {
				for (int z = ZD; z < ZO; z++) {
					if (World32[x][y][z].Type != BLOCK_AIR && World32[x][y][z].AirBesids) {
						vector3D Distance = vector3D(x + Position.x, y + Position.y, z + Position.z);
						float SM = Distance.squareMagnitude();
						if (SM <= RenderDistance * RenderDistance) {
							glTranslatef(-y, -x, -z);
							float r, g, b;
							r = 0;
							g = 0;
							b = 0;
							if (World32[x][y][z].Type == BLOCK_GRASS) {
								g = 1;
							}
							else if (World32[x][y][z].Type == BLOCK_WOOD) {
								r = .55; g = .27; b = .08;
							}
							else if (World32[x][y][z].Type == BLOCK_LEAVES) {
								r = .4; g = .8; b = .4;
							}
							else if (World32[x][y][z].Type == BLOCK_BED_ROCK) {
								r = .1; g = .1; b = .1;
							}
							else if (World32[x][y][z].Type == BLOCK_DIRT) {
								r = .44; g = .37; b = .15;
							}
							else if (World32[x][y][z].Type == BLOCK_STONE) {
								r = .5; g = .5; b = .5;
							}
							else if (World32[x][y][z].Type == BLOCK_SAND) {
								r = .93; g = .79; b = .38;
							}
							else if (World32[x][y][z].Type == BLOCK_DARKSTONE) {
								r = .3; g = .3; b = .3;
							}
							else if (World32[x][y][z].Type == BLOCK_LIGHT_WOOD) {
								r = .75; g = .47; b = .28;
							}
							else if (World32[x][y][z].Type == BLOCK_YELLOW_GRASS) {
								r = .7; g = 1;
							}
							if (x == BlockLookingAt.x && y == BlockLookingAt.y && z == BlockLookingAt.z) {
								r -= .1; g -= .1; b -= .1;
							}

							//r = (float)(rand() % 256) / 255;
							//g = (float)(rand() % 256) / 255;
							//b = (float)(rand() % 256) / 255;
							glColor3f(r, g, b);
							glutSolidCube(1);
							glColor3f(r - .1, g - .1, b - .1);
							float trans = .01;
							float SizeD = .9;
							if (SM <= RenderDistance * RenderDistance / 4) {
								//std::cout << SizeD << "\n";
								if (Position.y * -1 < y) {
									glTranslatef(.5 * (1 - SizeD) + trans, 0, 0);
									glutSolidCube(SizeD);
									glTranslatef(-.5 * (1 - SizeD) - trans, 0, 0);
								}
								else {
									glTranslatef(-.5 * (1 - SizeD) - trans, 0, 0);
									glutSolidCube(SizeD);
									glTranslatef(.5 * (1 - SizeD) + trans, 0, 0);
								}
								if (Position.x * -1 < x + playerHeight) {
									glTranslatef(0, .5 * (1 - SizeD) + trans, 0);
									glutSolidCube(SizeD);
									glTranslatef(0, -.5 * (1 - SizeD) - trans, 0);
								}
								else {
									glTranslatef(0, -.5 * (1 - SizeD) - trans, 0);
									glutSolidCube(SizeD);
									glTranslatef(0, .5 * (1 - SizeD) + trans, 0);
								}
								if (Position.z * -1 < z) {
									glTranslatef(0, 0, .5 * (1 - SizeD) + trans);
									glutSolidCube(SizeD);
									glTranslatef(0, 0, -.5 * (1 - SizeD) - trans);
								}
								else {
									glTranslatef(0, 0, -.5 * (1 - SizeD) - trans);
									glutSolidCube(SizeD);
									glTranslatef(0, 0, .5 * (1 - SizeD) + trans);
								}
							}
							//glutSolidSphere(1, 10, 10);

							//glutWireCube(1.01);
							//glutWireSphere(1.01, 10, 10);
							glTranslatef(y, x, z);
						}
					}
				}
			}
		}
	} else if (gamestate == 0) {
		glTranslatef(-28, 26, -100);
		glColor3f(1, 1, 1);
		if (ChosenMenuItem == 1) {
			glColor3f(0, 1, 0);
		}
		char Save1[] = "SAVE I";
		drawString(Save1, 6);
		glTranslatef(0, -15, 0);
		glColor3f(1, 1, 1);
		if (ChosenMenuItem == 2) {
			glColor3f(0, 1, 0);
		}
		char Save2[] = "SAVE II";
		drawString(Save2, 7);
		glTranslatef(0, -15, 0);
		glColor3f(1, 1, 1);
		if (ChosenMenuItem == 3) {
			glColor3f(0, 1, 0);
		}
		char Save3[] = "SAVE III";
		drawString(Save3, 8);
		glTranslatef(0, -15, 0);
		glColor3f(1, 1, 1);
		if (ChosenMenuItem == 4) {
			glColor3f(0, 1, 0);
		}
		char Leave[] = "LEAVE";
		drawString(Leave, 5);
		glTranslatef(28, 19, 100);
	} else if (gamestate == 2) {
		glTranslatef(-28, 26, -100);
		glColor3f(1, 1, 1);
		if (ChosenMenuItem == 1) {
			glColor3f(0, 1, 0);
		}
		char Type1[] = "TYPE I";
		drawString(Type1, 6);
		glTranslatef(0, -15, 0);
		glColor3f(1, 1, 1);
		if (ChosenMenuItem == 2) {
			glColor3f(0, 1, 0);
		}
		char Type2[] = "TYPE II";
		drawString(Type2, 7);
		glTranslatef(0, -15, 0);
		glColor3f(1, 1, 1);
		if (ChosenMenuItem == 3) {
			glColor3f(0, 1, 0);
		}
		char Type3[] = "TYPE III";
		drawString(Type3, 8);
		glTranslatef(0, -15, 0);
		glColor3f(1, 1, 1);
		if (ChosenMenuItem == 4) {
			glColor3f(0, 1, 0);
		}
		char Leave[] = "LEAVE";
		drawString(Leave, 5);
		glTranslatef(28, 19, 100);
	} else if (gamestate == 3) {
		glTranslatef(-56, 26, -100);
		glColor3f(1, 1, 1);
		if (ChosenMenuItem == 1) {
			glColor3f(0, 1, 0);
		}
		char SAL[] = "SAVE AND LEAVE";
		drawString(SAL, 14);
		glTranslatef(0, -15, 0);
		glColor3f(1, 1, 1);
		if (ChosenMenuItem == 2) {
			glColor3f(0, 1, 0);
		}
		char SAM[] = "SAVE AND MENV";
		drawString(SAM, 13);
		glTranslatef(0, -15, 0);
		glColor3f(1, 1, 1);
		if (ChosenMenuItem == 3) {
			glColor3f(0, 1, 0);
		}
		char S[] = "SAVE";
		drawString(S, 4);
		glTranslatef(0, -15, 0);
		glColor3f(1, 1, 1);
		if (ChosenMenuItem == 4) {
			glColor3f(0, 1, 0);
		}
		char Leave[] = "LEAVE";
		drawString(Leave, 5);
		glTranslatef(56, 19, 100);
	} else if (gamestate == 4) {
		glTranslatef(Gamestate4Text.length() * -4.0, 3.5, -100);
		glColor3f(1, 1, 1);
		drawRealString(Gamestate4Text, Gamestate4Text.length());
		glTranslatef(Gamestate4Text.length() * 4.0, -3.5, 100);
	}

	glutSwapBuffers();
}

void reshape(int W, int H){
	// Prevent a divide by zero, when window is too short
	// (you can't make a window of zero width).
	if (H == 0)
		H = 1;
	float ratio = (float)W / H;
	ScreenHeight = H;
	ScreenWidth = W;
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
	// Reset Matrix
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, W, H);
	// Set the correct perspective.
	gluPerspective(45, ratio, 0.009, 500);
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
	display();
}