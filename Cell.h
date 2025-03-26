#pragma once 

struct Cell{
    bool top_wall;
    bool right_wall;
    bool bottom_wall;
    bool left_wall;

    Cell() : top_wall(true) , right_wall(true) , bottom_wall(true) , left_wall(true) {}
};