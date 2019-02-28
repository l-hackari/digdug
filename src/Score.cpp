#include "../include/Score.h"

void Score::drawOnScreen(){
    al_draw_text(font, color, x, y, ALLEGRO_ALIGN_CENTRE, to_string(score).c_str()); 
}