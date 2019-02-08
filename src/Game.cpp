#include "../include/Game.h"

Game::Game(){}

void Game::initGame(){

    al_init();

}

void Game::createDisplay(){

    ALLEGRO_DISPLAY_MODE dmode;
    al_get_display_mode(0, &dmode);
    ALLEGRO_DISPLAY *display = al_create_display(dmode.width, dmode.height);
    displayMode = dmode;
    mainDisplay = display;
    al_rest(2.0);
}
