#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject {

    public:
        GameObject(): x(0), y(0){}
        GameObject(int _x, int _y): x(_x), y(_y){}
        virtual void drawOnScreen() = 0;

    private:
        int x, y;

};

#endif