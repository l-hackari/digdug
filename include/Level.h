#ifndef LEVEL_H
#define LEVEL_H
#include "GameTools.h"
#include "Player.h"
#include "Monkey.h"
#include "Dragon.h"
#include "Stone.h"

class Level
{
    private:
        vector<GameObject *> gameObjs;
        int dragonsNumber;
        int monkeysNumber;
        int stonesNumber;

        void setDragonsPosition();
        void setMonkeysPosition();
        void setPlayerPosition();
        void setStonesPosition();
    public:
        Level(const int &difficulty);
        int getEnemiesNumber();
        vector<GameObject *> getGameObjects();
};

#endif