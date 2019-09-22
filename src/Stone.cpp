#include "../include/Stone.h"

Stone::Stone(int _x, int _y, int _width, int _height): AnimatedSprite(_x, _y, _width, _height){
    
    id = STONE;
    initStone();
    speed = 8;
    stoneBitMap = al_load_bitmap("res/images/stone/stone1.png");
    alternativeSprites.push_back(al_load_bitmap("res/images/stone/stone2.png"));
    alternativeSprites.push_back(al_load_bitmap("res/images/stone/stone1.png"));
    alternativeSprites.push_back(al_load_bitmap("res/images/stone/stone2.png"));
    deathSprites.push_back(al_load_bitmap("res/images/stone/stone3.png"));
    deathSprites.push_back(al_load_bitmap("res/images/stone/stone4.png"));

}

void Stone::initStone(){
    for(int i = y / collisionCellDivider; i < (y + height) / collisionCellDivider; i++){
        for(int j = x / collisionCellDivider; j < (x + width) / collisionCellDivider; j++){
            groundMap[i][j] = id;
        }
    }
}


bool Stone::isFallen(){
    
    int i = (y+height)/ collisionCellDivider;
    for(int j = x / collisionCellDivider; j < (x + width) / collisionCellDivider; j++){
        if(groundMap[i][j] == 0)
            return false;
        }
    return true;
}

void Stone::drawStoneBreak(){
            if(actualFrame < deathSprites.size()){
                al_draw_bitmap(deathSprites[actualFrame], x, y, 0);
                if(rallenty == 4){
                    actualFrame++;
                    rallenty = 0;
                }
            rallenty++;
            }
        }

void Stone::drawAlternative(){
            
        if(actualFrame < alternativeSprites.size()){
            al_draw_bitmap(alternativeSprites[actualFrame], x, y, 0);
                if(rallenty == 2){
                actualFrame++;
                rallenty = 0;
            }
            rallenty++;
        }
}


void Stone::drawOnScreen(){
    
    if(!isBroken && !drawedDying){
        
        al_draw_bitmap(stoneBitMap, x, y, 0);

    }

    if(isFallen() && !isBroken && !drawedAlternative){

        drawAlternative();
        if(actualFrame == alternativeSprites.size()){
            for(int i = y / collisionCellDivider; i < (y + height) / collisionCellDivider; i++){
                for(int j = x / collisionCellDivider; j < (x + width) / collisionCellDivider; j++){
                    groundMap[i][j] = 0;
                }
            }

            drawedAlternative = true;
        }
            
    }

    else if (isFallen() && !isBroken && drawedAlternative){
        isCollided();
        y+=speed;
    }


    else if(!isFallen() && drawedAlternative && !landed){
        landed = true;
        actualFrame = 0;
    }

    if(landed){
        drawStoneBreak();
        drawedDying = true;
        if(actualFrame == deathSprites.size()){
            isBroken = true;
            isCollided();  
        }
    }

    if(!isBroken && drawedAlternative)
        isColliding();
    else if(landed && !loop && isBroken){
        freeCollisionMap();
        isVisible = false;
        loop = true;
    }
}

