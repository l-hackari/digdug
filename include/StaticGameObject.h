#ifndef STATIC_GAME_OBJECT_H
#define STATIC_GAME_OBJECT_H
#include "GameObject.h"

class StaticGameObject : public GameObject{

    public:
        StaticGameObject() {}
        StaticGameObject(int _id, int _x, int _y, int _width, int _height, const char *_bpath): GameObject(_id, _x, _y, _width, _height), bitmap(al_load_bitmap(_bpath)){}
        
        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();

    private:
         ALLEGRO_BITMAP *bitmap;
};

#endif