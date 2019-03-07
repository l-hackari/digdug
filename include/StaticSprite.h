#ifndef STATIC_SPRITE_H
#define STATIC_SPRITE_H
#include "GameObject.h"

class StaticSprite : public GameObject{

    public:
        StaticSprite() {}
        StaticSprite(int _id, int _x, int _y, int _width, int _height, ALLEGRO_BITMAP *_bmap): GameObject(_id, _x, _y), width(_width), height(_height), bitmap(_bmap){}
        
        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();

    protected:
        ALLEGRO_BITMAP *bitmap;
        int width;
        int height;

     
};

#endif