#ifndef ANIMATED_GAME_OBJECT_H
#define ANIMATED_GAME_OBJECT_H
#include "GameObject.h"

class AnimatedGameObject : public GameObject{

    public:
        AnimatedGameObject() {}
        AnimatedGameObject(int _id, int _x, int _y, int _width, int _height, ALLEGRO_BITMAP *fl, vector<ALLEGRO_BITMAP*> ms, vector<ALLEGRO_BITMAP*> as, vector<ALLEGRO_BITMAP*> als,vector<ALLEGRO_BITMAP*> ds);
        
        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();

    protected:
        vector<ALLEGRO_BITMAP*> movementSprites;
        vector<ALLEGRO_BITMAP*> attackSprites;
        vector<ALLEGRO_BITMAP*> alternativeSprites;
        vector<ALLEGRO_BITMAP*> deathSprites;
        ALLEGRO_BITMAP *flatten;
        int animationLimit;
        int previousAnimation;
        direction previousDirection;
        int actualFrame;
};

#endif