#ifndef GAME_H
#define GAME_H
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

//La classe principale del gioco
//This is the main class of the game
class Game {

    public:
        Game();
        //inizializza gli strumenti necessari per sfruttare Allegro
        //initializes tools needed to use Allegro
        void initGame();

        //crea un display (fullscreen) e lo imposta come display principale
        //creates a display (fullscreen) and sets it as main display
        void createDisplay();

        //crea  una coda degli eventi e un listener in attesa del tasto "ESCAPE" per uscire dal gioco
        //creates a event queue and a listener waiting for the "ESCAPE" key to exit from the game 
        void initEvent();

    private:
        ALLEGRO_DISPLAY *mainDisplay;
        ALLEGRO_DISPLAY_MODE displayMode;
        const int FPS = 60;

};

#endif