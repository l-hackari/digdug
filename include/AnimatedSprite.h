#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H
#include "StaticSprite.h"

class AnimatedSprite : public StaticSprite{

    public:
        AnimatedSprite() {}
        AnimatedSprite(int _id, int _x, int _y, int _width, int _height, ALLEGRO_BITMAP *idl, ALLEGRO_BITMAP *fl, vector<ALLEGRO_BITMAP*> ms, vector<ALLEGRO_BITMAP*> as, vector<ALLEGRO_BITMAP*> als,vector<ALLEGRO_BITMAP*> ds);
        
        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();

        //controlla se l'oggetto di gioco ha toccato un altro oggetto di gioco
        //checks if the game object touched another game object
        int isColliding();

        //controlla se l'oggetto di gioco è stato toccato
        //checks if the game object was touched
        int isCollided();

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
        bool isDying;
};

#endif