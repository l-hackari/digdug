#include "../include/Player.h"

Player::Player(int _id, int _x, int _y, int _width, int _height): AnimatedSprite(_id, _x, _y, _width, _height){

    speed = 4;
    varrow = al_load_bitmap("../res/images/arrow/varrow.png");
    harrow = al_load_bitmap("../res/images/arrow/harrow.png");
    movementSprites.push_back(al_load_bitmap("../res/images/player/run2.png"));
    movementSprites.push_back(al_load_bitmap("../res/images/player/run1.png"));
    swallowSprites.push_back(al_load_bitmap("../res/images/player/sw1.png"));
    swallowSprites.push_back(al_load_bitmap("../res/images/player/sw2.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/player/dei.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/player/dei.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/player/dei.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/player/dei.png"));
    //DA CAMBIARE
    deathSprites.push_back(al_load_bitmap("../res/images/player/dei.png")); 
    deathSprites.push_back(al_load_bitmap("../res/images/player/dei.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/player/de1.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/player/de2.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/player/de3.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/player/de4.png"));
    alternativeSprites.push_back(al_load_bitmap("../res/images/player/al1.png"));
    alternativeSprites.push_back(al_load_bitmap("../res/images/player/al2.png"));
    attackSprites.push_back(al_load_bitmap("../res/images/player/at.png"));

}

int Player::isArrowColliding(){
    int collidedID = 0;
    if(previousDirection == LEFT || previousDirection == RIGHT){

        int i = (((arrowY + arrowHeight) / 4) - 1) - (((arrowHeight / 4)) / 2);
        for(int j = arrowX / 4; j < (arrowX + arrowWidth) / 4; j++){
            if(j > 0 && j < 14 * 4 - 1){
                if(collisionMap[i][j] != 0 && collisionMap[i][j] != -1){
                    collidedID = collisionMap[i][j];
                }
            } 
        }

        for(int j = arrowX / 4; j < (arrowX + arrowWidth) / 4; j++){
            if(j > 0 && j < 14 * 4 - 1){
                collisionMap[i][j] = -1;
            }
        }
    } else {

        int j = (((arrowX + arrowWidth) / 4) - 1) - (((arrowWidth / 4)) / 2);
        for(int i = arrowY / 4; i < (arrowY + arrowHeight) / 4; i++){
            if(i >= 6){
                if(collisionMap[i][j] != 0 && collisionMap[i][j] != -1){
                    collidedID = collisionMap[i][j];
                }
            }
        }

        for(int i = arrowY / 4; i < (arrowY + arrowHeight) / 4; i++){
            if(i >= 6){
                collisionMap[i][j] = -1;
            }
        }
    }

    return collidedID;

}

int Player::isArrowCollided(){

    int collidedID = 0;
    if(previousDirection == LEFT || previousDirection == RIGHT){

        int i = (((arrowY + arrowHeight) / 4) - 1) - (((arrowHeight / 4)) / 2);
        for(int j = arrowX / 4; j < (arrowX + arrowWidth) / 4; j++){
            if(j > 0 && j < 14 * 4 - 1){
                if(collisionMap[i][j] != 0 && collisionMap[i][j] != -1){
                    collidedID = collisionMap[i][j];
                }
            }
        }

        for(int j = arrowX / 4; j < (arrowX + arrowWidth) / 4; j++){
            if(j > 0 && j < 14 * 4 - 1){
                collisionMap[i][j] = 0;
            }
        }
    } else {

        int j = (((arrowX + arrowWidth) / 4) - 1) - (((arrowWidth / 4)) / 2);
        for(int i = arrowY / 4; i < (arrowY + arrowHeight) / 4; i++){
            if(i >= 6){
                if(collisionMap[i][j] != 0 && collisionMap[i][j] != -1){
                    collidedID = collisionMap[i][j];
                }
            }
        }

        for(int i = arrowY / 4; i < (arrowY + arrowHeight) / 4; i++){
            if(i >= 6){
                collisionMap[i][j] = 0;
            }
        }
    }

    return collidedID;

}

