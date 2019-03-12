#include "../include/AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(int _id, int _x, int _y, int _width, int _height, ALLEGRO_BITMAP *idl, ALLEGRO_BITMAP *fl, vector<ALLEGRO_BITMAP*> ms, vector<ALLEGRO_BITMAP*> als,vector<ALLEGRO_BITMAP*> ds): StaticSprite(_id, _x, _y, _width, _height, idl), actualFrame(0), flatten(fl), movementSprites(ms), alternativeSprites(als), deathSprites(ds), previousDirection(RIGHT), orientation(RIGHT), isDying(false){}

void AnimatedSprite::drawOnScreen(){}

int AnimatedSprite::isCollided(){

    for(int i = y / 4; i < (y + height) / 4; i++){
        for(int j = x / 4; j < (x + width) / 4; j++){
            if(collisionMap[i][j] != 0 && collisionMap[i][j] != id){
                return collisionMap[i][j];
            }
        }
    }

    for(int i = y / 4; i < (y + height) / 4; i++){
        for(int j = x / 4; j < (x + width) / 4; j++){
            collisionMap[i][j] = 0;
        }
    }

    return 0;
}

int AnimatedSprite::isColliding(){
    for(int i = y / 4; i < (y + height) / 4; i++){
        for(int j = x / 4; j < (x + width) / 4; j++){
            if(collisionMap[i][j] != 0 && collisionMap[i][j] != id){
                return collisionMap[i][j];
            }
        }
    }

    for(int i = y / 4; i < (y + height) / 4; i++){
        for(int j = x / 4; j < (x + width) / 4; j++){
            collisionMap[i][j] = id;
        }
    }

    return 0;
}

