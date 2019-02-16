#include "../include/Game.h"

Game::Game(){

    numGameObj = 0;
    isRunning = true;
    redraw = false;
    actualPressedKey = ALLEGRO_KEY_SPACE;
    al_init();
    initGameMap();
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
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    al_get_display_mode(0, &displayMode);
    mainDisplay = al_create_display(displayMode.width, displayMode.height);
    buffer = al_create_bitmap(nativeScreenHeight, nativeScreenHeight);
    float scaleW = static_cast<float>(displayMode.width) / static_cast<float>(nativeScreenWidth);
    float scaleH = static_cast<float>(displayMode.height) / static_cast<float>(nativeScreenHeight);
    scale = min(scaleW, scaleH);
   
}

void Game::initGameMap(){

    for(int i = 0; i < 14; i++){
        for(int j = 0; j < 18; j++){
            gameMap[i][j] = 0;
        }
    }
}

void Game::endGame(){

    if(actualPressedKey == ALLEGRO_KEY_ESCAPE){
        isRunning = false;
        al_destroy_display(mainDisplay);
    }
    

}

void Game::eventManager(){

    al_wait_for_event(eventQueue, &actualEvent);

    if(actualEvent.type == ALLEGRO_EVENT_TIMER){

        redraw = true;
        al_get_keyboard_state(&keyboardState);

        if(!al_key_down(&keyboardState, actualPressedKey))
            actualPressedKey = ALLEGRO_KEY_SPACE;
        
        

    } else if(actualEvent.type == ALLEGRO_EVENT_KEY_DOWN){

        switch (actualEvent.keyboard.keycode)
        {
            case ALLEGRO_KEY_ESCAPE:
                actualPressedKey = ALLEGRO_KEY_ESCAPE;
                break;
            case ALLEGRO_KEY_UP:
                actualPressedKey = ALLEGRO_KEY_UP;
                break;
            case ALLEGRO_KEY_LEFT:
                actualPressedKey = ALLEGRO_KEY_LEFT;
                break;
            case ALLEGRO_KEY_RIGHT:
                actualPressedKey = ALLEGRO_KEY_RIGHT;
                break;
            case ALLEGRO_KEY_DOWN:
                actualPressedKey = ALLEGRO_KEY_DOWN;
                break;
            case ALLEGRO_KEY_S:
                actualPressedKey = ALLEGRO_KEY_S;
                break;
            case ALLEGRO_KEY_D:
                actualPressedKey = ALLEGRO_KEY_D;
                break;
            default:
                break;
        }
    }
}

bool Game::isGameRunning(){

    return isRunning;

}

void Game::initGameOjects(){

    el2.push_back(al_load_bitmap("../res/images/player/run2.png"));
    el2.push_back(al_load_bitmap("../res/images/player/run1.png"));
    el3.push_back(al_load_bitmap("../res/images/player/sw1.png"));
    el3.push_back(al_load_bitmap("../res/images/player/sw2.png"));
    el1.push_back(al_load_bitmap("../res/images/player/de1.png"));
    el1.push_back(al_load_bitmap("../res/images/player/de2.png"));
    el1.push_back(al_load_bitmap("../res/images/player/de3.png"));
    el1.push_back(al_load_bitmap("../res/images/player/de4.png"));
    el4.push_back(al_load_bitmap("../res/images/player/al1.png"));
    el4.push_back(al_load_bitmap("../res/images/player/al2.png"));
    el5.push_back(al_load_bitmap("../res/images/player/at.png"));
    gameObjs.push_back(new Player(1, 0, 0, 16, 16, al_load_bitmap("../res/images/player/fl.png"), al_load_bitmap("../res/images/player/di.png"), el2, el5, el4, el1, el3));
    background = al_load_bitmap("../res/images/background.png");
    numGameObj+=1;

}

void Game::drawScene(){

    if(redraw && al_is_event_queue_empty(eventQueue)){
        al_set_target_bitmap(buffer);
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(background, 0, 0, 0);

        for(int i = 0; i < numGameObj; i++)
            gameObjs[i]->drawOnScreen();

        al_set_target_backbuffer(mainDisplay);
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_scaled_bitmap(buffer, 0, 0, nativeScreenWidth, nativeScreenHeight, (displayMode.width - (nativeScreenWidth * scale)) / 2, (displayMode.height - (nativeScreenHeight * scale)) / 2, nativeScreenWidth * scale, nativeScreenHeight * scale, 0);
        al_flip_display();
        redraw = false;
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
