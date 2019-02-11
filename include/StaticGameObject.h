#ifndef STATIC_GAME_OBJECT_H
#define STATIC_GAME_OBJECT_H
#include "GameObject.h"

class StaticGameObject : public GameObject{

    public:
        StaticGameObject() {}
        StaticGameObject(int _x, int _y,ALLEGRO_BITMAP *bit_map): GameObject(_x, _y){
            bitmap = bit_map;
        }
        virtual void drawOnScreen();
        ALLEGRO_BITMAP * getBitMap(){return bitmap;}

    private:
         ALLEGRO_BITMAP *bitmap;
};

#endif