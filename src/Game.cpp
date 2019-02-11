#include "../include/Game.h"

Game::Game(){

    numGameObj = 0;
    var = 0;
    isRunning = true;
    al_init();
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    createDisplay();
    al_init_image_addon();
    al_install_keyboard();
    initGameOjects();
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

void Game::initGameOjects(){

    gameObjs.push_back(new StaticGameObject(10,10,"../res/images/player.png"));
    gameObjs.push_back(new StaticGameObject(100,100,"../res/images/player2.png"));
    numGameObj+=2;

}

void Game::drawScene(){

    if(actualEvent.type == ALLEGRO_EVENT_TIMER){

        al_clear_to_color(al_map_rgb(0, 0, 0));
        for(int i = 0; i < numGameObj; i++)
            gameObjs[i]->drawOnScreen();

        al_flip_display();

    } 

}

void Game::updateGameScene(){

    drawScene();
    eventManager();
    endGame();

}

Game::~Game(){
    for(int i = 0; i < numGameObj; i++){
        delete gameObjs[i];
    }
}
