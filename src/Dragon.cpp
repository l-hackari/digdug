#include "../include/Dragon.h"

Dragon::Dragon(int _id, int _x, int _y, int _width, int _height): AnimatedSprite(_id, _x, _y, _width, _height){

    speed = 4;
    alternativeMode = false;
    previousDirection = LEFT;
    orientation = LEFT;
    lockedPathCounter = 0;
    initPathMap();
    movementSprites.push_back(al_load_bitmap("../res/images/dragon/run2.png"));
    movementSprites.push_back(al_load_bitmap("../res/images/dragon/run1.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/dragon/de1.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/dragon/de2.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/dragon/de3.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/dragon/de4.png"));
    alternativeSprites.push_back(al_load_bitmap("../res/images/dragon/al1.png"));
    alternativeSprites.push_back(al_load_bitmap("../res/images/dragon/al2.png"));
    attackSprites.push_back(al_load_bitmap("../res/images/dragon/at1.png"));
    attackSprites.push_back(al_load_bitmap("../res/images/dragon/at2.png"));
    flatten = al_load_bitmap("../res/images/dragon/fl.png");
    alternativeFlatten = al_load_bitmap("../res/images/dragon/flal.png");

}

void Dragon::initPathMap(){
    
    for(int i = 0; i < 18 * 4; i++){
        for(int j = 0; j < 14 * 4; j++){
            pathMap[i][j] = 0;
        }
    }
}

void Dragon::drawDying(){

    switch (previousDirection)
    {
        case LEFT:
            al_draw_bitmap(deathSprites[swallowValue / 2], x, y, ALLEGRO_FLIP_HORIZONTAL);
            break;
        case RIGHT:
            al_draw_bitmap(deathSprites[swallowValue / 2], x, y, 0);
            break;
        case UP:
            if(orientation == LEFT)
                al_draw_bitmap(deathSprites[swallowValue / 2], x, y, ALLEGRO_FLIP_HORIZONTAL);
            else
                al_draw_bitmap(deathSprites[swallowValue / 2], x, y, 0);
            break;
        case DOWN:
            if(orientation == LEFT)
                al_draw_bitmap(deathSprites[swallowValue / 2], x, y, ALLEGRO_FLIP_HORIZONTAL);
            else
                al_draw_bitmap(deathSprites[swallowValue / 2], x, y, 0);
            break;
        default:
            break;
    }

}

void Dragon::fillVoidDirections(){
    if(availableDirections.size() == 1){
        if(availableDirections[0] == LEFT){

            availableDirections.push_back(UP);
            availableDirections.push_back(DOWN);

        } else if(availableDirections[0] == RIGHT){

            availableDirections.push_back(UP);
            availableDirections.push_back(DOWN);

        } else if(availableDirections[0] == UP){

            availableDirections.push_back(RIGHT);
            availableDirections.push_back(LEFT);

        } else if(availableDirections[0] == DOWN){

            availableDirections.push_back(RIGHT);
            availableDirections.push_back(LEFT);
        }
        
    } else {
        while(availableDirections.size() < 4){
            if(find(availableDirections.begin(), availableDirections.end(), RIGHT) == availableDirections.end())
                availableDirections.push_back(RIGHT);
            else if(find(availableDirections.begin(), availableDirections.end(), LEFT) == availableDirections.end())
                availableDirections.push_back(LEFT);
            else if(find(availableDirections.begin(), availableDirections.end(), UP) == availableDirections.end())
                availableDirections.push_back(UP);
            else if(find(availableDirections.begin(), availableDirections.end(), DOWN) == availableDirections.end())
                availableDirections.push_back(DOWN);
        }
    }
    
}

void Dragon::nearestDirections(int _x, int _y){

    availableDirections.clear();

    if(playerX == _x){
        if(playerY > _y)
            availableDirections.push_back(DOWN);
        else 
            availableDirections.push_back(UP);

    } else if(playerY == _y){
        if(playerX > _x)
            availableDirections.push_back(RIGHT);
        else 
            availableDirections.push_back(LEFT);

    } else {

        int xDiff = playerX - _x;
        int yDiff = playerY - _y;
        int posXDiff;
        int posYDiff;

        if(xDiff < 0)
            posXDiff = xDiff * (-1);
        else
            posXDiff = xDiff;

        if(yDiff < 0)
            posYDiff = yDiff * (-1);
        else
            posYDiff = yDiff;

        if(posXDiff < posYDiff){
            if(xDiff > 0)
                availableDirections.push_back(RIGHT);
            else
                availableDirections.push_back(LEFT);

            if(yDiff > 0)
                availableDirections.push_back(DOWN);
            else
                availableDirections.push_back(UP);
        } else {
            if(yDiff > 0)
                availableDirections.push_back(DOWN);
            else
                availableDirections.push_back(UP);

            if(xDiff > 0)
               availableDirections.push_back(RIGHT);
            else
                availableDirections.push_back(LEFT);
        }
    }
}

