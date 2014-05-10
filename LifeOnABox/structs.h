#include <Windows.h>
#include <GL\glut.h>
#include <thread>
#include <time.h>
#include <chrono>
#include "namespaceDec.h"
#include <string>
#include <fstream>

struct Blocks
{
	short Type;
	bool AirBesids;
};