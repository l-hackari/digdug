#include "../include/AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(int _id, int _x, int _y, int _width, int _height, ALLEGRO_BITMAP *idl, ALLEGRO_BITMAP *fl, vector<ALLEGRO_BITMAP*> ms, vector<ALLEGRO_BITMAP*> as, vector<ALLEGRO_BITMAP*> als,vector<ALLEGRO_BITMAP*> ds): StaticSprite(_id, _x, _y, _width, _height, idl), actualFrame(0), flatten(fl), attackSprites(as), movementSprites(ms), alternativeSprites(als), deathSprites(ds), previousDirection(RIGHT){}

void AnimatedSprite::drawOnScreen(){

}