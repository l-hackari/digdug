#include "AnimatedSprite.h"
class Dragon : public AnimatedSprite{
    
    public:
        Dragon(){}
        Dragon(int _id, int _x, int _y, int _width, int _height);
        virtual void drawOnScreen();


};