#include "render.h"

clock_t LastGameTick = clock();
int FramesCount = 0;
bool check = false;

void gametimer() {
	double Diff = clock() - LastGameTick;
	Diff = Diff / CLOCKS_PER_SEC;
	LastDiff = Diff;
	if (LastDiff > 0.05 && check && gamestate && RenderDistance > 5) {
		RenderDistance--;
		check = false;
	}
	else if (LastDiff < 0.01 && check && gamestate) {
		RenderDistance++;
		check = false;
	}
	if (Diff > 1 / FramesPerSecond) {
		check = true;
		LastGameTick = clock();
		if (gamestate == 1) {
			physicTick((float)Diff);
			LookingAt();
			updatePlayerMotion();
		} else {
			MenuControls();
		}
		display();
		FramesCount++;

		/*short Rotation = 0;
		short Side1, Side2, Side3, Side4;
		Side1 = World32[WorldBounds / 2 - 1][WorldBounds / 2][WorldBounds / 2].SpecialNumber + World32[WorldBounds / 2 - 1][WorldBounds / 2][WorldBounds / 2 - 1].SpecialNumber;
		Side2 = World32[WorldBounds / 2 - 1][WorldBounds / 2 - 1][WorldBounds / 2].SpecialNumber + World32[WorldBounds / 2 - 1][WorldBounds / 2][WorldBounds / 2 - 1].SpecialNumber;
		Side3 = World32[WorldBounds / 2 - 1][WorldBounds / 2 - 1][WorldBounds / 2].SpecialNumber + World32[WorldBounds / 2 - 1][WorldBounds / 2][WorldBounds / 2].SpecialNumber;
		Side4 = World32[WorldBounds / 2 - 1][WorldBounds / 2][WorldBounds / 2].SpecialNumber + World32[WorldBounds / 2 - 1][WorldBounds / 2][WorldBounds / 2].SpecialNumber;
		if (Side1 > Side2 && Side1 > Side3 && Side1 > Side4) {
		Rotation = 0;
		} else if (Side2 > Side1 && Side2 > Side3 && Side2 > Side4) {
		Rotation = 1;
		} else if (Side3 > Side1 && Side3 > Side2 && Side3 > Side4) {
		Rotation = 2;
		} else if(Side4 > Side1 && Side4 > Side3 && Side4 > Side2) {
		Rotation = 3;
		}
		int PlaneID = World32[WorldBounds / 2 - 1][WorldBounds / 2][WorldBounds / 2].SpecialNumber * World32[WorldBounds / 2 - 1][WorldBounds / 2][WorldBounds / 2].SpecialNumber +
		World32[WorldBounds / 2 - 1][WorldBounds / 2][WorldBounds / 2 - 1].SpecialNumber * World32[WorldBounds / 2 - 1][WorldBounds / 2][WorldBounds / 2 - 1].SpecialNumber +
		World32[WorldBounds / 2 - 1][WorldBounds / 2 - 1][WorldBounds / 2].SpecialNumber * World32[WorldBounds / 2 - 1][WorldBounds / 2 - 1][WorldBounds / 2].SpecialNumber +
		World32[WorldBounds / 2 - 1][WorldBounds / 2 - 1][WorldBounds / 2 - 1].SpecialNumber * World32[WorldBounds / 2 - 1][WorldBounds / 2 - 1][WorldBounds / 2 - 1].SpecialNumber;
		std::cout << PlaneID << " - " << Rotation << "\n";*/
	}
	else {
		std::this_thread::sleep_for(std::chrono::milliseconds(1 / (long long)FramesPerSecond - (long long)Diff/2));
	}
}

void ResetTime() {
	LastGameTick = clock();
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

	glutMainLoop();
}