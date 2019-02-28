#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "GameTools.h"
class GameObject {

    public:
        GameObject(): x(0), y(0){}
        GameObject(int _id, int _x, int _y): id(_id), x(_x), y(_y){}
        
        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen() = 0;

        //ritorna la coordinata x dell'oggetto di gioco
        //returns the game object's x coordinate
        int getX(){ return x; }

        //ritorna la coordinata y dell'oggetto di gioco
        //returns the game object's y coordinate
        int getY(){ return y; }

    protected:
        float x, y;
        int id;
       

};

#endif