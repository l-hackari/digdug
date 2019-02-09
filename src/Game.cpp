#include "../include/Game.h"

Game::Game(){}

void Game::initGame(){
    
    al_init();
    al_init_image_addon();
    al_install_keyboard();

}

void Game::initEvent(){
    
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    ALLEGRO_EVENT_QUEUE *event_queque = al_create_event_queue();
    al_register_event_source(event_queque,al_get_keyboard_event_source());
    al_register_event_source(event_queque,al_get_timer_event_source(timer));
    al_start_timer(timer);
    while(true){
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queque,&events);

        if(events.type == ALLEGRO_EVENT_KEY_DOWN){

            if(events.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                break;
            }
        }
    }

    al_destroy_display(mainDisplay);

}

void Game::createDisplay(){
    al_get_display_mode(0, &displayMode);
    mainDisplay = al_create_display(displayMode.width, displayMode.height);
    al_rest(2.0);
}
