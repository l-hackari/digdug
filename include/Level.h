#ifndef LEVEL_H
#define LEVEL_H
#include "GameTools.h"
#include "Player.h"
#include "Monkey.h"
#include "Dragon.h"
#include "Stone.h"
#include "Powerups.h"

class Level
{
    private:
        vector<GameObject *> gameObjs;
        int dragonsNumber;
        int monkeysNumber;
        int stonesNumber;

        //funzione che genera in modo randomico la posizione dei nemici
        //function that generates randomly enemies' position
        void setEnemiesPosition(object enemyToPosition);

        //funzione che genera in modo randomico la posizione del player
        //function that generates randomly player's position
        void setPlayerPosition();

        //funzione che genera in modo randomico la posizione delle pietre
        //function that generates randomly stones' position
        void setStonesPosition();
    public:
        Level(const int &difficulty);
        int getEnemiesNumber();
        vector<GameObject *> getGameObjects();
};

#endif