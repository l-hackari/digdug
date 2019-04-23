#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "GameTools.h"
class GameObject {

    public:
        GameObject(): x(0), y(0){}
        GameObject(int _id, int _x, int _y): id(_id), x(_x), y(_y), isVisible(true), initial_x(_x), initial_y(_y){}
        
        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen() = 0;

        //ritorna la coordinata x dell'oggetto di gioco
        //returns the game object's x coordinate
        float getX(){ return x; }

        //ritorna la coordinata y dell'oggetto di gioco
        //returns the game object's y coordinate
        float getY(){ return y; }

        //setta il valore della coordinata x dell'oggetto di gioco
        //sets the value of the x coordinate of the game object
        void setX(float _x){ x = _x; }

        //setta il valore della coordinata y dell'oggetto di gioco
        //sets the value of the y coordinate of the game object
        void setY(float _y){ y = _y; }

        //ritorna lo stato di visibilità dell'oggetto di gioco
        //returns the game object's visibility state
        bool getVisible(){ return isVisible; }

        //setta a true lo stato di visibilità dell'oggetto di gioco
        //sets at true game object's visibility state
        void setVisible(){ isVisible = true; }

        //ripristina la posizione iniziale dell'oggetto di gioco
        //restores the initial position of game object
        void restoreCoordinates(){ x = initial_x; y = initial_y; alternativeMode = false; }
    protected:
        float x, y, initial_x, initial_y;
        int id;
        bool isVisible;
        bool alternativeMode;
};

#endif