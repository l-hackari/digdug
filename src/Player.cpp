#include "../include/Player.h"

Player::Player(int _id, int _x, int _y, int _width, int _height): AnimatedSprite(_id, _x, _y, _width, _height){
    speed = 4;
    flatten = al_load_bitmap("../res/images/player/fl.png");
    varrow = al_load_bitmap("../res/images/arrow/varrow.png");
    harrow = al_load_bitmap("../res/images/arrow/harrow.png");
    movementSprites.push_back(al_load_bitmap("../res/images/player/run2.png"));
    movementSprites.push_back(al_load_bitmap("../res/images/player/run1.png"));
    swallowSprites.push_back(al_load_bitmap("../res/images/player/sw1.png"));
    swallowSprites.push_back(al_load_bitmap("../res/images/player/sw2.png")); 
    deathSprites.push_back(al_load_bitmap("../res/images/player/dei.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/player/de1.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/player/de2.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/player/de3.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/player/de4.png"));
    alternativeSprites.push_back(al_load_bitmap("../res/images/player/al1.png"));
    alternativeSprites.push_back(al_load_bitmap("../res/images/player/al2.png"));
    attackSprites.push_back(al_load_bitmap("../res/images/player/at.png"));
}


void Player::possibleDirection(){
    bool isDirection = true;
    possibleDirections.clear();

    for(int i = (y/4);  i < (y+height)/4; i++){
        int j = (x + width) / 4;
        if(groundMap[i][j] == STONE){
            isDirection = false;
        }
    }

    if(isDirection)
        possibleDirections.push_back(RIGHT);
    else
        isDirection = true;


    for(int i = (y/4);  i < (y+height)/4; i++){
        int j = (x / 4) - 1;
        if(groundMap[i][j] == STONE)
            isDirection = false;
    }

    if(isDirection)
        possibleDirections.push_back(LEFT);
    else
        isDirection = true;


    for(int j = x/4;  j < (x+width)/4; j++){
        int i = (y + height)/4;  
        if(groundMap[i][j] == STONE)
            isDirection = false;
    }

    if(isDirection)
        possibleDirections.push_back(DOWN);
    else
        isDirection = true;


    for(int j = x/4;  j < (x+width)/4; j++){
        int i = (y / 4) - 1;  
        if(groundMap[i][j] == STONE)
            isDirection = false;
    }

    if(isDirection)
        possibleDirections.push_back(UP);
    else
        isDirection = true;
        
}


int Player::isArrowColliding(){
    int collidedID = 0;
    if(previousDirection == LEFT || previousDirection == RIGHT){

        int i = (((arrowY + arrowHeight) / 4) - 1) - (((arrowHeight / 4)) / 2);
        for(int j = arrowX / 4; j < (arrowX + arrowWidth) / 4; j++){
            if(j > 0 && j < 14 * 4 - 1){
                if(collisionMap[i][j] != 0 && collisionMap[i][j] != -1 && collisionMap[i][j] != STONE && groundMap[i][j] == 1){
                    collidedID = collisionMap[i][j];
                }
            } 
        }

        for(int j = arrowX / 4; j < (arrowX + arrowWidth) / 4; j++){
            if(j > 0 && j < 14 * 4 - 1 && groundMap[i][j] == 1){
                collisionMap[i][j] = -1;
            }
        }
    } else {

        int j = (((arrowX + arrowWidth) / 4) - 1) - (((arrowWidth / 4)) / 2);
        for(int i = arrowY / 4; i < (arrowY + arrowHeight) / 4; i++){
            if(i >= 6){
                if(collisionMap[i][j] != 0 && collisionMap[i][j] != -1 && collisionMap[i][j] != STONE && groundMap[i][j] == 1){
                    collidedID = collisionMap[i][j];
                }
            }
        }

        for(int i = arrowY / 4; i < (arrowY + arrowHeight) / 4; i++){
            if(i >= 6 && groundMap[i][j] == 1){
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
                if(collisionMap[i][j] != 0 && collisionMap[i][j] != -1 && collisionMap[i][j] != STONE && groundMap[i][j] == 1){
                    collidedID = collisionMap[i][j];
                }
            }
        }

        for(int j = arrowX / 4; j < (arrowX + arrowWidth) / 4; j++){
            if(j > 0 && j < 14 * 4 - 1 && groundMap[i][j] == 1){
                collisionMap[i][j] = 0;
            }
        }
    } else {

        int j = (((arrowX + arrowWidth) / 4) - 1) - (((arrowWidth / 4)) / 2);
        for(int i = arrowY / 4; i < (arrowY + arrowHeight) / 4; i++){
            if(i >= 6 && groundMap[i][j] == 1){
                if(collisionMap[i][j] != 0 && collisionMap[i][j] != STONE && collisionMap[i][j] != -1 && groundMap[i][j] == 1){
                    collidedID = collisionMap[i][j];
                }
            }
        }

        for(int i = arrowY / 4; i < (arrowY + arrowHeight) / 4; i++){
            if(i >= 6 && groundMap[i][j] == 1){
                collisionMap[i][j] = 0;
            }
        }
    }

    return collidedID;

}

