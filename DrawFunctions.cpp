#include "DrawFunctions.h"

void DrawMaze(const Maze &maze)
{
    for(int y = 0;y < ROWS;y++) {
        for(int x = 0;x < COLS;x++) {
            if(maze.grid[y][x].top_wall) {
                DrawLine(x * CELLWIDTH , y * CELLHEIGHT , (x + 1) * CELLWIDTH , y * CELLHEIGHT , GREEN);
            }
            if(maze.grid[y][x].bottom_wall) {
                DrawLine(x * CELLWIDTH , (y + 1) * CELLHEIGHT , (x + 1) * CELLWIDTH , (y + 1) * CELLHEIGHT , GREEN);
            }
            if(maze.grid[y][x].right_wall) {
                DrawLine((x + 1) * CELLWIDTH , y * CELLHEIGHT , (x + 1) * CELLWIDTH , (y + 1) * CELLHEIGHT , GREEN);
            }
            if(maze.grid[y][x].left_wall) {
                DrawLine(x * CELLWIDTH , y * CELLHEIGHT , x * CELLWIDTH , (y + 1) * CELLHEIGHT , GREEN);
            } 
        }
    }
}

void DrawStart(const Maze &maze)
{
    DrawCircleLines(maze.start.x * CELLWIDTH + CELLWIDTH / 2 , maze.start.y * CELLHEIGHT + CELLHEIGHT / 2 , std::min(CELLHEIGHT,CELLWIDTH) / 4 , BLUE);
}

void DrawEnd(const Maze &maze)
{
    DrawCircleLines(maze.end.x * CELLWIDTH + CELLWIDTH / 2, maze.end.y * CELLHEIGHT + CELLHEIGHT / 2, std::min(CELLHEIGHT,CELLWIDTH) / 4 , RED);
}

void DrawPlayer(const Player& player)
{
    DrawCircle(player.x * CELLWIDTH, player.y * CELLHEIGHT, player.radius , YELLOW);
}
