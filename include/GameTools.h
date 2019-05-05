#ifndef GAME_TOOLS_H
#define GAME_TOOLS_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <string>
#include <ctime>
#include <vector>
#include <list>
#include <climits>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

extern const int FPS;
enum direction {NONE = 0, LEFT, RIGHT, UP, DOWN};
enum object {PLAYER = 1, DRAGON, MONKEY, STONE, POWER_UP};
enum audio {BACKGROUND_SOUND = 0, ATTACK = 1, SWALLOW = 2, MONSTER_TOUCHED = 3, DIED = 4, MONSTER_DIED = 5, GAME_OVER = 6, LAST_ENEMY = 7, ROUND_WIN = 8};
extern vector<ALLEGRO_SAMPLE*> audios;
extern bool died;
extern int nativeScreenWidth;
extern int nativeScreenHeight;
extern int actualPressedKey;
extern int score;
extern int scoreBonusLimit;
extern int collisionMap[18*4][14*4];
extern int groundMap[18*4][14*4];
extern int lifePoints;
extern ALLEGRO_SAMPLE_ID ret;
extern bool isBackgroundAudioOn;
extern ALLEGRO_TIMER *swallowTimer;
extern bool isSwallowTimerActive;
extern int swallowValue;
extern int playerX;
extern int playerY;
extern int enemiesCounter;
extern bool stoneIsFalling;
extern bool isEnemySwallowing;


#endif