int Dragon::findPath(direction prevDiretion, int _x, int _y, int n){

    for(int i = _y / 4; i < ((_y + height) / 4 ); i++)
        for(int j = _x / 4; j < ((_x + width) / 4); j++)
            if(collisionMap[i][j] == 1)
                return 1;

    nearestDirections(_x, _y);
    fillVoidDirections();

    bool find = false;
    int rCost = INT_MAX;
    int lCost = INT_MAX;
    int uCost = INT_MAX;
    int dCost = INT_MAX;

    for(int i = 0; i < availableDirections.size(); i++){
        if(availableDirections[i] == RIGHT){
            bool rightDir = true;
            if(!find && prevDiretion != LEFT){
                int j = (_x + width) / 4;
                if(j < 14 * 4 && j >= 0){
                    for(int i = _y / 4; i < ((_y + height) / 4) && rightDir && !find; i++){
                        if(!(i >= 6 && i < 68))
                            rightDir = false;
                        else if(pathMap[i][j] == 1)
                            rightDir = false;
                        else if(collisionMap[i][j] == 1)
                            find = true;
                        else if(groundMap[i][j] == 0)
                            rightDir = false;
                    }

                    if(rightDir){
                        for(int i = _y / 4; i < ((_y + height) / 4); i++)
                            pathMap[i][j] = 1;
                        int tCost = findPath(RIGHT,_x + 4, _y, n + 1);
                        if(tCost)
                            rCost = tCost + 1;
                    }
                } 
            }

        } else if(availableDirections[i] == LEFT) {
            bool leftDir = true;
            if(!find && prevDiretion != RIGHT){
                int j = (_x / 4) - 1;
                int gc = 0;
                if(j < 14 * 4 && j >= 0){
                    for(int i = _y / 4; i < ((_y + height) / 4) && leftDir && !find; i++){
                        if(!(i >= 6 && i < 68))
                            leftDir = false;
                        else if(pathMap[i][j] == 1)
                            leftDir = false;
                        else if(collisionMap[i][j] == 1)
                            find = true;
                        else if(groundMap[i][j] == 0)
                            leftDir = false;
                    }

                    if(leftDir){
                        for(int i = _y / 4; i < ((_y + height) / 4); i++)
                            pathMap[i][j] = 1;
                        
                        int tCost = findPath(LEFT, _x - 4, _y, n + 1);
                        if(tCost)
                            lCost = tCost + 1;
                            
                    }

                }
                    
            }
    
        } else if(availableDirections[i] == UP) {
            bool upDir = true;
            if(!find && prevDiretion != DOWN){
                int i = (_y / 4) - 1;
                if(i >= 6 && i < 68){
                    for(int j = _x / 4; j < ((_x + width) / 4) && upDir && !find; j++){
                        if(!(j < 14 * 4 && j >= 0))
                            upDir = false;
                        else if(pathMap[i][j] == 1)
                            upDir = false;
                        else if(collisionMap[i][j] == 1)
                            find = true;
                        else if(groundMap[i][j] == 0)
                            upDir = false;
                    }

                    if(upDir){
                        for(int j = _x / 4; j < ((_x + width) / 4); j++)
                            pathMap[i][j] = 1;
                        int tCost = findPath(UP, _x, _y - 4, n + 1);
                        if(tCost)
                            uCost = tCost + 1;
                    }
                }
            }
        } else if(availableDirections[i] == DOWN) {
            bool downDir = true;
            if(!find && prevDiretion != UP){
                int i = (_y + height) / 4;
                int j;
                if(i >= 6 && i < 68){
                    for(j = _x / 4; j < ((_x + width) / 4 ) && downDir && !find; j++){
                        if(!(j < 14 * 4 && j >= 0))
                            downDir = false;
                        else if(pathMap[i][j] == 1)
                            downDir = false;
                        else if(collisionMap[i][j] == 1)
                            find = true;
                        else if(groundMap[i][j] == 0)
                            downDir = false;
                    }

                    if(downDir){
                        for(j = _x / 4; j < ((_x + width) / 4 ); j++)
                            pathMap[i][j] = 1;
                        int tCost = findPath(DOWN, _x, _y + 4, n + 1);
                        
                        if(tCost)
                            dCost = tCost + 1;
                    }
                }   
            }
        }
    }
    

    if(rCost <= lCost && rCost <= uCost && rCost <= dCost && rCost != INT_MAX){
        previousDirection = RIGHT;
        return rCost;
    } else if(lCost <= rCost && lCost <= uCost && lCost <= dCost && lCost != INT_MAX){
        previousDirection = LEFT;
        return lCost;
    } else if(uCost <= rCost && uCost <= lCost && uCost <= dCost && uCost != INT_MAX){
        previousDirection = UP;
        return uCost;
    } else if(dCost <= rCost && dCost <= lCost && dCost <= uCost && dCost != INT_MAX){
        previousDirection = DOWN;
        return dCost;
    }

    return 0;
    
}

