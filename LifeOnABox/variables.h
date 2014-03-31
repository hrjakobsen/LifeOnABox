#include "structs.h"
using namespace JBnamespace;

#define BLOCK_AIR 0
#define BLOCK_STONE 1
#define BLOCK_DIRT 2
#define BLOCK_WOOD 3
#define BLOCK_LEAVES 4
#define BLOCK_GRASS 5

Blocks World32[32][32][32];
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

float RenderDistance = 32;