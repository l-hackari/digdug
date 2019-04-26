#include "../include/AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(int _id, int _x, int _y, int _width, int _height): StaticSprite(_id, _x, _y, _width, _height), actualFrame(0), previousDirection(RIGHT), orientation(RIGHT), isDying(false){}

void AnimatedSprite::drawScoreValue(){

    if(text == nullptr)
        text = new Text(5,10,al_map_rgb(255,255,255),x,y,scoreValue);
    else
        text -> drawOnScreen ();
}

void AnimatedSprite::drawOnScreen(){}


bool AnimatedSprite::itsCrashing(){
    
    int i = (y-1)/4;
    for(int j = x/4; j < (x+width)/4; j++){
        if(collisionMap[i][j] == STONE){
            return true;
        }
    }

    return false;
}


void AnimatedSprite::freeCollisionMap(){
    for(int i = 0; i < 18 * 4; i++){
        for(int j = 0; j < 14 * 4; j++){
            if(collisionMap[i][j] == id)
                collisionMap[i][j] = 0;
        }
    }
}
int AnimatedSprite::isCollided(){

    int collidedID = 0;
    for(int i = y / 4; i < (y + height) / 4; i++){
        for(int j = x / 4; j < (x + width) / 4; j++){
            if(j < 14 * 4 - 1){
                if(collisionMap[i][j] != 0 && collisionMap[i][j] != id){
                    if(collidedID == 0)
                        collidedID = collisionMap[i][j];
                    else if(collisionMap[i][j] == -1)
                        collidedID = collisionMap[i][j];

                }
            }
        }
    }

    for(int i = y / 4; i < (y + height) / 4; i++){
        for(int j = x / 4; j < (x + width) / 4; j++){
            if(j < 14 * 4 - 1)
                collisionMap[i][j] = 0;
        }
    }

    return collidedID;
}

int AnimatedSprite::isColliding(){
    int collidedID = 0;

    for(int i = y / 4; i < (y + height) / 4; i++){
        for(int j = x / 4; j < (x + width) / 4; j++){
            if(j < 14 * 4 - 1){
                if(collisionMap[i][j] != 0 && collisionMap[i][j] != id){
                    if(collidedID == 0)
                        collidedID = collisionMap[i][j];
                    else if(collisionMap[i][j] == -1)
                        collidedID = collisionMap[i][j];
                }
            }
        }
    }

    for(int i = y / 4; i < (y + height) / 4; i++){
        for(int j = x / 4; j < (x + width) / 4; j++){
            if(j < 14 * 4 - 1)
                collisionMap[i][j] = id;
        }
    }

    return collidedID;
}

