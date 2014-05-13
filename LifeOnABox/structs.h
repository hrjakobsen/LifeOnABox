#include <Windows.h>
#include <GL\glut.h>
#include <thread>
#include <time.h>
#include <chrono>
#include "namespaceDec.h"
#include <string>
#include <fstream>

#include <iostream>
#include <vector>

#define BIB A
#define BOB B
#define LESS -
#define MORE +
#define SAME =
#define STAHP ;

struct Blocks
{
	short Type;
	bool AirBesids;
};