#include "../include/Game.h"

int main(int argc, char **argv){    
    Game game;
    while(game.isGameRunning()){
        game.updateGameScene();
    }

}