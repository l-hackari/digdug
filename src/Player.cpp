#include "../include/Player.h"

Player::Player(int _id, int _x, int _y, int _width, int _height): AnimatedSprite(_id, _x, _y, _width, _height){

    speed = 4;
    /*vector<ALLEGRO_BITMAP*> movementSprites;
    vector<ALLEGRO_BITMAP*> alternativeSprites;
    vector<ALLEGRO_BITMAP*> deathSprites;*/
    
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
    
    if(!isDying){

        if(actualFrame >= animationLimit){
            actualFrame = 0;
        }
        
        if(previousAnimation != actualPressedKey)
            actualFrame = 0;

        if(isCollided()){
            animationLimit = deathSprites.size();
            actualFrame = 0;
            isDying = true;
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
                drawAttack();
                actualFrame++;
                previousAnimation = ALLEGRO_KEY_D;
                break;
            case ALLEGRO_KEY_S:
                animationLimit = alternativeSprites.size();
                drawAlternative();
                previousAnimation = ALLEGRO_KEY_S;
                actualFrame++;
                break;
            default:
                drawIdle();
                break;
        }

        if(isColliding()){
            animationLimit = deathSprites.size();
            actualFrame = 0;
            isDying = true;
            lifePoints--;
        }

    } else {

        if(actualFrame >= animationLimit){
            isVisible = false;
        } else {
            drawDying();
            actualFrame++;
        }

    }
}