#ifndef POWERUPS_H
#define POWERUPS_H
#include "AnimatedSprite.h"

class Powerups : public AnimatedSprite {
        
    public:
        Powerups(){}
        Powerups(int _x, int _y, int _width, int _height);

        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();


    private:
        ALLEGRO_BITMAP *PowerUpsBitMap;
        int scoreBonusLimit = 0;
        int timerBonus = 0;
        int rallenty = 0;


};

#endif