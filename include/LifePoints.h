#ifndef LIFE_POINTS_H
#define LIFE_POINTS_H
#include "StaticSprite.h"

class LifePoints : public StaticSprite {
    public:
        LifePoints() {}
        LifePoints(int _x, int _y, int _width, int _height);
        
        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();
     
};

#endif