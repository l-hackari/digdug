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
extern const int nativeScreenWidth;
extern const int nativeScreenHeight;
extern int actualPressedKey;
extern int score;
extern const int collisionCellDivider;
extern const int spriteHeight;
extern const int spriteWidth;
extern const int originalCollisionMapHeight;
extern const int originalCollisionMapWidth;
extern int collisionMap[18*4][14*4];
extern int groundMap[18*4][14*4];
extern int lifePoints;
extern ALLEGRO_SAMPLE_ID ret;
extern bool isBackgroundAudioOn;
extern ALLEGRO_TIMER *swallowTimer;
extern ALLEGRO_TIMER *bonusTimer;
extern bool isSwallowTimerActive;
extern int swallowValue;
extern int playerX;
extern int playerY;
extern int enemiesCounter;
extern bool stoneIsFalling;
extern bool isEnemySwallowing;
extern int killedEnemy;
extern const int dragonAttackPreparingCounter;
extern const int distanceToAttack;
extern const int groundIndexStart;
extern const int groundIndexEnd;
extern const float radiantFor270Degrees;
extern const float radiantFor90Degrees;
extern const int initialDiggedGroundIndex;
extern const int groundSpiteSize;


#endif