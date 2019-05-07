#ifndef ENEMY_H
#define ENEMY_H
#include "AnimatedSprite.h"

enum objective {OBJ_PLAYER = 0, OBJ_EXIT};

class Enemy : public AnimatedSprite{
    
    public:
        Enemy(){}
        Enemy(int _x, int _y, int _width, int _height);

    protected:

        //disegna l'animazione normale di movimento dell'oggetto di gioco
        //draws game object's normal movement animation
        virtual void drawNormal();

        //disegna l'animazione idle dell'oggetto di gioco
        //draws game object's idle animation
        virtual void drawIdle();

        //disegna l'animazione di morte dell'oggetto di gioco
        //draws game object's dying animation
        virtual void drawDying();

        //disegna l'animazione alternativa dell'oggetto di gioco
        //draws game object's alternative animation
        virtual void drawAlternative();

        //disegna l'animazione di attacco dell'oggetto di gioco
        //draws game object's attack animation
        virtual void drawAttack() = 0;

        //calcola la direzione da prendere in base alla posizione dell'obiettivo passato come parametro
        //calculates the direction to take depending on the position of the objective passed as parameter
        void calculateDirection(objective objectiveToReach);

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

        //cancella le celle occupate dalle fiamme nella collisionMap
        //erases collisionMap's cells occupied by flames
        void clearFlameCollisionMap();

        //riempie la collisionMap in base alla posizione delle fiamme
        //fills collisionMap depending on flames' position
        bool fillFlameCollisionMap();


    protected:
        vector<direction> availableDirections;
        bool exitReached = false;
        int lockedPathCounter;
        int rallenty = 0;
        int lockedPathLimit;


};

#endif