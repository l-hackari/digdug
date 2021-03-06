#ifndef PLAYER_H
#define PLAYER_H
#include "AnimatedSprite.h"
class Player : public AnimatedSprite{

    public:
        Player() {}
        Player(int _x, int _y, int _width, int _height);
        
        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();
        
        //disegna l'animazione idle dell'oggetto di gioco
        //draws game object's idle animation
        void drawIdle();

        //disegna l'animazione di attacco dell'oggetto di gioco
        //draws game object's attack animation
        void drawAttack();

        //disegna lo strumento di attacco
        //draws attack tool
        void drawArrow();

        //disegna l'animazione di gonfiamento del player
        //draws player's swallow animation
        void drawSwallowing();

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

        //controlla se l'oggetto di attacco ha toccato un altro oggetto di gioco
        //checks if the attack object touched another game object
        int isArrowColliding();

        //controlla se l'oggetto di attacco è stato toccato
        //checks if the attack object was touched
        int isArrowCollided();

        //setta a '0' tutte le celle della collisionMatrix che erano state settate a '-1' (funzione isArrowColliding)
        //sets to '0' all collisionMatrix's cells that were set to '-1' (isArrowColliding function)
        void arrowFree();

        
        void possibleDirection();

        


    private:
        vector<ALLEGRO_BITMAP*> swallowSprites;
        vector<direction>possibleDirections;
        ALLEGRO_BITMAP *harrow;
        ALLEGRO_BITMAP *varrow;
        bool isSwallowing = false;
        bool isArrowFree = false;
        bool arrowTouched = false;
        const int arrowSpriteWidth = 32;
        const int arrowSpriteHeight = 16;
        int arrowX = 0;
        int arrowY = 0;
        int arrowCounter = 5;
        int arrowHeight = 0;
        int arrowWidth = 0;
        int rallenty = 0;
};

#endif