void Player::arrowFree(){

    if(previousDirection == LEFT || previousDirection == RIGHT){

        int i = (((arrowY + arrowHeight) / 4) - 1) - (((arrowHeight / 4)) / 2);

        for(int j = arrowX / 4; j < (arrowX + arrowWidth) / 4; j++){
            collisionMap[i][j] = 0;
        }

    } else {

        int j = (((arrowX + arrowWidth) / 4) - 1) - (((arrowWidth / 4)) / 2);

        for(int i = arrowY / 4; i < (arrowY + arrowHeight) / 4; i++){
            collisionMap[i][j] = 0;
        }
    }
}

void Player::drawIdle(){
    switch (previousDirection)
    {
        case LEFT:
            al_draw_bitmap(movementSprites[1], x, y, ALLEGRO_FLIP_HORIZONTAL);
            break;
        case RIGHT:
            al_draw_bitmap(movementSprites[1], x, y, 0);
            break;
        case UP:
            if(orientation == LEFT)
                al_draw_rotated_bitmap(movementSprites[1], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, ALLEGRO_FLIP_VERTICAL);
            else
                al_draw_rotated_bitmap(movementSprites[1], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
            break;
        case DOWN:
            if(orientation == LEFT)
                al_draw_rotated_bitmap(movementSprites[1], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, ALLEGRO_FLIP_VERTICAL);
            else 
                al_draw_rotated_bitmap(movementSprites[1], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, 0);   
            break;
        default:
            break;
    }

}

void Player::drawAttack(){

    switch (previousDirection)
    {
        case LEFT:
            arrowWidth = 32 / arrowCounter;
            arrowHeight = 16;
            arrowX = x - arrowWidth;
            arrowY = y;
            al_draw_bitmap(attackSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
            al_draw_bitmap_region(harrow, 32 - arrowWidth, 0, arrowWidth, arrowHeight, arrowX, arrowY, ALLEGRO_FLIP_HORIZONTAL);
            break;
        case RIGHT:
            arrowWidth = 32 / arrowCounter;
            arrowHeight = 16;
            arrowX = x + width;
            arrowY = y;
            al_draw_bitmap(attackSprites[actualFrame], x, y, 0);
            al_draw_bitmap_region(harrow, 32 - arrowWidth, 0, arrowWidth, arrowHeight, arrowX, arrowY, 0);
            break;
        case UP:
            if(orientation == LEFT)
                al_draw_rotated_bitmap(attackSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, ALLEGRO_FLIP_VERTICAL);
            else
                al_draw_rotated_bitmap(attackSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
            
            arrowWidth = 16;
            arrowHeight = 32 / arrowCounter;
            arrowX = x;
            arrowY = y - arrowHeight;
            al_draw_bitmap_region(varrow, 0, 0, arrowWidth, arrowHeight, arrowX, arrowY, 0);
            break;
        case DOWN:
            if(orientation == LEFT)
                al_draw_rotated_bitmap(attackSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, ALLEGRO_FLIP_VERTICAL);
            else
                al_draw_rotated_bitmap(attackSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, 0);
            
            arrowWidth = 16;
            arrowHeight = 32 / arrowCounter;
            arrowX = x;
            arrowY = y + width;
            al_draw_bitmap_region(varrow, 0, 0, arrowWidth, arrowHeight, arrowX, arrowY, ALLEGRO_FLIP_VERTICAL);
            break;
        default:
            break;
    }

}

void Player::drawAlternative(){

    switch (previousDirection)
    {
        case LEFT:
            al_draw_bitmap(alternativeSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
            break;
        case RIGHT:
            al_draw_bitmap(alternativeSprites[actualFrame], x, y, 0);
            break;
        case UP:
            if(orientation == LEFT)
                al_draw_rotated_bitmap(alternativeSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, ALLEGRO_FLIP_VERTICAL);
            else
                al_draw_rotated_bitmap(alternativeSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
            break;
        case DOWN:
            if(orientation == LEFT)
                al_draw_rotated_bitmap(alternativeSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, ALLEGRO_FLIP_VERTICAL);
            else
                al_draw_rotated_bitmap(alternativeSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, 0);
            break;
        default:
            break;
    }

}

void Player::drawDying(){

    switch (previousDirection)
    {
        case LEFT:
            al_draw_bitmap(deathSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
            break;
        case RIGHT:
            al_draw_bitmap(deathSprites[actualFrame], x, y, 0);
            break;
        case UP:
            if(orientation == LEFT)
                al_draw_rotated_bitmap(deathSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, ALLEGRO_FLIP_VERTICAL);
            else
                al_draw_rotated_bitmap(deathSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
            break;
        case DOWN:
            if(orientation == LEFT)
                al_draw_rotated_bitmap(deathSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, ALLEGRO_FLIP_VERTICAL);
            else
                al_draw_rotated_bitmap(deathSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, 0);
            break;
        default:
            break;
    }

}

void Player::drawSwallowing(){

    if(actualPressedKey == ALLEGRO_KEY_D){
        al_stop_timer(swallowTimer);
        al_start_timer(swallowTimer);
        swallowValue++;
        switch (previousDirection)
        {
            case LEFT:
                al_draw_bitmap(swallowSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case RIGHT:
                al_draw_bitmap(swallowSprites[actualFrame], x, y, 0);
                break;
            case UP:
                if(orientation == LEFT)
                    al_draw_rotated_bitmap(swallowSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, ALLEGRO_FLIP_VERTICAL);
                else
                    al_draw_rotated_bitmap(swallowSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
                break;
            case DOWN:
                if(orientation == LEFT)
                    al_draw_rotated_bitmap(swallowSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, ALLEGRO_FLIP_VERTICAL);
                else
                    al_draw_rotated_bitmap(swallowSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, 0);
                break;
            default:
                break;
        }
    } else {
        switch (previousDirection)
        {
            case LEFT:
                al_draw_bitmap(swallowSprites[0], x, y, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case RIGHT:
                al_draw_bitmap(swallowSprites[0], x, y, 0);
                break;
            case UP:
                if(orientation == LEFT)
                    al_draw_rotated_bitmap(swallowSprites[0], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, ALLEGRO_FLIP_VERTICAL);
                else
                    al_draw_rotated_bitmap(swallowSprites[0], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
                break;
            case DOWN:
                if(orientation == LEFT)
                    al_draw_rotated_bitmap(swallowSprites[0], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, ALLEGRO_FLIP_VERTICAL);
                else
                    al_draw_rotated_bitmap(swallowSprites[0], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, 0);
                break;
            default:
                break;
        }
    }
    
}

bool Player::checkDigged(){

    for(int i = y / 4; i < (y + height) / 4; i++){
        for(int j = x / 4; j < (x + width) / 4; j++){
            if(groundMap[i][j] == 0)
                return false;
        }
    } 

    return true;
}

void Player::digs(){

    for(int i = y / 4; i < (y + height) / 4; i++){
        for(int j = x / 4; j < (x + width) / 4; j++){
            groundMap[i][j] = 1;
        }
    }
}


void Player::drawOnScreen(){

    playerX = x;
    playerY = y;

    if(!isDying && !isSwallowing){

        if(actualFrame >= animationLimit){
            actualFrame = 0;
        }
        
        if(previousAnimation != actualPressedKey){
            actualFrame = 0;
            if(previousAnimation == ALLEGRO_KEY_D)
                arrowFree();
            
            arrowCounter = 4;  
        }
        
        int collID = isCollided();
        if(collID != -1 && collID != 0){
            animationLimit = deathSprites.size();
            actualFrame = 0;
            isDying = true;
            died = true;
        }
        switch (actualPressedKey)
        {
            case ALLEGRO_KEY_UP:
                if(y > 24)
                    y -= speed;
                
                if(!checkDigged()){

                    if(orientation == LEFT){
                        al_draw_rotated_bitmap(alternativeSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, ALLEGRO_FLIP_VERTICAL);
                    } else {
                        al_draw_rotated_bitmap(alternativeSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
                    }
                    
                    animationLimit = alternativeSprites.size();
                
                } else {

                    if(orientation == LEFT){
                        al_draw_rotated_bitmap(movementSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, ALLEGRO_FLIP_VERTICAL);
                    } else {
                        al_draw_rotated_bitmap(movementSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
                    }

                    animationLimit = movementSprites.size();
                }

                digs();
                previousDirection = UP;
                previousAnimation = ALLEGRO_KEY_UP;
                actualFrame++;
                break;
            case ALLEGRO_KEY_DOWN:
                if(y < 256)
                    y += speed;
                
                if(!checkDigged()){

                    if(orientation == LEFT){
                        al_draw_rotated_bitmap(alternativeSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, ALLEGRO_FLIP_VERTICAL);
                    } else {
                        al_draw_rotated_bitmap(alternativeSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, 0);
                    }

                    animationLimit = alternativeSprites.size();
                
                } else {

                    if(orientation == LEFT){
                        al_draw_rotated_bitmap(movementSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, ALLEGRO_FLIP_VERTICAL);
                    } else {
                        al_draw_rotated_bitmap(movementSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, 0);
                    }

                    animationLimit = movementSprites.size();
                }

                digs();
                previousDirection = DOWN;
                previousAnimation = ALLEGRO_KEY_DOWN;
                actualFrame++;
                break;
            case ALLEGRO_KEY_RIGHT:
                if(x + width < nativeScreenWidth)
                    x += speed;

                if(!checkDigged()){
                    al_draw_bitmap(alternativeSprites[actualFrame], x, y, 0);
                    animationLimit = alternativeSprites.size();
                } else {
                    al_draw_bitmap(movementSprites[actualFrame], x, y, 0);
                    animationLimit = movementSprites.size();
                }
                
                digs();
                previousDirection = RIGHT;
                orientation = RIGHT;
                previousAnimation = ALLEGRO_KEY_RIGHT;
                actualFrame++;
                break;
            case ALLEGRO_KEY_LEFT:
                if(x > 0)
                    x -= speed;
                

                if(!checkDigged()){
                    al_draw_bitmap(alternativeSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
                    animationLimit = alternativeSprites.size();
                } else {
                    al_draw_bitmap(movementSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
                    animationLimit = movementSprites.size();
                }
                
                digs();
                previousDirection = LEFT;
                orientation = LEFT;
                previousAnimation = ALLEGRO_KEY_LEFT;
                actualFrame++;
                break;
            case ALLEGRO_KEY_D:
                animationLimit = attackSprites.size();
                if(isArrowCollided()){
                    animationLimit = swallowSprites.size();
                    actualFrame = 0;
                    isSwallowing = true;
                    isSwallowTimerActive = true;
                    al_start_timer(swallowTimer);
                }

                arrowCounter--;
                if(arrowCounter == 0)
                    arrowCounter = 4;
                drawAttack();
                actualFrame++;
                previousAnimation = ALLEGRO_KEY_D;
                if(isArrowColliding()){
                    animationLimit = swallowSprites.size();
                    actualFrame = 0;
                    isSwallowTimerActive = true;
                    al_start_timer(swallowTimer);
                    isSwallowing = true;
                }

                break;
            case ALLEGRO_KEY_S:
                animationLimit = alternativeSprites.size();
                drawAlternative();
                previousAnimation = ALLEGRO_KEY_S;
                actualFrame++;
                break;
            default:
                previousAnimation = ALLEGRO_KEY_SPACE;
                drawIdle();
                break;
        }

        collID = isColliding();
        if(collID != -1 && collID != 0){
            animationLimit = deathSprites.size();
            actualFrame = 0;
            isDying = true;
            died = true;
            lifePoints--;
        }

    } else if(isDying) {

        if(actualFrame >= animationLimit){
            isVisible = false;
        } else {
            drawDying();
            actualFrame++;
        }

    } else if(isSwallowing) {
            
        if(!isArrowFree){
            arrowFree();
            isArrowFree = true;
        }

        if(actualFrame >= animationLimit)
            actualFrame = 0;

        drawSwallowing();

        actualFrame++;

        if(!isSwallowTimerActive){
            isSwallowing = false;
            isArrowFree = false;
            actualFrame = 0;
        }

    }
}