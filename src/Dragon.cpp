#include "../include/Dragon.h"

Dragon::Dragon(int _id, int _x, int _y, int _width, int _height): AnimatedSprite(_id, _x, _y, _width, _height){

    speed = 4;
    movementSprites.push_back(al_load_bitmap("../res/images/dragon/run2.png"));
    movementSprites.push_back(al_load_bitmap("../res/images/dragon/run1.png"));
    //DA CAMBIARE
    deathSprites.push_back(al_load_bitmap("../res/images/dragon/de1.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/dragon/de2.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/dragon/de3.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/dragon/de4.png"));
    alternativeSprites.push_back(al_load_bitmap("../res/images/dragon/al1.png"));
    alternativeSprites.push_back(al_load_bitmap("../res/images/dragon/al2.png"));
    attackSprites.push_back(al_load_bitmap("../res/images/dragon/at1.png"));
    attackSprites.push_back(al_load_bitmap("../res/images/dragon/at2.png"));

    //AGGIUNGERE FLATTEN

}