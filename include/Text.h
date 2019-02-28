#ifndef TEXT_H
#define TEXT_H
#include "GameObject.h"

    class Text : public GameObject {

        public:
            
            Text(int _id, int _size, ALLEGRO_COLOR _c, int _x, int _y);
            Text(int _id, int _size, ALLEGRO_COLOR _c, int _x, int _y, string _text);
            Text(int _id, int _size, ALLEGRO_COLOR _c, int _x, int _y, int _score);
            virtual void drawOnScreen();

        protected:
            
            ALLEGRO_FONT *font;
            ALLEGRO_COLOR color;
            string text;
            int font_size; 
    
    };

#endif