#pragma once

#include "Model.h"

void DisplaySnake(const Snake *pSnake);
void DisplaySnakeBlock(int x, int y);
void CleanSnakeBlock(int x, int y);
void ViewInit(int width, int height);
void DisplayWall(int width, int height);
void DisplayFood(int x, int y);
void DisplayScore(int score);
