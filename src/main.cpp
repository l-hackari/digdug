#include "../include/Game.h"
#include "../include/GameObject.h"
#include "../include/StaticGameObject.h"
int main(int argc, char **argv){

    
    Game game;
    ALLEGRO_BITMAP *bitmap = al_load_bitmap("../res/images/player.png");
    GameObject *player = new StaticGameObject(10,10,bitmap);
    while(game.isGameRunning()){
        game.updateGameScene();
         player -> drawOnScreen();
    }



    

    


}