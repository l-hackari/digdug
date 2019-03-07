#include "AnimatedSprite.h"
class Monkey : public AnimatedSprite{
    
    public:
        Monkey();
        Monkey(int _id, int _x, int _y, int _width, int _height, ALLEGRO_BITMAP *enemy, ALLEGRO_BITMAP *fl, vector<ALLEGRO_BITMAP*> ms, vector<ALLEGRO_BITMAP*> as, vector<ALLEGRO_BITMAP*> als,vector<ALLEGRO_BITMAP*> ds);
        //Player(int _id, int _x, int _y, int _width, int _height, ALLEGRO_BITMAP *idl, ALLEGRO_BITMAP *fl, vector<ALLEGRO_BITMAP*> ms, vector<ALLEGRO_BITMAP*> as, vector<ALLEGRO_BITMAP*> als ,vector<ALLEGRO_BITMAP*> ds, vector<ALLEGRO_BITMAP*> sw);
        
        /*vector<ALLEGRO_BITMAP*> movementSprites;
        vector<ALLEGRO_BITMAP*> alternativeSprites;
        vector<ALLEGRO_BITMAP*> deathSprites;*/
    private:


};