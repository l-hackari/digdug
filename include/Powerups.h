#include "AnimatedSprite.h"

class Powerups : public AnimatedSprite {
        
    public:
    Powerups(){}
    Powerups(int _id, int _x, int _y, int _width, int _height);
    virtual void drawOnScreen();


    private:
        ALLEGRO_BITMAP * PowerUpsBitMap;
        int scoreBonusLimit = 0;
        int timerBonus = 0;
        int rallenty = 0;


};