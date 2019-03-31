#include "../include/GameTools.h"

int actualPressedKey = ALLEGRO_KEY_SPACE;
bool died = false;
int nativeScreenWidth = 224;
int nativeScreenHeight = 288;
int score = 0;
int collisionMap[18 * 4][14 * 4];
int groundMap[18 * 4][14 * 4];
int lifePoints = 3;
ALLEGRO_TIMER *swallowTimer;
bool isSwallowTimerActive = false;
int swallowValue = 0;
int playerX;
int playerY;
 