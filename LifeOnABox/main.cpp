#include "render.h"

clock_t LastGameTick = clock();
int FramesCount = 0;
void gametimer() {
	double Diff = clock() - LastGameTick;
	Diff = Diff / CLOCKS_PER_SEC;
	if (Diff > 1 / FramesPerSecond) {
		LastGameTick = clock();
		if (gamestate == 1) {
			physicTick((float)Diff);
			LookingAt();
		}
		updatePlayerMotion();
		display();
		FramesCount++;
	}
	else {
		std::this_thread::sleep_for(std::chrono::milliseconds(1 / (long long)FramesPerSecond - (long long)Diff));
	}
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1280, 768);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("Life On A Box");

	glutSetCursor(GLUT_CURSOR_NONE);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMotionFunc(mouseMotion);
	glutPassiveMotionFunc(mouseMotion);
	glutIdleFunc(gametimer); 
	glutKeyboardFunc(keyBoardCallBackDown);
	glutKeyboardUpFunc(keyBoardCallBackUp);
	glutMouseFunc(mouseClick);
	//glutFullScreen();

	ProgramInit();

	glutMainLoop();
}