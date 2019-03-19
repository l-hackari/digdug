#include "../include/Monkey.h"

Monkey::Monkey(int _id, int _x, int _y, int _width, int _height):AnimatedSprite(_id,_x,_y,_width,_height){
    movementSprites.push_back(al_load_bitmap("../res/images/redenemy/m1.png"));
    movementSprites.push_back(al_load_bitmap("../res/images/redenemy/m2.png"));

    deathSprites.push_back(al_load_bitmap("../res/images/redenemy/de1.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/redenemy/de2.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/redenemy/de3.png"));
    deathSprites.push_back(al_load_bitmap("../res/images/redenemy/de4.png"));

    alternativeSprites.push_back(al_load_bitmap("../res/images/redenemy/al1.png"));
    alternativeSprites.push_back(al_load_bitmap("../res/images/redenemy/al2.png"));

    flatten = al_load_bitmap("../res/images/redenemy/flatten.png");
}

void Monkey::drawMonkey(){
    switch (previousDirection)
    {
        case LEFT:
            al_draw_bitmap(movementSprites[1], x, y, ALLEGRO_FLIP_HORIZONTAL);
            break;
        case RIGHT:
            al_draw_bitmap(movementSprites[1], x, y, 0);
            break;
        case UP:
            if(orientation == LEFT)
                al_draw_rotated_bitmap(movementSprites[1], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, ALLEGRO_FLIP_VERTICAL);
            else
                al_draw_rotated_bitmap(movementSprites[1], width / 2, height / 2, x + (width / 2), y + (height / 2), 4.71239, 0);
            break;
        case DOWN:
            if(orientation == LEFT)
                al_draw_rotated_bitmap(movementSprites[1], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, ALLEGRO_FLIP_VERTICAL);
            else 
                al_draw_rotated_bitmap(movementSprites[1], width / 2, height / 2, x + (width / 2), y + (height / 2), 1.5708, 0);   
            break;
        default:
            break;
    }
}

    void Monkey::drawOnScreen(){
        drawMonkey();
    }
