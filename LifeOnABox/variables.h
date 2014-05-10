#include "structs.h"
using namespace JBnamespace;

#define BLOCK_AIR 0
#define BLOCK_BED_ROCK 1
#define BLOCK_STONE 2
#define BLOCK_DIRT 3
#define BLOCK_WOOD 4
#define BLOCK_LEAVES 5
#define BLOCK_GRASS 6
#define BLOCK_SAND 7
#define BLOCK_DARKSTONE 8
#define BLOCK_LIGHT_WOOD 9
#define BLOCK_YELLOW_GRASS 10

#define HVIS if

short WorldBounds = 32;
Blocks World32[256][256][256];
short  MiniMapView[128][128];
vector3D HeadRotation = vector3D(-45, 0, 0); // Left Right // Up down // Unused
vector3D Position = vector3D(-WorldBounds / 4, -WorldBounds / 4, -WorldBounds / 4);
//vector3D Position = vector3D(-10,-10,-128);
//vector3D Position = vector3D(WorldBounds / 2, -WorldBounds / 2, WorldBounds / 4);
float CameraSensitivity = 40;

int ScreenWidth;
int ScreenHeight;

float FramesPerSecond = 30;

bool KEYS[256];
float Speed = 0.2;

float PI = 3.14159265359;
float DECTORAD = PI / 180;

float RenderDistance = 20;


bool RotationCube = false;
float TAngle = 0;
float TSpeed = 10;

//Physics
float g = 11.22285713; // gets multiplyed by 0.875 before added
bool fallDamageActivated = false;
bool healthbarActivated = false;
float playerHeight = 1.8;
float playerRadius = 0.25;
particle bodyParticles[12];

bool IsPlayerOnGround = false;

int RotateCoolDown = 0;

//Gameplay Variables
float reach = 8;
vector3D BlockLookingAt;
vector3D BlockPlacePos;
short chosenBlock = BLOCK_STONE;


//MENU CRAP
short gamestate = 0; //1 = Playing bitch! 0 - 3 % 1 = Menu crap

std::string Gamestate4Text = "LOADING";



//World saving stuff
unsigned int seed;
short worldNumber = 1;
int PlayerID;


short ChosenMenuItem = 1;
bool IsSpaceHoldIn = false;

