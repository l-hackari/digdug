#ifndef PLAYER_H
#define PLAYER_H
#include "AnimatedSprite.h"
class Player : public AnimatedSprite{

    public:
        Player() {}
        Player(int _id, int _x, int _y, int _width, int _height);
        
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

        //disegna l'animazione di morte dell'oggetto di gioco
        //draws game object's dying animation
        void drawDying();

        //segna le zone scavate dal giocatore
        //marks the zones that are digged by the player
        void digs();

        //controlla se la zona attraversata è stata scavata
        //checks if crossed zone was digged
        bool checkDigged();

    private:
        vector<ALLEGRO_BITMAP*> swallowSprites;
        vector<ALLEGRO_BITMAP*> attackSprites;
};

#endif