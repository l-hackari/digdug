#ifndef STONE_H
#define STONE_H
#include "AnimatedSprite.h"

class Stone : public AnimatedSprite{

    public:
        Stone(){}
        Stone(int _x, int _y, int _width, int _height);

        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();

        bool isFallen();

        void drawStoneBreak();
        
        void drawAlternative();

        bool isCrushed();

        void initStone();

    private:
        ALLEGRO_BITMAP * stoneBitMap;
        bool isBroken = false;
        int rallenty = 0;
        bool drawedAlternative = false;
        bool drawedDying = false;
        bool landed = false;
        bool brake = false;
        int count = 0;
        bool ok = false;



};

#endif