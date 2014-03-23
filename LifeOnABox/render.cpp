#include "render.h"

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(1, 1, 1);
	glVertex3f(-1, 1, 0);
	glVertex3f(-1, -1, -1);
	glEnd();

	glutSwapBuffers();
}