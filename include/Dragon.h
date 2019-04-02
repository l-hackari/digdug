#include "AnimatedSprite.h"

class Dragon : public AnimatedSprite{
    
    public:
        Dragon(){}
        Dragon(int _id, int _x, int _y, int _width, int _height);

        //disegna l'animazione di morte dell'oggetto di gioco
        //draws game object's dying animation
        void drawDying();

        //disegna su schermo l'oggetto di gioco
        //draws the game objects on screen
        virtual void drawOnScreen();

        //calcola la direzione da prendere in base alla posizione del giocatore
        //calculates the direction to take depending on player's position
        void calculateDirection();

        //disegna l'animazione idle dell'oggetto di gioco
        //draws game object's idle animation
        void drawIdle();

        //disegna l'animazione idle di attacco dell'oggetto di gioco
        //draws game object's attack idle animation
        void drawAttackIdle();

        //disegna l'animazione alternativa dell'oggetto di gioco
        //draws game object's alternative animation
        void drawAlternative();

        //disegna l'animazione di attacco dell'oggetto di gioco
        //draws game object's attack animation
        void drawAttack();
        
    private:
        //funzione ricorsiva che calcola il costo di tutti i percorsi disponibili per arrivare al player
        //recursive function that calculates the cost of all available paths to arrive to the player
        int findPath(direction prevDirection, int x, int y);

        //calcola le direzioni da prendere per raggiungere il player in modalità alternatva
        //calculates directions to take to reach the player in alternative mode
        void findAlternativePath();

        //calcola le direzioni da prendere per raggiungere il player
        //calculates directions to take to reach the player
        void nearestDirections(int _x, int _y);

        //assegna le direzioni rimaste al vettore che contiene le direzioni preferenziali
        //assigns remained directions to the vector that contains preferential directions
        void fillVoidDirections();

        //disegna l'animazione normale di movimento dell'oggetto di gioco
        //draws game object's normal movement animation
        void drawNormal();

        //inializza la mappa usata per calcolare i percorsi migliori
        //initializes the map used to calculate best paths
        void initPathMap();


    protected:
        ALLEGRO_BITMAP *alternativeFlatten;
        vector<ALLEGRO_BITMAP*> flames;
        vector<direction> availableDirections;
        bool alternativeMode;
        int lockedPathCounter;
        int pathMap[18*4][14*4];
        int attackCounter = 0;
        int flameCounter = 1;
        int flameHeight = 16;
        int flameWidth = 16;
        int flameX;
        int flameY;


};