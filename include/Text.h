#ifndef TEXT_H
#define TEXT_H
#include "Game.h"
#include "AnimatedGameObject.h"
    class Text : public AnimatedGameObject {

        public:
            
            Text(int size, ALLEGRO_COLOR c, int _x, int _y);
            Text(int size, ALLEGRO_COLOR c, int _x, int _y, string _text);
            Text(int size, ALLEGRO_COLOR c, int _x, int _y, int _text);
            virtual void drawOnScreen();

        private:
            
            ALLEGRO_FONT *font;
            ALLEGRO_COLOR color;
            int x, y;
            char text[20] = "";
            int font_size; 
    
    };

#endif