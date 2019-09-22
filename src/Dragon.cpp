#include "../include/Dragon.h"

Dragon::Dragon(int _x, int _y, int _width, int _height): Enemy(_x, _y, _width, _height){

    id = DRAGON;
    scoreValue = 300;
    speed = 4;
    movementSprites.push_back(al_load_bitmap("res/images/dragon/run2.png"));
    movementSprites.push_back(al_load_bitmap("res/images/dragon/run1.png"));
    deathSprites.push_back(al_load_bitmap("res/images/dragon/de1.png"));
    deathSprites.push_back(al_load_bitmap("res/images/dragon/de2.png"));
    deathSprites.push_back(al_load_bitmap("res/images/dragon/de3.png"));
    deathSprites.push_back(al_load_bitmap("res/images/dragon/de4.png"));
    alternativeSprites.push_back(al_load_bitmap("res/images/dragon/al1.png"));
    alternativeSprites.push_back(al_load_bitmap("res/images/dragon/al2.png"));
    attackSprites.push_back(al_load_bitmap("res/images/dragon/at1.png"));
    attackSprites.push_back(al_load_bitmap("res/images/dragon/at2.png"));
    flatten = al_load_bitmap("res/images/dragon/fl.png");
    alternativeFlatten = al_load_bitmap("res/images/dragon/flal.png");
    flames.push_back(al_load_bitmap("res/images/dragon/flame1.png"));
    flames.push_back(al_load_bitmap("res/images/dragon/flame2.png"));
    flames.push_back(al_load_bitmap("res/images/dragon/flame3.png"));

}

void Dragon::clearFlameCollisionMap(){
    for(int i = flameY / collisionCellDivider; i < (flameY + flameHeight) / collisionCellDivider; i++){
        for(int j = flameX / collisionCellDivider; j < (flameX + flameWidth) / collisionCellDivider; j++){
            if(j > 0 && j < originalCollisionMapWidth * collisionCellDivider - 1 && i >= 6){
                collisionMap[i][j] = 0;
            }
        }
    }
}

bool Dragon::fillFlameCollisionMap(){
    for(int i = flameY / collisionCellDivider; i < (flameY + flameHeight) / collisionCellDivider; i++){
        for(int j = flameX / collisionCellDivider; j < (flameX + flameWidth) / collisionCellDivider; j++){
            if(j > 0 && j < originalCollisionMapWidth * collisionCellDivider - 1 && i >= 6){
                if(groundMap[i][j] == 0 || groundMap[i][j] == STONE)
                    return false;
                
                collisionMap[i][j] = id;
            }
        }
    }

    return true;
}

void Dragon::drawAttackIdle(){
    
    if(orientation == RIGHT)
        al_draw_bitmap(attackSprites[0], x, y, 0);
    else
        al_draw_bitmap(attackSprites[0], x, y, ALLEGRO_FLIP_HORIZONTAL);
}

void Dragon::drawAttack(){

    if(attackCounter < dragonAttackPreparingCounter){
        if(attackCounter % 2 == 0)
            drawAttackIdle();
        else
            drawIdle();

        attackCounter++;
    } else {
        clearFlameCollisionMap();
        switch (previousDirection)
        {
            case LEFT:
                flameWidth = spriteWidth * flameCounter;
                flameX = x - flameWidth;
                flameY = y;
                al_draw_bitmap(attackSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
                al_draw_bitmap(flames[flameCounter - 1], flameX, flameY, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case RIGHT:
                flameWidth = 16 * flameCounter;
                flameX = x + width;
                flameY = y;
                al_draw_bitmap(attackSprites[actualFrame], x, y, 0);
                al_draw_bitmap(flames[flameCounter - 1], flameX, flameY, 0);
                break;
            default:
                break;
        }

        if(fillFlameCollisionMap()){
            flameCounter++;

            if(flameCounter > 3){
                flameCounter = 1;
                attackCounter = 0;
                needToFreeFlameMap = true;
            }

        } else {
            flameCounter = 1;
            attackCounter = 0;
            clearFlameCollisionMap();
        }
    }
}

void Dragon::drawOnScreen(){

    if(!isDying && !died && !isFlatten && !showScore){

        if(actualFrame >= animationLimit){
            actualFrame = 0;
        }

        if(needToFreeFlameMap){
            clearFlameCollisionMap();
            needToFreeFlameMap = false;
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

        if(alternativeMode){
            drawAlternative();
        } else{
            if((previousDirection == LEFT && y == playerY && (x - playerX) <= distanceToAttack && x > playerX) || (previousDirection == RIGHT && y == playerY && (playerX - x) <= distanceToAttack && x < playerX)){
                drawAttack();
            } else {
                flameCounter = 1;
                attackCounter = 0;
                drawNormal();
            }
                
        }
        
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
            score += scoreValue;
            freeCollisionMap();
            isDying = false;
            killedEnemy++;
            isFlatten = false;
        } else {
            isCollided();
            if(!isSwallowTimerActive){
                drawNormal();
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
            scoreValue = (scoreValue*3) + 100;
            score += scoreValue;
            enemiesCounter--;
            killedEnemy++;
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