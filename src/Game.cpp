#include "../include/Game.h"

Game::Game(){}

void Game::initGame(){

    al_init();

}

void Game::createDisplay(){

    al_get_display_mode(0, &displayMode);
    mainDisplay = al_create_display(displayMode.width, displayMode.height);
    al_rest(2.0);
}
