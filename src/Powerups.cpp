#include "../include/Powerups.h"

Powerups::Powerups(int _id, int _x, int _y, int _width, int _height):AnimatedSprite(_id, _x, _y, _width, _height){
        
        unsigned int random = rand() % 2;
        if(random == 0) {PowerUpsBitMap = al_load_bitmap("../res/images/powerups/red.png"); scoreValue = 250;}
        else {PowerUpsBitMap = al_load_bitmap("../res/images/powerups/white.png"); scoreValue = 500;
        }
}



void Powerups::drawOnScreen(){ 
        
        if(isVisible){
                if(!showScore){
                        al_draw_bitmap(PowerUpsBitMap,x,y,0);

                        if(isCollided() == PLAYER_){
                                score += scoreValue;
                                showScore = true;
                        }

                        if(timerBonus == FPS*10){
                                isVisible = false;
                                freeCollisionMap();
                        }

                        timerBonus++;
                } else {
                        if(rallenty < FPS*2){
                                drawScoreValue();
                                rallenty++;
                        } else {
                                isVisible = false;
                                freeCollisionMap();
                        }
                }

        }     

}


