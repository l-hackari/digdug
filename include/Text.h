#ifndef TEXT_H
#define TEXT_H
#include "GameObject.h"

class Text : public GameObject {

    public:
        
        Text(int _size, ALLEGRO_COLOR _c, int _x, int _y);
        Text(int _size, ALLEGRO_COLOR _c, int _x, int _y, string _text);
        Text(int _size, ALLEGRO_COLOR _c, int _x, int _y, int _score);

        //disegna su schermo il testo
        //draws text on screen
        virtual void drawOnScreen();

    protected:
        
        ALLEGRO_FONT *font;
        ALLEGRO_COLOR color;
        string text;
        int font_size; 

};

#endif