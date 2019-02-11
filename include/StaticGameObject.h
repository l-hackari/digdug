#ifndef STATIC_GAME_OBJECT_H
#define STATIC_GAME_OBJECT_H
#include "GameObject.h"

class StaticGameObject : public GameObject{

    public:
        StaticGameObject() {}
        StaticGameObject(int _x, int _y, const char *_bpath): GameObject(_x, _y), bitmap(al_load_bitmap(_bpath)){}
        virtual void drawOnScreen();
        ALLEGRO_BITMAP * getBitMap(){return bitmap;}

    private:
         ALLEGRO_BITMAP *bitmap;
};

#endif