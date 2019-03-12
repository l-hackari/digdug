#include "../include/Game.h"

Game::Game(){

    numGameObj = 0;
    isRunning = true;
    redraw = false;
    actualPressedKey = ALLEGRO_KEY_SPACE;
    al_init();
    initGameMaps();
    createDisplay();
    al_init_image_addon();
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();
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

void Game::initGameMaps(){

    for(int i = 0; i < 18 * 4; i++){
        for(int j = 0; j < 14 * 4; j++){
            collisionMap[i][j] = 0;
        }
    }

    for(int i = 0; i < 18 * 4; i++){
        for(int j = 0; j < 14 * 4; j++){
            groundMap[i][j] = 0;
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 14 * 4; j++){
            groundMap[i][j] = 0;
        }
    }

    //DECOMMENTA PER TESTARE LE COLLISIONI
    for(int i = 64; i < 68; i++){
        for(int j = 52; j < 56; j++){
            collisionMap[i][j] = 4;
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
            case ALLEGRO_KEY_S: {
                actualPressedKey = ALLEGRO_KEY_S;
                score++;
                break;
            } 
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

    centerGround = al_load_bitmap("../res/images/ground/ground2.png");
    middleGround = al_load_bitmap("../res/images/ground/ground1.png");
    cornerGround = al_load_bitmap("../res/images/ground/ground3.png");
    blueGround = al_load_bitmap("../res/images/ground/ground4.png");
    el2.push_back(al_load_bitmap("../res/images/player/run2.png"));
    el2.push_back(al_load_bitmap("../res/images/player/run1.png"));
    el3.push_back(al_load_bitmap("../res/images/player/sw1.png"));
    el3.push_back(al_load_bitmap("../res/images/player/sw2.png"));
    el1.push_back(al_load_bitmap("../res/images/player/dei.png"));
    el1.push_back(al_load_bitmap("../res/images/player/dei.png"));
    el1.push_back(al_load_bitmap("../res/images/player/dei.png"));
    el1.push_back(al_load_bitmap("../res/images/player/dei.png"));
    el1.push_back(al_load_bitmap("../res/images/player/dei.png"));
    el1.push_back(al_load_bitmap("../res/images/player/dei.png"));
    el1.push_back(al_load_bitmap("../res/images/player/de1.png"));
    el1.push_back(al_load_bitmap("../res/images/player/de2.png"));
    el1.push_back(al_load_bitmap("../res/images/player/de3.png"));
    el1.push_back(al_load_bitmap("../res/images/player/de4.png"));
    el4.push_back(al_load_bitmap("../res/images/player/al1.png"));
    el4.push_back(al_load_bitmap("../res/images/player/al2.png"));
    el5.push_back(al_load_bitmap("../res/images/player/at.png"));
    gameObjs.push_back(new Player(1, 0, 24, 16, 16, el2[0], al_load_bitmap("../res/images/player/fl.png"), el2, el5, el4, el1, el3));
    lifePointsBitmap.push_back(new StaticSprite(2,0,274,16,16, al_load_bitmap("../res/images/player/al1.png")));
    lifePointsBitmap.push_back(new StaticSprite(2,16,274,16,16, al_load_bitmap("../res/images/player/al1.png")));
    lifePointsBitmap.push_back(new StaticSprite(2,32,274,16,16, al_load_bitmap("../res/images/player/al1.png")));
    background = al_load_bitmap("../res/images/background.png");
    string hs = "HIGH SCORE";
    string rd = "ROUND ";
    ALLEGRO_COLOR redColor = al_map_rgb(255,0,0);
    ALLEGRO_COLOR whiteColor = al_map_rgb(255,255,255);
    gameObjs.push_back(new Text(2, 10, redColor, 110, 0, hs));
    gameObjs.push_back(new Score(3, 10, whiteColor, 110, 12));
    gameObjs.push_back(new Text(4, 10, whiteColor, 110, 274, mapScore));
    gameObjs.push_back(new Text(5, 10, whiteColor, 200, 274, rd));
    gameObjs.push_back(new Text(6, 10, whiteColor, 220, 274, round));
    numGameObj+=6;

}

void Game::updateGround(){
    for(int i = 10; i < 18 * 4; i++){
        for(int j = 1; j < 14 * 4 - 1; j++){
            if(groundMap[i][j] == 1 && groundMap[i + 1][j] == 0){
                if(groundMap[i][j + 1] == 1 && groundMap[i][j - 1] == 1)
                    al_draw_bitmap(middleGround, j * 4, i * 4, 0);
                else if(groundMap[i][j + 1] == 0)
                    al_draw_bitmap(cornerGround, j * 4, i * 4, 0);
                else if(groundMap[i][j - 1] == 0)
                    al_draw_bitmap(cornerGround, j * 4, i * 4, ALLEGRO_FLIP_HORIZONTAL);
            } else if(groundMap[i][j] == 1 && groundMap[i - 1][j] == 0){
                if(groundMap[i][j + 1] == 1 && groundMap[i][j - 1] == 1)
                    al_draw_bitmap(middleGround, j * 4, i * 4, ALLEGRO_FLIP_VERTICAL);
                else if(groundMap[i][j + 1] == 0)
                    al_draw_bitmap(cornerGround, j * 4, i * 4, ALLEGRO_FLIP_VERTICAL);
                else if(groundMap[i][j - 1] == 0)
                    al_draw_bitmap(cornerGround, j * 4, i * 4, 3);
            } else if(groundMap[i][j] == 1 && groundMap[i + 1][j] == 1 && groundMap[i - 1][j] == 1){
                if(groundMap[i][j - 1] == 0)
                    al_draw_rotated_bitmap(middleGround, 2, 2, j * 4 + 2, i * 4 + 2, 1.5708, 0);
                else if(groundMap[i][j + 1] == 0)
                    al_draw_rotated_bitmap(middleGround, 2, 2, j * 4 + 2, i * 4 + 2, 4.71239, 0);
                else if(groundMap[i][j + 1] == 1 && groundMap[i][j - 1] == 1)
                    al_draw_bitmap(centerGround, j * 4, i * 4, 0);
            }
        }
    }

    for(int j = 0; j < 14 * 4; j++){
        if(groundMap[10][j] == 1){
            al_draw_bitmap(centerGround, j * 4, 9 * 4 + 2, 0);
        }
    }

    for(int i = 10; i < 18 * 4; i++){
        if(groundMap[i][0] == 1){
            if(groundMap[i + 1][0] == 1){
                al_draw_rotated_bitmap(middleGround, 2, 2, 0 + 2, i * 4 + 2, 1.5708, 0);
            } else if(groundMap[i + 1][0] == 0){
                al_draw_bitmap(cornerGround, 0, i * 4, ALLEGRO_FLIP_HORIZONTAL);
            }
        }
    }

    for(int i = 10; i < 18 * 4; i++){
        if(groundMap[i][14 * 4 - 1] == 1){
            if(groundMap[i + 1][14 * 4 - 1] == 1){
                al_draw_rotated_bitmap(middleGround, 2, 2, (14 * 4 - 1) * 4 + 2, i * 4 + 2, 4.71239, 0);
            } else if(groundMap[i + 1][14 * 4 - 1] == 0){
                al_draw_bitmap(cornerGround, (14 * 4 - 1) * 4, i * 4, 0);
            }
        }
    }
}

void Game::drawScene(){

    if(redraw && al_is_event_queue_empty(eventQueue)){
        al_set_target_bitmap(buffer);
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(background, 0, 0, 0);
        updateGround();

        for(int i = 0; i < numGameObj; i++){
            if(gameObjs[i]->getVisible())
                gameObjs[i]->drawOnScreen();
        
        }
        
        for(int i = 0; i < lifePointsBitmap.size(); i++){
                lifePointsBitmap[i] -> drawOnScreen();
        }

        if(lifePoints < lifePointsBitmap.size()){
            lifePointsBitmap.pop_back();
        }

        al_set_target_backbuffer(mainDisplay);
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_scaled_bitmap(buffer, 0, 0, nativeScreenWidth, nativeScreenHeight, (displayMode.width - (nativeScreenWidth * scale)) / 2, (displayMode.height - (nativeScreenHeight * scale)) / 2, nativeScreenWidth * scale, nativeScreenHeight * scale, 0);
        al_flip_display();
        redraw = false;
    } 

}

void resetGameScene(){
    
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
