#include "Player.h"

Player::Player(float _x , float _y , float _speed, float _radius)
    : x(_x), y(_y), speed(_speed), radius(_radius)
{
}


void Player::MoveUp(const Maze &maze, float dt) {
    int cellx = floor(x);
    int celly = floor(y);
    if(maze.grid[celly][cellx].top_wall && y - 0.25 - speed*dt < float(celly)) y = celly + 0.25;
    
    else y -= speed * dt;
}

void Player::MoveDown(const Maze &maze, float dt) {
    int cellx = floor(x);
    int celly = floor(y);
    if(maze.grid[celly][cellx].bottom_wall && y + 0.25 + speed*dt > float(celly+1)) y = celly+1 - 0.25;
    
    else y += speed * dt;
}

void Player::MoveRight(const Maze &maze, float dt) {
    int cellx = floor(x);
    int celly = floor(y);
    if(maze.grid[celly][cellx].right_wall && x + 0.25 + speed*dt > float(cellx+1)) x = cellx+1 - 0.25;
    
    else x += speed * dt;
}

void Player::MoveLeft(const Maze &maze, float dt) {
    int cellx = floor(x);
    int celly = floor(y);
    if(maze.grid[celly][cellx].left_wall && x - 0.25 - speed*dt < float(cellx)) x = cellx + 0.25;
    
    else x -= speed * dt;
}

float Player::GetX()
{
    return x;
}

float Player::GetY()
{
    return y;
}

bool Player::EndCheck(const Vector2 &end)
{
    return floor(x) == end.x && floor(y) == end.y;
}

void Player::PrintCoordinates()
{
    std::cout << x << " : " << y << std::endl;
}
