#include "../include/Player.h"

Player::Player(int _id, int _x, int _y, int _width, int _height, ALLEGRO_BITMAP *idl, ALLEGRO_BITMAP *fl, ALLEGRO_BITMAP *di, vector<ALLEGRO_BITMAP*> ms, vector<ALLEGRO_BITMAP*> as, vector<ALLEGRO_BITMAP*> als ,vector<ALLEGRO_BITMAP*> ds, vector<ALLEGRO_BITMAP*> sw): AnimatedSprite(_id, _x, _y, _width, _height, idl, fl, ms, as, als, ds), deathIdle(di), swallowSprites(sw){
    actualFrame = 0;
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
            al_draw_rotated_bitmap(movementSprites[1], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
            break;
        case DOWN:
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
            al_draw_rotated_bitmap(attackSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
            break;
        case DOWN:
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
            al_draw_rotated_bitmap(alternativeSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
            break;
        case DOWN:
            al_draw_rotated_bitmap(alternativeSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, 0);
            break;
        default:
            break;
    }

}

void Player::drawOnScreen(){

    if(actualFrame >= animationLimit){
        actualFrame = 0;
    }
    
    if(previousAnimation != actualPressedKey)
        actualFrame = 0;

    for(int i = x / 4; i < (x + width) / 4; i++){
        for(int j = y / 4; j < (y + height) / 4; j++){
            gameMap[i][j] = 0;
        }
    }

    switch (actualPressedKey)
    {
        case ALLEGRO_KEY_UP: 
            y -= 4;
            al_draw_rotated_bitmap(movementSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
            animationLimit = movementSprites.size();
            previousDirection = UP;
            previousAnimation = ALLEGRO_KEY_UP;
            actualFrame++;
            break;
        case ALLEGRO_KEY_DOWN:
            y += 4;
            al_draw_rotated_bitmap(movementSprites[actualFrame], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, 0);
            animationLimit = movementSprites.size();
            previousDirection = DOWN;
            previousAnimation = ALLEGRO_KEY_DOWN;
            actualFrame++;
            break;
        case ALLEGRO_KEY_RIGHT:
            x += 4;
            al_draw_bitmap(movementSprites[actualFrame], x, y, 0);
            animationLimit = movementSprites.size();
            previousDirection = RIGHT;
            previousAnimation = ALLEGRO_KEY_RIGHT;
            actualFrame++;
            break;
        case ALLEGRO_KEY_LEFT:
            x -= 4;
            al_draw_bitmap(movementSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
            animationLimit = movementSprites.size();
            previousDirection = LEFT;
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

    for(int i = x / 4; i < (x + width) / 4; i++){
        for(int j = y / 4; j < (y + height) / 4; j++){
            gameMap[i][j] = id;
        }
    }
}