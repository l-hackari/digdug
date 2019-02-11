#include "../include/Game.h"
#include "../include/GameObject.h"
#include "../include/StaticGameObject.h"
int main(int argc, char **argv){
    
    Game game;
    while(game.isGameRunning()){
        game.updateGameScene();
    }

}