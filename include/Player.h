#ifndef PLAYER_H
#define PLAYER_H
#include "AnimatedGameObject.h"

class Player : public AnimatedGameObject{

    public:
        Player() {}
        Player(int _id, int _x, int _y, int _width, int _height, ALLEGRO_BITMAP *fl, ALLEGRO_BITMAP *di, vector<ALLEGRO_BITMAP*> ms, vector<ALLEGRO_BITMAP*> as, vector<ALLEGRO_BITMAP*> als ,vector<ALLEGRO_BITMAP*> ds, vector<ALLEGRO_BITMAP*> sw);
        
        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();
        
        //disegna l'animazione idle dell'oggetto di gioco
        //draws game object's idle animation
        void drawIdle();

        //disegna l'animazione di attacco dell'oggetto di gioco
        //draws game object's attack animation
        void drawAttack();

        //disegna l'animazione alternativa dell'oggetto di gioco
        //draws game object's alternative animation
        void drawAlternative();

    private:
        vector<ALLEGRO_BITMAP*> swallowSprites;
        ALLEGRO_BITMAP *deathIdle;
        
};

#endif