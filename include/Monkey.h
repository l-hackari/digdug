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
        
        //funzione ricorsiva che calcola il costo di tutti i percorsi disponibili per arrivare all'obiettivo passato come parametro
        //recursive function that calculates the cost of all available paths to arrive to the objective passed as parameter
        int findPath(direction prevDirection, int x, int y, objective objectiveToReach);

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

        //calcola la direzione da prendere in base alla posizione dell'obiettivo passato come parametro
        //calculates the direction to take depending on the position of the objective passed as parameter
        void calculateDirection(objective objectiveToReach);

    private:
            int pathMap[18*4][14*4];
            vector<direction> availableDirections;
            bool exitReached = false;
            int lockedPathCounter;
            int rallenty = 0;


};