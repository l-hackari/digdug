#include "../include/Monkey.h"

Monkey::Monkey(int _x, int _y, int _width, int _height):Enemy(_x, _y, _width, _height){
    
    id = MONKEY;
    scoreValue = 200;
    speed = 4;
    movementSprites.push_back(al_load_bitmap("res/images/redenemy/m1.png"));
    movementSprites.push_back(al_load_bitmap("res/images/redenemy/m2.png"));

    deathSprites.push_back(al_load_bitmap("res/images/redenemy/de1.png"));
    deathSprites.push_back(al_load_bitmap("res/images/redenemy/de2.png"));
    deathSprites.push_back(al_load_bitmap("res/images/redenemy/de3.png"));
    deathSprites.push_back(al_load_bitmap("res/images/redenemy/de4.png"));

    alternativeSprites.push_back(al_load_bitmap("res/images/redenemy/al1.png"));
    alternativeSprites.push_back(al_load_bitmap("res/images/redenemy/al2.png"));

    flatten = al_load_bitmap("res/images/redenemy/flatten.png");
   
}

void Monkey::drawOnScreen(){

    if(!isDying && !died && !isFlatten && !showScore){

        if(actualFrame >= animationLimit){
            actualFrame = 0;
        }

        if(isCollided() == -1 && !isEnemySwallowing){
            animationLimit = deathSprites.size();
            actualFrame = 0;
            isDying = true;
            isSwallowTimerActive = true;
            al_start_timer(swallowTimer);
            isEnemySwallowing = true;
        }

        if(itsCrashing() && !isFlatten)
                isFlatten = true;

        if(alternativeMode)
            drawAlternative();
        else
            drawNormal();
            
        

        if(isColliding() == -1 && !isEnemySwallowing){
            animationLimit = deathSprites.size();
            actualFrame = 0;
            isDying = true;
            isSwallowTimerActive = true;
            al_start_timer(swallowTimer);
            isEnemySwallowing = true;
        }

    } else if(isDying && !isFlatten) {

        if(swallowValue >= 6){
            isEnemySwallowing = false;
            drawDying();
            showScore = true;
            enemiesCounter--;
            al_stop_sample(&ret);
            al_play_sample(audios[MONSTER_DIED], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &ret);
            freeCollisionMap();
            isDying = false;
            isFlatten = false;
            score += scoreValue;
            killedEnemy++;
        } else {
            isCollided();
            if(!isSwallowTimerActive){
                isEnemySwallowing = true;
                isDying = false;
                isEnemySwallowing = false;
            } else {
                drawDying();
            }
                
            isColliding();
        }

    } else if(!isDying && isFlatten){
        if(rallenty < 16){
            al_draw_bitmap(flatten,x,y,0);
            rallenty++;
        } else{
            isDying = false;
            isFlatten = false;
            showScore = true;
            killedEnemy++;
            scoreValue *= 5;
            score += scoreValue;
            enemiesCounter--;
            rallenty = 0;
        }

    } else if(died && !showScore){
        drawIdle();
    } else if(showScore){
         if(rallenty < FPS*2){
             drawScoreValue();
             rallenty++;
            } else {
                isVisible = false;
                rallenty = 0;
            }
    }
}

void Monkey::drawAttack(){}