#ifndef GAME_H
#define GAME_H
#include "Score.h"
#include "Level.h"
#include "LifePoints.h"

//La classe principale del gioco
//This is the main class of the game

class Game {

    public:
        Game();
        ~Game();


        //crea un display (fullscreen) e lo imposta come display principale
        //creates a display (fullscreen) and sets it as main display
        void createDisplay();

        //mostra il menu prima dell'avvio del gioco
        //shows the menu before starting the game
        void createMenu();

        //inizializza tutte le celle delle matrici che rappresentano mappa di gioco e del terreno di gioco
        //initializes all cells of the matrices that represent the game's map and the game's ground
        void initGameMaps();

        //se viene premuto il tasto "ESC" termina l'esecuzione del gioco
        //if "ESC" key is pressed terminates game execution
        void checkendGame();

        //disegna la scritta "Pausa" e stoppa le operazioni di disegno
        //draws "Pause" text and stops graphic routines
        void checkStopGame();

        //termina l'esecuzione del gioco
        //terminates game executon
        void quit();

        //un metodo che gestisce tutti gli eventi, modificando una variabile globale in base al tipo di evento
        //a method that manages all events, editing a global variable depending of the event type 
        void eventManager();

        //metodo per caricare i file audio che verranno riprodotti
        //method to load audio files that will be reproduced
        void loadAudios();

        //ritorna true se il gioco è in esecuzione, falso altrimenti
        //returns true if game is running, false otherwise
        bool isGameRunning();

        //disegna tutti gli oggetti di gioco esistenti in base agli FPS
        //draws all game objects depending on FPS
        void drawScene();

        //draws a scene where a 'Game Over' sentence is written
        //disegna una scena dove viene scritta la frase 'Game Over'
        void drawFinalScene();

        //inizializza tutti gli oggetti di gioco
        //initializes all game object
        void initGameOjects();

        //aggiorna la scena di gioco ridisegnanto le bitmap in base agli eventi
        //updates the game scene redrawing bitmaps in base of the events
        void updateGameScene();

        //disegna le zone scavate del terreno di gioco
        //draws digged game's ground zones
        void updateGround();

        //carica tutte le impostazioni generate dal livello creato
        //loads all settings generted by created level
        void loadLevel(int difficulty);

        //carica il punteggio migliore registrato
        //loads the best registered score
        void loadBestScore();

        //controlla se il punteggio fatto è superiore al punteggio migliore e lo salva
        //checks if the actual score is higher than the best score and saves it
        void saveBestScore();

        //resetta tutte le impostazioni in modo da avviare un nuovo livello
        //resets all setting to start a new level
        void resetGameScene();

        //elimina tutti i gameObject allocati
        //deletes all allocated gameObject
        void deleteGameObjects();

        //ripristina la posizione iniziale degli oggetti di gioco
        //restores the initial position of game objects
        void resetGameObjects();

        
    private:
        ALLEGRO_DISPLAY *mainDisplay;
        ALLEGRO_DISPLAY_MODE displayMode;
        ALLEGRO_BITMAP *background;
        ALLEGRO_BITMAP *buffer;
        ALLEGRO_BITMAP *centerGround;
        ALLEGRO_BITMAP *middleGround;
        ALLEGRO_BITMAP *cornerGround;
        ALLEGRO_TIMER *mainTimer;
        ALLEGRO_EVENT actualEvent;
        ALLEGRO_EVENT_QUEUE *eventQueue;
        vector<GameObject *> gameObjs;
        Level *actualLevel;
        ALLEGRO_KEYBOARD_STATE keyboardState;
        int bestScore;
        bool isRunning;
        bool lastEnemySong = false;
        float scale;
        bool redraw;
        int round = 1;
        bool isGameInPause = false;
        bool setPause = false;
        bool showMenu = true;
        bool showControls = false;
};

#endif