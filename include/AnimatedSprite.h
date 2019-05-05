#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H
#include "StaticSprite.h"
#include "Text.h"
#include "Node.h"

class AnimatedSprite : public StaticSprite{

    public:
        AnimatedSprite() {}

        AnimatedSprite(int _x, int _y, int _width, int _height);
        
        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();

        //controlla se l'oggetto di gioco ha toccato un altro oggetto di gioco
        //checks if the game object touched another game object
        int isColliding();

        //controlla se l'oggetto di gioco è stato toccato
        //checks if the game object was touched
        int isCollided();

        //setta a '0' tutte le celle della collisionMatrix che erano state settate a 'id' (funzione isColliding)
        //sets to '0' all collisionMatrix's cells that were set to 'id' (isColliding function)
        void freeCollisionMap();

        //controlla se l'oggetto di gioco è stato colliso da un masso
        //checks if game object was collided by a stone
        bool itsCrashing();

        //disegna il punteggio ottenuto dall'uccisione del nemico o da un bonus
        //draws the score obtained from killing enemy or obtained from a bonus
        void drawScoreValue();

        ~AnimatedSprite();

    protected:
        vector<ALLEGRO_BITMAP*> movementSprites;
        vector<ALLEGRO_BITMAP*> alternativeSprites;
        vector<ALLEGRO_BITMAP*> deathSprites;
        vector<ALLEGRO_BITMAP*> attackSprites;
        ALLEGRO_BITMAP *flatten;
        int animationLimit;
        int previousAnimation;
        direction previousDirection;
        direction orientation;
        int actualFrame = 0;
        bool isDying;
        int speed;
        bool isFlatten = false;
        bool loop = false;
        int scoreValue;
        Text *text = nullptr;
        bool showScore = false;
};

#endif