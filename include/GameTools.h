#ifndef GAME_TOOLS_H
#define GAME_TOOLS_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>
#include <ctime>
#include <vector>
#include <climits>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

enum direction {NONE = 0, LEFT, RIGHT, UP, DOWN};
extern bool died;
extern int nativeScreenWidth;
extern int nativeScreenHeight;
extern int actualPressedKey;
extern int score;
extern int collisionMap[18*4][14*4];
extern int groundMap[18*4][14*4];
extern int lifePoints;
extern ALLEGRO_TIMER *swallowTimer;
extern bool isSwallowTimerActive;
extern int swallowValue;
extern int playerX;
extern int playerY;
extern int enemiesCounter;

#endif