#pragma once
#include "raylib.h"
#include "Maze.h"
#include "DrawFunctions.h"
#include <cmath>

class Maze;

class Player{
private:
    float x;
    float y;
    float speed;
    float radius;

public:
    Player(float,float,float,float);
    void MoveUp(const Maze& maze , float dt);
    void MoveDown(const Maze& maze , float dt);
    void MoveRight(const Maze& maze , float dt);
    void MoveLeft(const Maze& maze , float dt);
    float GetX();
    float GetY();
    bool EndCheck(const Vector2& end);

    friend void DrawPlayer(const Player&);
};
