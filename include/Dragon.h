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

        //calcola la direzione da prendere in base alla posizione dell'obiettivo passato come parametro
        //calculates the direction to take depending on the position of the objective passed as parameter
        void calculateDirection(objective objectiveToReach);

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
        //funzione che calcola il costo di tutti i percorsi disponibili per arrivare all'obiettivo passato come parametro
        //function that calculates the cost of all available paths to arrive to the objective passed as parameter
        direction findPath(int startX, int startY, objective objectiveToReach);

        //calcola le direzioni da prendere per raggiungere l'obiettivo in modalità alternatva
        //calculates directions to take to reach the objective in alternative mode
        void findAlternativePath();

        //calcola le direzioni da prendere per raggiungere le coordinate passate
        //calculates directions to take to reach passed coordinates
        void nearestDirections(int _start_x, int _start_y, int _arrive_x, int _arrive_y);

        //assegna le direzioni rimaste al vettore che contiene le direzioni preferenziali
        //assigns remained directions to the vector that contains preferential directions
        void fillVoidDirections();

        //disegna l'animazione normale di movimento dell'oggetto di gioco
        //draws game object's normal movement animation
        void drawNormal();

        //inializza la mappa usata per calcolare i percorsi migliori
        //initializes the map used to calculate best paths
        void initPathMap();

        //cancella le celle occupate dalle fiamme nella collisionMap
        //erases collisionMap's cells occupied by flames
        void clearFlameCollisionMap();

        //riempie la collisionMap in base alla posizione delle fiamme
        //fills collisionMap depending on flames' position
        bool fillFlameCollisionMap();


    protected:
        ALLEGRO_BITMAP *alternativeFlatten;
        vector<ALLEGRO_BITMAP*> flames;
        vector<direction> availableDirections;
        bool exitReached = false;
        bool needToFreeFlameMap = false;
        int lockedPathCounter;
        int pathMap[18*4][14*4];
        int attackCounter = 0;
        int flameCounter = 1;
        int flameHeight = 16;
        int flameWidth = 16;
        int flameX;
        int flameY;
        int rallenty = 0;


};