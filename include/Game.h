#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Score.h"


//La classe principale del gioco
//This is the main class of the game

class Game {

    public:
        Game();
        ~Game();
        
        //crea un display (fullscreen) e lo imposta come display principale
        //creates a display (fullscreen) and sets it as main display
        void createDisplay();

        //inizializza a "0" tutte le celle della matrice che rappresenta la mappa di gioco
        //initalize to "0" all cells of the matrix that represents the map of the game
        void initGameMap();

        //se viene premuto il tasto "ESC" termina l'esecuzione del gioco
        //if "ESC" key is pressed terminates game execution
        void endGame();

        //un metodo che gestisce tutti gli eventi, modificando una variabile globale in base al tipo di evento
        //a method that manages all events, editing a global variable depending of the event type 
        void eventManager();

        //ritorna true se il gioco è in esecuzione, falso altrimenti
        //returns true if game is running, false otherwise
        bool isGameRunning();

        //disegna tutti gli oggetti di gioco esistenti in base agli FPS
        //draws all game objects depending on FPS
        void drawScene();

        //inizializza tutti gli oggetti di gioco
        //initializes all game object
        void initGameOjects();

        //aggiorna la scena di gioco ridisegnanto le bitmap in base agli eventi
        //updates the game scene redrawing bitmaps in base of the events
        void updateGameScene();

    private:
        ALLEGRO_DISPLAY *mainDisplay;
        ALLEGRO_DISPLAY_MODE displayMode;
        ALLEGRO_BITMAP *background;
        ALLEGRO_BITMAP *buffer;
        ALLEGRO_TIMER *mainTimer;
        ALLEGRO_EVENT actualEvent;
        ALLEGRO_EVENT_QUEUE *eventQueue;
        vector<GameObject *> gameObjs;
        vector<ALLEGRO_BITMAP *> el1;
        vector<ALLEGRO_BITMAP *> el3;
        vector<ALLEGRO_BITMAP *> el2;
        vector<ALLEGRO_BITMAP *> el4;
        vector<ALLEGRO_BITMAP *> el5;
        ALLEGRO_KEYBOARD_STATE keyboardState;
        int numGameObj;
        bool isRunning;
        const int FPS = 15;
        float scale;
        bool redraw;
        int mapScore = 0;
        int round = 1;
        int lifePoints = 3;


};

#endif