void Dragon::calculateDirection(){

    initPathMap();

    if(findPath(previousDirection, x, y, 0) == 0){
        lockedPathCounter++;
        bool rightDir = true, leftDir = true, upDir = true, downDir = true, chosed = false;
        int j = (x + width) / 4;
        if(j <= 14 * 4){
            for(int i = y / 4; i < ((y + height) / 4 ) && rightDir; i++){
                if(groundMap[i][j] == 0)
                    rightDir = false;
            }
        }

        
        j = (x / 4) - 1;
        if(j >= 0){
            for(int i = y / 4; i < ((y + height) / 4 ) && leftDir; i++){
                if(groundMap[i][j] == 0)
                    leftDir = false;
            }
        }

        
        int i = (y / 4) - 1;
        if(i >= 6){
            for(int j = x / 4; j < ((x + width) / 4 ) && upDir; j++){
                if(groundMap[i][j] == 0)
                    upDir = false;
            }
        }

                
        i = (y + height) / 4;
        if(i >= 6){
            for(int j = x / 4; j < ((x + width) / 4 ) && downDir; j++){
                if(groundMap[i][j] == 0)
                    downDir = false;
            }
        }

        if(previousDirection == LEFT && !leftDir){
            if(upDir)
                previousDirection = UP;
            else if(downDir)
                previousDirection = DOWN;
            else if(rightDir)
                previousDirection = RIGHT;
        } else if(previousDirection == RIGHT && !rightDir){
            if(upDir)
                previousDirection = UP;
            else if(downDir)
                previousDirection = DOWN;
            else if(leftDir)
                previousDirection = LEFT;
        } else if(previousDirection == UP && !upDir){
            if(rightDir)
                previousDirection = RIGHT;
            else if(leftDir)
                previousDirection = LEFT;
            else if(downDir)
                previousDirection = DOWN;
        } else if(previousDirection == DOWN && !downDir){
            if(rightDir)
                previousDirection = RIGHT;
            else if(leftDir)
                previousDirection = LEFT;
            else if(upDir)
                previousDirection = UP;
        }
    }

    if(lockedPathCounter > 30){
        lockedPathCounter = 0;
        alternativeMode = true;
    }
}

