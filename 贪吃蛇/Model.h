#pragma once

//����Ľṹ��
typedef struct Coordinate 
{
	int x;
	int y;
} Coordinate;


//����Ľڵ�ṹ��
typedef struct Node
{
	Coordinate Coord;
	struct Node* next;
}  Node;


//��ǰ���ķ���
typedef enum
{
	UP, RIGHT, DOWN, LEFT
} Direction;

//��
typedef struct Snake
{
	Node* head;
	Direction direction;
}  Snake;


//��ϷԪ��
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