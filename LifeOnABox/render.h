#include "controls.h"

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(HeadRotation.y, 1, 0, 0);
	glRotatef(HeadRotation.x, 0, 1, 0);

	RotateCoolDown--;
	if (RotateCoolDown < 0) {
		RotateCoolDown = -1;
	}

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

	if (RotationCube) {
		glTranslatef(WorldBounds / 2, WorldBounds / 2, WorldBounds / 2);
		glRotatef(TAngle, 1, 1, 1);
		TAngle += TSpeed;
	}

	for (int x = XD; x < XO; x++) {
		for (int y = YD; y < YO; y++) {
			for (int z = ZD; z < ZO; z++) {
				if (World32[x][y][z].Type != BLOCK_AIR && World32[x][y][z].AirBesids) {
					vector3D Distance = vector3D(x + Position.x, y + Position.y, z + Position.z);
					if (Distance.squareMagnitude() <= RenderDistance * RenderDistance) {
						glTranslatef(-y, -x, -z);
						if (World32[x][y][z].Type == BLOCK_GRASS) {
							glColor3f(0, 1, 0);
						} else if(World32[x][y][z].Type == BLOCK_WOOD) {
							glColor3f(0.55, 0.27, 0.08);
						} else if (World32[x][y][z].Type == BLOCK_LEAVES) {
							glColor3f(0.4, .8, 0.4);
						} else if (World32[x][y][z].Type == BLOCK_BED_ROCK) {
							glColor3f(0.1, 0.1, 0.1);
						} else if (World32[x][y][z].Type == BLOCK_DIRT) {
							glColor3f(0.44, 0.37, 0.15);
						} else if (World32[x][y][z].Type == BLOCK_STONE) {
							glColor3f(0.5, 0.5, 0.5);
						} else if (World32[x][y][z].Type == BLOCK_SAND) {
							glColor3f(0.93, 0.79, 0.38);
						} else if (World32[x][y][z].Type == BLOCK_DARKSTONE) {
							glColor3f(0.3, 0.3, 0.3);
						} else if (World32[x][y][z].Type == BLOCK_LIGHT_WOOD) {
							glColor3f(0.75, 0.47, 0.28);
						} else if (World32[x][y][z].Type == BLOCK_YELLOW_GRASS) {
							glColor3f(0.7, 1, 0);
						}
						glutSolidCube(1);
						//glutSolidSphere(1, 10, 10);
						glColor3f(1, 1, 1);
						glutWireCube(1.01);
						//glutWireSphere(1.01, 10, 10);
						glTranslatef(y, x, z);
					}
				}
			}
		}
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
	gluPerspective(45, ratio, 0.01, 500);
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
	display();
}