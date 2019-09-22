#include "../include/GameTools.h"

const int FPS = 8;
int actualPressedKey = ALLEGRO_KEY_SPACE;
bool died = false;
const int nativeScreenWidth = 224;
const int nativeScreenHeight = 288;
const int collisionCellDivider = 4;

/*

Ha lo scopo di dividere ogni cella della matrice di collisione in 16 parti 
per aumentare la precisione 
 __________  _____________
 |         | |__|__|__|__|
 | cella   | |__|__|__|__|   <---- Cella divisa in 16 parti per aumentare la precisione
 |         | |__|__|__|__|   
 |_________| |__|__|__|__|
 
 */


const int spriteHeight = 16;
const int spriteWidth = 16;
const int originalCollisionMapHeight = nativeScreenHeight / spriteHeight;
const int originalCollisionMapWidth = nativeScreenWidth / spriteWidth;
int score = 0;
int collisionMap[originalCollisionMapHeight * collisionCellDivider][originalCollisionMapWidth * collisionCellDivider];
int groundMap[originalCollisionMapHeight * collisionCellDivider][originalCollisionMapWidth * collisionCellDivider];
int lifePoints = 3;
ALLEGRO_TIMER *swallowTimer;
ALLEGRO_TIMER *bonusTimer;
vector<ALLEGRO_SAMPLE*> audios;
ALLEGRO_SAMPLE_ID ret;
bool isBackgroundAudioOn = true;
bool isSwallowTimerActive = false;
int swallowValue = 0;
int playerX;
int playerY;
int enemiesCounter;
bool isEnemySwallowing = false;
int killedEnemy = 0;
const int dragonAttackPreparingCounter = 8;
const int distanceToAttack = 48;
const int groundIndexStart = 6;
const int groundIndexEnd = 68;
const float radiantFor270Degrees = 4.71239;
const float radiantFor90Degrees = 1.5708;
const int initialDiggedGroundIndex = 10;
const int groundSpiteSize = 4;