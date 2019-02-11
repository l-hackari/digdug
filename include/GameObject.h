#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
class GameObject {

    public:
        GameObject(): x(0), y(0){}
        GameObject(int _x, int _y): x(_x), y(_y){}
        virtual void drawOnScreen() = 0;
        int getX(){ return x; }
        int getY(){ return y; }

    protected:
        int x, y;
       

};

#endif