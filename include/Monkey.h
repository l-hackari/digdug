#include "AnimatedSprite.h"
class Monkey : public AnimatedSprite{
    
    public:
        Monkey(){}
        Monkey(int _id, int _x, int _y, int _width, int _height);
        virtual void drawOnScreen();
        void drawIdle();

        void drawAttackIdle();

        void drawAlternative();

        void drawDying();
        
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

        void calculateDirection();
    private:
            int pathMap[18*4][14*4];
            vector<direction> availableDirections;
            int lockedPathCounter;
            bool alternativeMode;
            int rallenty = 0;


};