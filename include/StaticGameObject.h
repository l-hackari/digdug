#ifndef ANIMATED_GAME_OBJECT_H
#define ANIMATED_GAME_OBJECT_H
#include "GameObject.h"

class StaticGameObject : public GameObject{

    public:
        StaticGameObject() {}
        StaticGameObject(int _x, int _y): GameObject(_x, _y){}
        virtual void drawOnScreen();

    private:

};

#endif