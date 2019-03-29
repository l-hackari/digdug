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
        
    private:
        //funzione ricorsiva che calcola il costo di tutti i percorsi disponibili per arrivare al player
        //recursive function that calculates the cost of all available paths to arrive to the player
        int findPath(direction prevDirection, int x, int y, int n);

        //calcola le direzioni da prendere per raggiungere il player
        //calculates directions to take to reach the player
        void nearestDirections(int _x, int _y);


    protected:
        ALLEGRO_BITMAP *alternativeFlatten;
        vector<direction> availableDirections;


};