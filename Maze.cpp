#include "Maze.h"

bool Maze::CheckBaseCase(const Vector2 &current, const vector<vector<bool>> visited)
{
    if((current.y + 1 >= visited.size() || visited[current.y+1][current.x]) && (current.y - 1 < 0 || visited[current.y-1][current.x])
        && (current.x + 1 >= visited[0].size() || visited[current.y][current.x+1]) && (current.x - 1 < 0 || visited[current.y][current.x-1])) {
            return true;
        } 

    return false;
}

void Maze::DFS(const Vector2 &current, const Vector2 &_start, vector<vector<bool>> &visited)
{
    visited[current.y][current.x] = true;
    // base case all neighbours are visited
    if(CheckBaseCase(current , visited)) return;
    


    /*
    Directions:
    0: up   1: right    2: down     3: left
    */

    
    bool base; 
    do {
        base = CheckBaseCase(current , visited);
        int dir = rand() % 4;
        switch(dir) {
            case 0:
                if(current.y - 1 >= 0 && !visited[current.y-1][current.x]) {
                    grid[current.y][current.x].top_wall = false;
                    grid[current.y-1][current.x].bottom_wall = false;
                    DFS({current.x , current.y-1} , _start , visited);
                }
                break;

            case 1:
                if(current.x + 1 < visited[0].size() && !visited[current.y][current.x+1]) {
                    grid[current.y][current.x].right_wall = false;
                    grid[current.y][current.x+1].left_wall = false;
                    DFS({current.x+1 , current.y} , _start , visited);
                }
                break;

            case 2:
                if(current.y + 1 < visited.size() && !visited[current.y+1][current.x]) {
                    grid[current.y][current.x].bottom_wall = false;
                    grid[current.y+1][current.x].top_wall = false;
                    DFS({current.x , current.y+1} , _start , visited);
                }
                break;

            case 3:
                if(current.x - 1 >= 0 && !visited[current.y][current.x-1]) {
                    grid[current.y][current.x].left_wall = false;
                    grid[current.y][current.x-1].right_wall = false;
                    DFS({current.x-1 , current.y} , _start , visited);
                }
                break;
        }
    }while(!base);

}

Maze::Maze(int rows, int cols) : grid(rows, vector<Cell>(cols , Cell())) 
{
}

void Maze::InitMaze()
{
    const int rows = grid.size() , cols = grid[0].size();
    Vector2 _start = {rand()%20,rand()%20};
    Vector2 _end;
    do{
        _end = {float(rand() % 20),float(rand() % 20)};
    }while(sqrt(pow(_end.x - _start.x , 2) + pow(_end.y - _start.y , 2)) < 6.0); 
    vector<vector<bool>> visited(rows , vector<bool>(cols, false));
    DFS(_start , _start, visited);

    this->start = _start;
    this->end = _end;
}

float Maze::GetStartX()
{
    return start.x;
}

float Maze::GetStartY()
{
    return start.y;
}

Vector2 Maze::GetEnd()
{
    return end;
}
