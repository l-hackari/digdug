#include "../include/AnimatedGameObject.h"

AnimatedGameObject::AnimatedGameObject(int _id, int _x, int _y, int _width, int _height, ALLEGRO_BITMAP *fl, vector<ALLEGRO_BITMAP*> ms, vector<ALLEGRO_BITMAP*> as, vector<ALLEGRO_BITMAP*> als,vector<ALLEGRO_BITMAP*> ds): GameObject(_id, _x, _y, _width, _height), actualFrame(0), flatten(fl), attackSprites(as), movementSprites(ms), alternativeSprites(als), deathSprites(ds), previousDirection(RIGHT){}

void AnimatedGameObject::drawOnScreen(){

}