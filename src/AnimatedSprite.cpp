#include "../include/AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(int _x, int _y, int _width, int _height): StaticSprite(_x, _y, _width, _height), actualFrame(0), previousDirection(RIGHT), orientation(RIGHT), isDying(false){}

void AnimatedSprite::drawScoreValue(){

    if(text == nullptr)
        text = new Text(10,al_map_rgb(255,255,255),x,y,scoreValue);
    else
        text -> drawOnScreen();
}

void AnimatedSprite::drawOnScreen(){}


bool AnimatedSprite::itsCrashing(){
    
    int i = (y / collisionCellDivider) - 1;
    for(int j = x / collisionCellDivider; j < (x + width) / collisionCellDivider; j++){
        if(collisionMap[i][j] == STONE){
            return true;
        }
    }

    return false;
}


void AnimatedSprite::freeCollisionMap(){
    for(int i = 0; i < originalCollisionMapHeight * collisionCellDivider; i++){
        for(int j = 0; j < originalCollisionMapWidth * collisionCellDivider; j++){
            if(collisionMap[i][j] == id)
                collisionMap[i][j] = 0;
        }
    }
}
int AnimatedSprite::isCollided(){

    int collidedID = 0;
    for(int i = y / collisionCellDivider; i < (y + height) / collisionCellDivider; i++){
        for(int j = x / collisionCellDivider; j < (x + width) / collisionCellDivider; j++){
            if(j < originalCollisionMapWidth * collisionCellDivider - 1){
                if(collisionMap[i][j] != 0 && collisionMap[i][j] != id){
                    if(collidedID == 0)
                        collidedID = collisionMap[i][j];
                    else if(collisionMap[i][j] == -1)
                        collidedID = collisionMap[i][j];

                }
            }
        }
    }

    for(int i = y / collisionCellDivider; i < (y + height) / collisionCellDivider; i++){
        for(int j = x / collisionCellDivider; j < (x + width) / collisionCellDivider; j++){
            if(j < originalCollisionMapWidth * collisionCellDivider - 1)
                collisionMap[i][j] = 0;
        }
    }

    return collidedID;
}

int AnimatedSprite::isColliding(){
    int collidedID = 0;

    for(int i = y / collisionCellDivider; i < (y + height) / collisionCellDivider; i++){
        for(int j = x / collisionCellDivider; j < (x + width) / collisionCellDivider; j++){
            if(j < originalCollisionMapWidth * collisionCellDivider - 1){
                if(collisionMap[i][j] != 0 && collisionMap[i][j] != id){
                    if(collidedID == 0)
                        collidedID = collisionMap[i][j];
                    else if(collisionMap[i][j] == -1)
                        collidedID = collisionMap[i][j];
                }
            }
        }
    }

    for(int i = y / collisionCellDivider; i < (y + height) / collisionCellDivider; i++){
        for(int j = x / collisionCellDivider; j < (x + width) / collisionCellDivider; j++){
            if(j < originalCollisionMapWidth * collisionCellDivider - 1)
                collisionMap[i][j] = id;
        }
    }

    return collidedID;
}

AnimatedSprite::~AnimatedSprite(){
    delete text;
}

