#include "AnimatedSprite.h"
class Monkey : public AnimatedSprite{
    
    public:
        Monkey(){}
        Monkey(int _id, int _x, int _y, int _width, int _height);
        virtual void drawOnScreen();
        void drawMonkey();
    private:


};