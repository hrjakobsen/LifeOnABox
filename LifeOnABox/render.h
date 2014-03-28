#include "controls.h"

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(HeadRotation.y, 1, 0, 0);
	glRotatef(HeadRotation.x, 0, 1, 0);

	glTranslatef(-Position.y, -Position.x, -Position.z);

	for (int x = 0; x < 32; x++) {
		for (int y = 0; y < 32; y++) {
			for (int z = 0; z < 32; z++) {
				if (World32[x][y][z] != 0) {
					glTranslatef(-y, -x, -z);
					glutWireCube(1);
					glTranslatef(y, x, z);
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