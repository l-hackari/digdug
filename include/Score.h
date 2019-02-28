#ifndef SCORE_H
#define SCORE_H
#include "Text.h"

    class Score : public Text {

        public:
            
            Score(int _id, int _size, ALLEGRO_COLOR _c, int _x, int _y): Text(_id, _size, _c, _x, _y){}
            virtual void drawOnScreen(); 
    
    };

#endif