void Player::arrowFree(){

    for(int i = 0; i < 18 * 4; i++){
        for(int j = 0; j < 14 * 4; j++){
            if(collisionMap[i][j] == -1)
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

void Player::drawArrow(){      
    switch (previousDirection)
    {
        case LEFT:
            arrowWidth = 32 / arrowCounter;
            arrowHeight = 16;
            arrowX = x - arrowWidth;
            arrowY = y;
            al_draw_bitmap_region(harrow, 32 - arrowWidth, 0, arrowWidth, arrowHeight, arrowX, arrowY, ALLEGRO_FLIP_HORIZONTAL);
            break;
        case RIGHT:
            arrowWidth = 32 / arrowCounter;
            arrowHeight = 16;
            arrowX = x + width;
            arrowY = y;
            al_draw_bitmap_region(harrow, 32 - arrowWidth, 0, arrowWidth, arrowHeight, arrowX, arrowY, 0);
            break;
        case UP:
            arrowWidth = 16;
            arrowHeight = 32 / arrowCounter;
            arrowX = x;
            arrowY = y - arrowHeight;
            al_draw_bitmap_region(varrow, 0, 0, arrowWidth, arrowHeight, arrowX, arrowY, 0);
            break;
        case DOWN:
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

void Player::drawAttack(){

    drawArrow();

    if(arrowCounter == 4){
        isBackgroundAudioOn = false;
        al_stop_sample(&ret);
        al_play_sample(audios[ATTACK], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &ret);
    }

    switch (previousDirection)
    {
        case LEFT:
            al_draw_bitmap(attackSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
            break;
        case RIGHT:
            al_draw_bitmap(attackSprites[actualFrame], x, y, 0);
            break;
        case UP:
            if(orientation == LEFT)
                al_draw_rotated_bitmap(attackSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, ALLEGRO_FLIP_VERTICAL);
            else
                al_draw_rotated_bitmap(attackSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
            break;
        case DOWN:
            if(orientation == LEFT)
                al_draw_rotated_bitmap(attackSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, ALLEGRO_FLIP_VERTICAL);
            else
                al_draw_rotated_bitmap(attackSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, 0);
            
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

    if(!isDying && !isSwallowing && !isFlatten){

        if(actualFrame >= animationLimit){
            actualFrame = 0;
        }
        
        if(previousAnimation != actualPressedKey){
            actualFrame = 0;
            if(!isBackgroundAudioOn){
                al_stop_sample(&ret);
                al_play_sample(audios[BACKGROUND_SOUND], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &ret);
                isBackgroundAudioOn = true;
            }

            if(previousAnimation == ALLEGRO_KEY_D)
                arrowFree();
            
            arrowCounter = 4;  
        }
    
        int collID = isCollided();
        if(itsCrashing() && !isFlatten){
            isFlatten = true;
            animationLimit = deathSprites.size();
            actualFrame = 0;
            died = true;
            al_stop_sample(&ret);
            al_play_sample(audios[MONSTER_TOUCHED], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &ret);
            return;
        } else if(collID != -1 && collID != 0 && collID != STONE){
            animationLimit = deathSprites.size();
            actualFrame = 0;
            isDying = true;
            died = true;
            drawDying();
            actualFrame++;
            al_stop_sample(&ret);
            al_play_sample(audios[MONSTER_TOUCHED], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &ret);
            return;
        }

        switch (actualPressedKey)
        {
            case ALLEGRO_KEY_UP:
                if(y > 24){
                    possibleDirection();
                    if(find(possibleDirections.begin(), possibleDirections.end(), UP) != possibleDirections.end())
                        y -= speed;
                }
                
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
                if(y < 256){
                    possibleDirection();
                    if(find(possibleDirections.begin(), possibleDirections.end(), DOWN) != possibleDirections.end())
                        y += speed;
                }
                
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
                if(x + width < nativeScreenWidth){
                    possibleDirection();
                    if(find(possibleDirections.begin(), possibleDirections.end(), RIGHT) != possibleDirections.end())
                        x += speed;
                }
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
                if(x > 0){
                    possibleDirection();
                    if(find(possibleDirections.begin(), possibleDirections.end(), LEFT) != possibleDirections.end())
                        x -= speed;
                }
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

                drawAttack();
                arrowCounter--;
                if(arrowCounter == 0)
                    arrowCounter = 4;
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
            default:
                previousAnimation = ALLEGRO_KEY_SPACE;
                drawIdle();
                break;
        }

            if(itsCrashing() && !isFlatten){
                isFlatten = true;
                animationLimit = deathSprites.size();
                cerr << animationLimit << " ";
                actualFrame = 0;
                died = true;
                al_stop_sample(&ret);
                al_play_sample(audios[MONSTER_TOUCHED], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &ret);
            } else {
                collID = isColliding();
                if(collID != -1 && collID != 0&& collID != STONE){
                animationLimit = deathSprites.size();
                actualFrame = 0;
                isDying = true;
                died = true;
                drawDying();
                actualFrame++;
                al_stop_sample(&ret);
                al_play_sample(audios[MONSTER_TOUCHED], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &ret);
            }
        }

    } else if(isDying && !isFlatten) {

        if(isBackgroundAudioOn)
            al_rest(1.0);
        
        if(actualFrame >= animationLimit){
            lifePoints--;
            isVisible = false;
            isDying = false;
            isFlatten = false;
            isSwallowing = false;
            isBackgroundAudioOn = true;
        } else {
            drawDying();
            actualFrame++;
            if(isBackgroundAudioOn){
                isBackgroundAudioOn = false;
                al_stop_sample(&ret);
                al_play_sample(audios[DIED], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &ret);
            }
        }

    } else if(!isDying && isFlatten){

        if(rallenty < 16){
            al_draw_bitmap(flatten,x,y,0);
            rallenty++;
        } else {
            isFlatten = false;
            isDying = true;
            rallenty = 0;
            actualFrame = 0;
            drawDying();
            actualFrame++;
        }
        
    } else if(isSwallowing) {
            
        if(!isArrowFree){
            arrowFree();
            isArrowFree = true;
        }

        int collID = isCollided();
        if(collID != -1 && collID != 0 && collID != STONE){
            animationLimit = deathSprites.size();
            actualFrame = 0;
            isDying = true;
            died = true;
            isSwallowing = false;
            drawDying();
            actualFrame++;
            al_stop_sample(&ret);
            al_play_sample(audios[MONSTER_TOUCHED], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &ret);
            isBackgroundAudioOn = true;

        } else {

            if(actualFrame >= animationLimit){
                isBackgroundAudioOn = false;
                al_stop_sample(&ret);
                al_play_sample(audios[SWALLOW], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &ret);
                actualFrame = 0;
            }

            drawArrow();
            drawSwallowing();

            actualFrame++;

            if(!isSwallowTimerActive){
                isSwallowing = false;
                isArrowFree = false;
                actualFrame = 0;
                arrowCounter = 4;
                isBackgroundAudioOn = true;
                al_stop_sample(&ret);
                al_play_sample(audios[BACKGROUND_SOUND], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &ret);
            }

            if(actualPressedKey != ALLEGRO_KEY_D && actualPressedKey != ALLEGRO_KEY_ESCAPE){
                isSwallowing = false;
                isArrowFree = false;
                actualFrame = 0;
                arrowCounter = 4;
                isBackgroundAudioOn = true;
                al_stop_sample(&ret);
                al_play_sample(audios[BACKGROUND_SOUND], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &ret);
            }

        }

    }
}