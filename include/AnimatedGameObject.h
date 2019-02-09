#ifndef ANIMATED_GAME_OBJECT_H
#define ANIMATED_GAME_OBJECT_H
#include "GameObject.h"

class AnimatedGameObject : public GameObject{

    public:
        AnimatedGameObject() {}
        AnimatedGameObject(int _x, int _y): GameObject(_x, _y){}
        virtual void drawOnScreen();

    private:

};

#endif