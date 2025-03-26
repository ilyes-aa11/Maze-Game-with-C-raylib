#pragma once
#include "Cell.h"
#include "raylib.h"
#include <cmath>
#include "DrawFunctions.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using std::vector , std::pair , std::rand , std::time;


class Maze{
private:
    vector<vector<Cell>> grid;
    Vector2 start;
    Vector2 end;

    bool CheckBaseCase(const Vector2& current,const vector<vector<bool>> visited);
    void DFS(const Vector2& current,const Vector2& _start ,vector<vector<bool>>& visited);

public:
    Maze(int rows , int cols);
    void InitMaze();
    float GetStartX();
    float GetStartY();
    Vector2 GetEnd();

    friend void DrawMaze(const Maze&);
    friend void DrawStart(const Maze& maze);
    friend void DrawEnd(const Maze& maze);
    friend class Player;
};