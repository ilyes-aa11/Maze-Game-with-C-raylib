#pragma once

#include "Player.h"
#include "Macros.h"

class Player;

class Maze;
void DrawMaze(const Maze& maze);
void DrawStart(const Maze& maze);
void DrawEnd(const Maze& maze);
void DrawPlayer(const Player& player);