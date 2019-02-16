#ifndef GAME_TOOLS_H
#define GAME_TOOLS_H
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <vector>
#include <iostream>
using namespace std;

enum direction {LEFT = 0, RIGHT, UP, DOWN};
extern int actualPressedKey;
extern int gameMap[18*4][14*4];

#endif