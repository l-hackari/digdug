#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"

class Dragon : public Enemy{
    
    public:
        Dragon(){}
        Dragon(int _x, int _y, int _width, int _height);
        
        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();
        
    private:
        //disegna l'animazione idle di attacco dell'oggetto di gioco
        //draws game object's attack idle animation
        void drawAttackIdle();

        //disegna l'animazione di attacco dell'oggetto di gioco
        //draws game object's attack animation
        void drawAttack();

        //cancella le celle occupate dalle fiamme nella collisionMap
        //erases collisionMap's cells occupied by flames
        void clearFlameCollisionMap();

        //riempie la collisionMap in base alla posizione delle fiamme
        //fills collisionMap depending on flames' position
        bool fillFlameCollisionMap();


    protected:
        ALLEGRO_BITMAP *alternativeFlatten;
        vector<ALLEGRO_BITMAP*> flames;
        bool needToFreeFlameMap = false;
        int attackCounter = 0;
        int flameCounter = 1;
        int flameHeight = 16;
        int flameWidth = 16;
        int flameX;
        int flameY;


};

#endif