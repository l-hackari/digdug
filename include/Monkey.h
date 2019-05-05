#ifndef MONKEY_H
#define MONKEY_H
#include "Enemy.h"

class Monkey : public Enemy{
    
    public:
        Monkey(){}
        Monkey(int _x, int _y, int _width, int _height);

        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();

    private:
        //disegna l'animazione di attacco dell'oggetto di gioco
        //draws game object's attack animation
        virtual void drawAttack();


};

#endif