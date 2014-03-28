#include "structs.h"
using namespace JBnamespace;

int World32[32][32][32];
vector3D HeadRotation = vector3D(0, 0, 0); // Left Right // Up down // Unused
vector3D Position = vector3D(0, 0, 0);
float CameraSensitivity = 40;

int ScreenWidth;
int ScreenHeight;

float FramesPerSecond = 30;

bool KEYS[256];
float Speed = 0.2;

float PI = 3.14159265359;
float DECTORAD = PI / 180;