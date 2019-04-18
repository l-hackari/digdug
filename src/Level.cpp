#include "../include/Level.h"

Level::Level(const int &difficulty): dragonsNumber(1 * difficulty), monkeysNumber(2 * difficulty), stonesNumber(3){
    srand(time(NULL));
    gameObjs.push_back(new Player(PLAYER_, 104, 132, 16, 16));
    setPlayerPosition();
    setStonesPosition();
    setDragonsPosition();
    setMonkeysPosition();
}

vector<GameObject *> Level::getGameObjects(){ return gameObjs; }

int Level::getEnemiesNumber(){ return monkeysNumber + dragonsNumber; }
void Level::setStonesPosition(){
    for(int g = 0; g < stonesNumber; g++)
    {
        bool positioned = false;

        while(!positioned){

            int x, y, x_start, x_end, y_start, y_end;
            x = (rand() % 175) + 25; //generates a number from 25 to 179 to respect Map's limits
            y = (rand() % 168) + 64; //generates a number from 64 to 231 to respect Map's limits
            int rem = x % 4;
            if(rem != 0){
                x += 4 - rem;
            }

            rem = y % 4;
            if(rem != 0){
                y += 4 - rem;
            }

            x_start = x;
            x_end = x + 16; //the standard object's weight is 16
            y_start = y;
            y_end = y + 16;

            bool obstacles = false; //if there is an obstacle (another object or excaveted ground)
            for(int i = (y_start / 4) - 1; i <= y_end / 4 && !obstacles; i++)
                for(int j = (x_start / 4) - 1; j <= x_end / 4 && !obstacles; j++)
                    if(groundMap[i][j] == 1 || groundMap[i][j] == STONE)
                        obstacles = true;


            for(int i = y_start / 4; i < y_end / 4 && !obstacles; i++)
                for(int j = x_start / 4; j < x_end / 4 && !obstacles; j++)
                    groundMap[i][j] = STONE;

            if(!obstacles){
                gameObjs.push_back(new Stone(STONE,x, y,16,16));
                positioned = true;
            }
        }
        
    }   
}


void Level::setDragonsPosition(){
    for(int g = 0; g < dragonsNumber; g++)
    {
        bool positioned = false;

        while(!positioned){

            int orientation = rand() % 2; //1 is vertical, 0 is horizontal
            int x, y, x_start, x_end, y_start, y_end;
            
            if(orientation == 1){
                x = rand() % 209; //generates a number from 0 to 208
                y = (rand() % 161) + 64; //generates a number from 64 to 224 to respect Map's limits
                int rem = x % 4;
                if(rem != 0){
                    x += 4 - rem;
                }

                rem = y % 4;
                if(rem != 0){
                    y += 4 - rem;
                }
                x_start = x;
                x_end = x + 16; //the standard object's weight is 16
                y_start = y - 32;
                y_end = y + 32;

            } else {
                y = (rand() % 225) + 32; //generates a number from 32 to 256
                x = (rand() % 161) + 32; //generates a number from 32 to 192
                int rem = x % 4;
                if(rem != 0){
                    x += 4 - rem;
                }

                rem = y % 4;
                if(rem != 0){
                    y += 4 - rem;
                }
                y_start = y;
                y_end = y + 16; //the standard object's height is 16
                x_start = x - 32;
                x_end = x + 32;
            }

            bool obstacles = false; //if there is an obstacle (another object or excaveted ground)

            if(x_start >= 0 && x_end <= 224 && y_start >= 32 && y_end <= 288){
                for(int i = (y_start / 4) - 1; i <=  y_end / 4 && !obstacles; i++)
                    for(int j = (x_start / 4) - 1; j <= x_end / 4 && !obstacles; j++)
                        if(groundMap[i][j] == 1 || groundMap[i][j] == STONE)
                            obstacles = true;

    
                for(int i = y_start / 4; i < y_end / 4 && !obstacles; i++)
                    for(int j = x_start / 4; j < x_end / 4 && !obstacles; j++)
                        groundMap[i][j] = 1;

                if(!obstacles){
                    gameObjs.push_back(new Dragon(DRAGON,x, y,16,16));
                    positioned = true;
                }

            }
        }
        
    }   
}

void Level::setMonkeysPosition(){
    for(int g = 0; g < monkeysNumber; g++)
    {
        bool positioned = false;

        while(!positioned){

            int orientation = rand() % 2; //1 is vertical, 0 is horizontal
            int x, y, x_start, x_end, y_start, y_end;
            
            if(orientation == 1){
                x = rand() % 209; //generates a number from 0 to 208
                y = (rand() % 161) + 64; //generates a number from 64 to 224 to respect Map's limits
                int rem = x % 4;
                if(rem != 0){
                    x += 4 - rem;
                }

                rem = y % 4;
                if(rem != 0){
                    y += 4 - rem;
                }
                x_start = x;
                x_end = x + 16; //the standard object's weight is 16
                y_start = y - 32;
                y_end = y + 32;

            } else {
                y = (rand() % 225) + 32; //generates a number from 32 to 256
                x = (rand() % 161) + 32; //generates a number from 32 to 192
                int rem = x % 4;
                if(rem != 0){
                    x += 4 - rem;
                }

                rem = y % 4;
                if(rem != 0){
                    y += 4 - rem;
                }
                y_start = y;
                y_end = y + 16; //the standard object's height is 16
                x_start = x - 32;
                x_end = x + 32;
            }

            bool obstacles = false; //if there is an obstacle (another object or excaveted ground)

            if(x_start >= 0 && x_end <= 224 && y_start >= 32 && y_end <= 288){
                for(int i = (y_start / 4) - 1; i <= y_end / 4 && !obstacles; i++)
                    for(int j = (x_start / 4) - 1; j <= x_end / 4 && !obstacles; j++)
                        if(groundMap[i][j] == 1 || groundMap[i][j] == STONE)
                            obstacles = true;

    
                for(int i = y_start / 4; i < y_end / 4 && !obstacles; i++)
                    for(int j = x_start / 4; j < x_end / 4 && !obstacles; j++)
                        groundMap[i][j] = 1;

                if(!obstacles){
                    positioned = true;
                    gameObjs.push_back(new Monkey(MONKEY, x, y,16,16));
                }
            }
        }
        
    }
}

void Level::setPlayerPosition(){

    int x_start = (nativeScreenWidth / 2) - 8;
    int x_end = x_start + 16;
    int y_start = 24;
    int y_end = y_start + 124;
    for(int i = y_start / 4; i < y_end / 4; i++)
        for(int j = x_start / 4; j < x_end / 4; j++)
            groundMap[i][j] = 1;

    x_start -= 32;
    x_end = x_start + 16 + 64; //16 is the width of a block
    y_start = y_end - 16;
    for(int i = y_start / 4; i < y_end / 4; i++)
        for(int j = x_start / 4; j < x_end / 4; j++)
            groundMap[i][j] = 1;

}