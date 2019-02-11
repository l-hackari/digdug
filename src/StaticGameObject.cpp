#include "../include/StaticGameObject.h"

void StaticGameObject::drawOnScreen(){
    al_draw_bitmap(bitmap,x,y,0);
    al_flip_display();
}



