#ifndef NODE_H
#define NODE_H
#include "GameTools.h"

class Node
{
    private:
        int x;
        int y;
        direction firstChooseDirection;
    public:
        Node(int x, int y, direction firstChooseDirection)
        {
            this->x = x;
            this->y = y;
            this->firstChooseDirection = firstChooseDirection;
        }

        int getX(){
            return x;
        }

        int getY(){
            return y;
        }

        void setFirstChooseDirection(direction firstChooseDirection){
            this->firstChooseDirection = firstChooseDirection;
        }

        void setX(int x){
            this->x =  x;
        }

        void setY(int y){
            this->y =  y;
        }

        direction getFirstChooseDirection(){
            return firstChooseDirection;
        }

        bool operator==(const Node &n){
            return x == n.x && y == n.y;
        }
        
};

#endif