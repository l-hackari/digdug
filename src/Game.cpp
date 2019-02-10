#include "../include/Game.h"

Game::Game(){

    isRunning = true;
    al_init();
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    createDisplay();
    al_init_image_addon();
    al_install_keyboard();
    mainTimer = al_create_timer(1.0 / FPS);
    al_start_timer(mainTimer);
    eventQueue = al_create_event_queue();
    al_register_event_source(eventQueue, al_get_display_event_source(mainDisplay));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_timer_event_source(mainTimer));

}

void Game::createDisplay(){
    al_get_display_mode(0, &displayMode);
    mainDisplay = al_create_display(displayMode.width, displayMode.height);
}

void Game::endGame(){

    if(actualEvent.type == ALLEGRO_EVENT_KEY_DOWN){
        if(actualEvent.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
            isRunning = false;
            al_destroy_display(mainDisplay);
        }
    }
    

}

void Game::eventManager(){

    al_wait_for_event(eventQueue, &actualEvent);

}

bool Game::isGameRunning(){

    return isRunning;

}

void Game::updateGameScene(){

    eventManager();
    endGame();

}
