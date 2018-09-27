#pragma once

//坐标的结构体
typedef struct Coordinate 
{
	int x;
	int y;
} Coordinate;


//链表的节点结构体
typedef struct Node
{
	Coordinate Coord;
	struct Node* next;
}  Node;


//蛇前进的方向
typedef enum
{
	UP, RIGHT, DOWN, LEFT
} Direction;

//蛇
typedef struct Snake
{
	Node* head;
	Direction direction;
}  Snake;


//游戏元素
typedef struct Game
{
	Snake snake;
	Coordinate food;
	int width;
	int height;
	int	speed;
	int	score;
}  Game;


void GameInit(Game *pGame);
void FoodInit(Coordinate *pFood, int width,
	int height, const Snake *pSnake);
void GameDestroy(Game *pGame);

void AddSnakeHead(Snake* pSnake,Coordinate nextCoord);
void RemoveSnakeTail(Snake* pSnake);