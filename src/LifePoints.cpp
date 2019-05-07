#include "../include/LifePoints.h"

LifePoints::LifePoints(int _x, int _y, int _width, int _height): StaticSprite(_x, _y, _width,_height){
    bitmap = al_load_bitmap("res/images/player/al1.png");
}


void LifePoints::drawOnScreen(){
    for(int i = 0; i < lifePoints; i++){
        al_draw_bitmap(bitmap, x + (i * 16), y, 0);
    }
    
}