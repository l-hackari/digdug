#include "../include/Text.h"



            Text::Text(int size, ALLEGRO_COLOR c, int _x, int _y){ 
                x = _x;
                y = _y;
                font = al_load_font("../res/fonts/font.ttf",size,0);
                color = c;
            }

            Text::Text(int size, ALLEGRO_COLOR c, int _x, int _y,string _text){ 
                x = _x;
                y = _y;
                strcpy(text, _text.c_str());
                font = al_load_font("../res/fonts/font.ttf",size,0);
                color = c;
            }
            
            Text::Text(int size, ALLEGRO_COLOR c, int _x, int _y, int _text){ 
                x = _x;
                y = _y;
                font = al_load_font("../res/fonts/font.ttf",size,0);
                color = c;
                string strScore = to_string(_text);
                strcpy(text,strScore.c_str());
            }

            void Text::drawOnScreen(){
                al_draw_text(font,color,x,y,ALLEGRO_ALIGN_CENTRE,text);   
            }

                //al_draw_text(font,White_color,110,10,ALLEGRO_ALIGN_CENTRE,text);  