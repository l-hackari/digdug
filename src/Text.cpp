#include "../include/Text.h"

Text::Text(int _size, ALLEGRO_COLOR _c, int _x, int _y): GameObject(_x, _y), font_size(_size), color(_c), font(al_load_font("res/fonts/font.ttf", _size, 0)), text("") {}

Text::Text(int _size, ALLEGRO_COLOR _c, int _x, int _y, string _text): GameObject(_x, _y), font_size(_size), color(_c), font(al_load_font("res/fonts/font.ttf", _size, 0)), text(_text) {}

Text::Text(int _size, ALLEGRO_COLOR _c, int _x, int _y, int _score): GameObject(_x, _y), font_size(_size), color(_c), font(al_load_font("res/fonts/font.ttf", _size, 0)), text(to_string(_score)) {}

void Text::drawOnScreen(){
    al_draw_text(font, color, x, y, ALLEGRO_ALIGN_CENTRE, text.c_str());   
}