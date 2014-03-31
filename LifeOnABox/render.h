#include "controls.h"

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(HeadRotation.y, 1, 0, 0);
	glRotatef(HeadRotation.x, 0, 1, 0);

	glTranslatef(-Position.y, -Position.x, -Position.z);

	for (int x = 1; x < 31; x++) {
		for (int y = 1; y < 31; y++) {
			for (int z = 1; z < 31; z++) {
				if (World32[x][y][z].Type != 0) {
					vector3D Distance = vector3D(x + Position.x, y + Position.y, z + Position.z);
					if (Distance.squareMagnitude() <= RenderDistance * RenderDistance) {
						glTranslatef(-y, -x, -z);
						if (World32[x][y][z].Type == 1 && World32[x][y][z].AirBesids) {
							glColor3f(0, 1, 0);
							glutSolidCube(1);
							glColor3f(1, 1, 1);
							glutWireCube(1.01);
						}
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
	gluPerspective(45, ratio, 0.01, 100);
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
	display();
}