void Dragon::drawAlternative(){
    nearestDirections(x, y);
    if(find(availableDirections.begin(), availableDirections.end(), RIGHT) != availableDirections.end()){
            x ++;
            if(find(availableDirections.begin(), availableDirections.end(), UP) != availableDirections.end())
                y--;
            else if(find(availableDirections.begin(), availableDirections.end(), DOWN) != availableDirections.end())
                y++;

            al_draw_bitmap(alternativeSprites[actualFrame], x, y, 0);
            actualFrame++;
            orientation = RIGHT;
            animationLimit = alternativeSprites.size();

    } else if(find(availableDirections.begin(), availableDirections.end(), LEFT) != availableDirections.end()){

            x--;
            if(find(availableDirections.begin(), availableDirections.end(), UP) != availableDirections.end())
                y--;
            else if(find(availableDirections.begin(), availableDirections.end(), DOWN) != availableDirections.end())
                y++;

            al_draw_bitmap(alternativeSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
            actualFrame++;
            orientation = LEFT;
            animationLimit = alternativeSprites.size();

    } else if(find(availableDirections.begin(), availableDirections.end(), DOWN) != availableDirections.end()){

        if(y < 256){
            y++;
        } else {
            previousDirection = UP;
            y--;
        }

        if(orientation == RIGHT)
            al_draw_bitmap(alternativeSprites[actualFrame], x, y, 0);
        else
            al_draw_bitmap(alternativeSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
        
        actualFrame++;
        animationLimit = alternativeSprites.size();

    } else if(find(availableDirections.begin(), availableDirections.end(), UP) != availableDirections.end()){

        if(y > 24){
            y--;
        } else {
            previousDirection = DOWN;
            y ++;
            
        }

        if(orientation == RIGHT)
            al_draw_bitmap(alternativeSprites[actualFrame], x, y, 0);
        else
            al_draw_bitmap(alternativeSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
        
        actualFrame++;
        animationLimit = alternativeSprites.size();
    }

    int count = 0;
    for(int i = y / 4; i < (y + height) / 4; i++){
        for(int j = x / 4; j < (x + width) / 4; j++){
            if(groundMap[i][j] == 1)
                count++;
        }
    }

    if(count == 16){
        alternativeMode = false;
        int rem = static_cast<int>(x) % 4;
        if(rem != 0){
            x += 4 - rem;
        }

        rem = static_cast<int>(y) % 4;
        if(rem != 0){
            y += 4 - rem;
        }
    }
}


void Dragon::drawNormal(){
    calculateDirection();

    if(previousDirection == RIGHT){
        if(x + width < nativeScreenWidth){
            animationLimit = movementSprites.size();
            x += speed;
            al_draw_bitmap(movementSprites[actualFrame], x, y, 0);
            actualFrame++;
            orientation = RIGHT;
        } else {
            previousDirection = LEFT;
            orientation = LEFT;
            animationLimit = movementSprites.size();
            x -= speed;
            al_draw_bitmap(movementSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
            actualFrame++;
        }

    } else if(previousDirection == LEFT){
        if(x > 0){
            animationLimit = movementSprites.size();
            x -= speed;
            al_draw_bitmap(movementSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
            actualFrame++;
            orientation = LEFT;
        } else {
            previousDirection = RIGHT;
            orientation = RIGHT;
            animationLimit = movementSprites.size();
            x += speed;
            al_draw_bitmap(movementSprites[actualFrame], x, y, 0);
            actualFrame++;
        }
        
    } else if(previousDirection == DOWN){
        if(y < 256){
            animationLimit = movementSprites.size();
            y += speed;
            if(orientation == RIGHT)
                al_draw_bitmap(movementSprites[actualFrame], x, y, 0);
            else
                al_draw_bitmap(movementSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
            actualFrame++;
        } else {
            previousDirection = UP;
            animationLimit = movementSprites.size();
            y -= speed;
            if(orientation == RIGHT)
                al_draw_bitmap(movementSprites[actualFrame], x, y, 0);
            else
                al_draw_bitmap(movementSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
            actualFrame++;
        }

    } else if(previousDirection == UP){
        if(y > 24){
            animationLimit = movementSprites.size();
            y -= speed;
            if(orientation == RIGHT)
                al_draw_bitmap(movementSprites[actualFrame], x, y, 0);
            else
                al_draw_bitmap(movementSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
            actualFrame++;
        } else {
            previousDirection = DOWN;
            animationLimit = movementSprites.size();
            y += speed;
            if(orientation == RIGHT)
                al_draw_bitmap(movementSprites[actualFrame], x, y, 0);
            else
                al_draw_bitmap(movementSprites[actualFrame], x, y, ALLEGRO_FLIP_HORIZONTAL);
            actualFrame++;
        }
        
    }
}

void Dragon::drawOnScreen(){

    if(!isDying && !died){

        if(actualFrame >= animationLimit){
            actualFrame = 0;
        }

        if(isCollided() == -1){
            animationLimit = deathSprites.size();
            actualFrame = 0;
            isDying = true;
            isSwallowTimerActive = true;
            al_start_timer(swallowTimer);
        }

        if(alternativeMode)
            drawAlternative();
        else
            drawNormal();
        

        if(isColliding() == -1){
            animationLimit = deathSprites.size();
            actualFrame = 0;
            isDying = true;
            isSwallowTimerActive = true;
            al_start_timer(swallowTimer);
        }

    } else if(isDying) {

        if(swallowValue > 6){
            isVisible = false;
            freeCollisionMap();
        } else {
            if(!isSwallowTimerActive)
                isDying = false;
            else
                drawDying();
        }

    } else if(died){
        if(orientation == RIGHT)
            al_draw_bitmap(movementSprites[0], x, y, 0);
        else
            al_draw_bitmap(movementSprites[0], x, y, ALLEGRO_FLIP_HORIZONTAL);
    }
}