#include "fileManagement.h"

/*

AND JBCODING SAID: "LET THERE BE LETTERS"

*/

void drawChar(char letter) {
	if (letter == 65) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(4,-1);
			glVertex2f(4, -7);
			glVertex2f(5,-7);
			glVertex2f(5,-1);
			glVertex2f(4,-1);
			glVertex2f(1,-1);
			glVertex2f(1,0);
			glVertex2f(4,0);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1, -3);
			glVertex2f(4, -3);
			glVertex2f(4, -4);
			glVertex2f(1, -4);
			glVertex2f(1, -7);
			glVertex2f(0, -7);
			glVertex2f(0, -1);
			glVertex2f(1, -1);
		glEnd();
	} else if (letter == 68) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(0,0);
			glVertex2f(4,0);
			glVertex2f(4,-1);
			glVertex2f(1,-1);
			glVertex2f(1,-6);
			glVertex2f(0,-6);
			glVertex2f(0,0);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(4,-6);
			glVertex2f(4,-1);
			glVertex2f(5,-1);
			glVertex2f(5,-6);
			glVertex2f(4,-6);
			glVertex2f(4,-7);
			glVertex2f(0,-7);
			glVertex2f(0,-6);
		glEnd();
	} else if (letter == 69) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(0,0);
			glVertex2f(5,0);
			glVertex2f(5,-1);
			glVertex2f(0,-1);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1,-2);
			glVertex2f(3,-2);
			glVertex2f(3,-3);
			glVertex2f(1,-3);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(0,-7);
			glVertex2f(0,-1);
			glVertex2f(1,-1);
			glVertex2f(1,-6); 
			glVertex2f(5,-6);
			glVertex2f(5,-7);
		glEnd();

	} else if (letter == 71) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1,-1);
			glVertex2f(5,-1);
			glVertex2f(5,0);
			glVertex2f(1,0);
			glVertex2f(1,-1);
			glVertex2f(0,-1);
			glVertex2f(0,-6);
			glVertex2f(1,-6);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(5,-2);
			glVertex2f(2,-2);
			glVertex2f(2,-3);
			glVertex2f(4,-3);
			glVertex2f(4,-6);
			glVertex2f(5,-6);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1,-6);
			glVertex2f(1,-7);
			glVertex2f(4,-7);
			glVertex2f(4,-6);
		glEnd();
	} else if (letter == 73) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(2, -1);
			glVertex2f(1, -1);
			glVertex2f(1, 0);
			glVertex2f(4, 0);
			glVertex2f(4, -1);
			glVertex2f(3, -1);
			glVertex2f(3, -6);
			glVertex2f(2, -6);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1, -6);
			glVertex2f(1, -7);
			glVertex2f(4, -7);
			glVertex2f(4, -6);
		glEnd();
	}
	else if (letter == 76) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(0, -7);
			glVertex2f(0, 0);
			glVertex2f(1, 0);
			glVertex2f(1, -6);
			glVertex2f(5, -6);
			glVertex2f(5, -7);
		glEnd();
	} else if (letter == 77) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1, -1);
			glVertex2f(2, -1);
			glVertex2f(2, -2);
			glVertex2f(1, -2);
			glVertex2f(1, -7);
			glVertex2f(0, -7);
			glVertex2f(0, 0);
			glVertex2f(1, 0);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(4, -1);
			glVertex2f(3, -1);
			glVertex2f(3, -2);
			glVertex2f(4, -2);
			glVertex2f(4, -7);
			glVertex2f(5, -7);
			glVertex2f(5, 0);
			glVertex2f(4, 0);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(2, -2);
			glVertex2f(2, -3);
			glVertex2f(3, -3);
			glVertex2f(3, -2);
		glEnd();
	} else if (letter == 78) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1, -1);
			glVertex2f(2, -1);
			glVertex2f(2, -2);
			glVertex2f(1, -2);
			glVertex2f(1, -7);
			glVertex2f(0, -7);
			glVertex2f(0, 0);
			glVertex2f(1, 0);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(4, -3);
			glVertex2f(3, -3);
			glVertex2f(3, -4);
			glVertex2f(4, -4);
			glVertex2f(4, -7);
			glVertex2f(5, -7);
			glVertex2f(5, 0);
			glVertex2f(4, 0);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(2, -2);
			glVertex2f(2, -3);
			glVertex2f(3, -3);
			glVertex2f(3, -2);
		glEnd();
	} else if (letter == 79) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1, -1);
			glVertex2f(4, -1);
			glVertex2f(4, 0);
			glVertex2f(1, 0);
			glVertex2f(1, -1);
			glVertex2f(1, -6);
			glVertex2f(0, -6);
			glVertex2f(0, -1);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(4, -6);
			glVertex2f(4, -1);
			glVertex2f(5, -1);
			glVertex2f(5, -6);
			glVertex2f(4, -6);
			glVertex2f(1, -6);
			glVertex2f(1, -7);
			glVertex2f(4, -7);
		glEnd();
	} else if (letter == 80) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(4, -2);
			glVertex2f(1, -2);
			glVertex2f(1, -3);
			glVertex2f(4, -3);
			glVertex2f(4, -2);
			glVertex2f(4, -1);
			glVertex2f(5, -1);
			glVertex2f(5, -2);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(0, 0);
			glVertex2f(4, 0);
			glVertex2f(4, -1);
			glVertex2f(1, -1);
			glVertex2f(1, -7);
			glVertex2f(0, -7);
		glEnd();
	} else if (letter == 82) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(4, -2);
			glVertex2f(1, -2);
			glVertex2f(1, -3);
			glVertex2f(4, -3);
			glVertex2f(4, -2);
			glVertex2f(4, -1);
			glVertex2f(5, -1);
			glVertex2f(5, -2);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(0, 0);
			glVertex2f(4, 0);
			glVertex2f(4, -1);
			glVertex2f(1, -1);
			glVertex2f(1, -7);
			glVertex2f(0, -7);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(4, -3);
			glVertex2f(4, -7);
			glVertex2f(5, -7);
			glVertex2f(5, -3);
		glEnd();
	} else if (letter == 83) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1, -1);
			glVertex2f(5, -1);
			glVertex2f(5, 0);
			glVertex2f(1, 0);
			glVertex2f(1, -1);
			glVertex2f(0, -1);
			glVertex2f(0, -2);
			glVertex2f(1, -2);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(4, -3);
			glVertex2f(1, -3);
			glVertex2f(1, -2);
			glVertex2f(4, -2);
			glVertex2f(4, -3);
			glVertex2f(5, -3);
			glVertex2f(5, -6);
			glVertex2f(4, -6);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1, -6);
			glVertex2f(1, -5);
			glVertex2f(0, -5);
			glVertex2f(0, -6);
			glVertex2f(1, -6);
			glVertex2f(1, -7);
			glVertex2f(4, -7);
			glVertex2f(4, -6);
		glEnd();
	} else if (letter == 84) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(2, -1);
			glVertex2f(0, -1);
			glVertex2f(0, 0);
			glVertex2f(5, 0);
			glVertex2f(5, -1);
			glVertex2f(3, -1);
			glVertex2f(3, -7);
			glVertex2f(2, -7);
		glEnd();
	} else if (letter == 85) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1, -6);
			glVertex2f(0, -6);
			glVertex2f(0, 0);
			glVertex2f(1, 0);
			glVertex2f(1, -6);
			glVertex2f(1, -7);
			glVertex2f(4, -7);
			glVertex2f(4, -6);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(4, 0);
			glVertex2f(5, 0);
			glVertex2f(5, -6);
			glVertex2f(4, -6);
		glEnd();
	} else if (letter == 86) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1, -4);
			glVertex2f(0, -4);
			glVertex2f(0, 0);
			glVertex2f(1, 0);
			glVertex2f(1, -4);
			glVertex2f(1, -6);
			glVertex2f(2, -6);
			glVertex2f(2, -4);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(4, -4);
			glVertex2f(4, 0);
			glVertex2f(5, 0);
			glVertex2f(5, -4);
			glVertex2f(4, -4);
			glVertex2f(4, -6);
			glVertex2f(3, -6);
			glVertex2f(3, -4);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(2, -6);
			glVertex2f(2, -7);
			glVertex2f(3, -7);
			glVertex2f(3, -6);
		glEnd();
	} else if (letter == 89) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(1, -1);
			glVertex2f(0, -1);
			glVertex2f(0, 0);
			glVertex2f(1, 0);
			glVertex2f(1, -1);
			glVertex2f(2, -1);
			glVertex2f(2, -2);
			glVertex2f(1, -2);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(4, -1);
			glVertex2f(4, 0);
			glVertex2f(5, 0);
			glVertex2f(5, -1);
			glVertex2f(4, -1);
			glVertex2f(4, -2);
			glVertex2f(3, -2);
			glVertex2f(3, -1);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(2, -2);
			glVertex2f(3, -2);
			glVertex2f(3, -7);
			glVertex2f(2, -7);
		glEnd();
	}
} 