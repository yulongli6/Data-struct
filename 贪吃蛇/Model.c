#define _CRT_SECURE_NO_DEPRECATE 1

#include "Model.h"
#include "stdbool.h"
#include "stdlib.h"
#include "view.h"


void SnakeInit(Snake *pSnake)
{
	pSnake->direction = RIGHT;
	pSnake->head = NULL;

	for (int i = 0; i < 3;i++)
	{
		int x = 3 + i;
		int y = 3;

		Node* node = (Node*)malloc(sizeof(Node));
		node->Coord.x = x;
		node->Coord.y = y;

		node->next = pSnake->head;
		pSnake->head = node;
	}
}


static bool IsOverlapSnake(int x, int y, const Snake *pSnake)
{
	Node* cur = pSnake->head;
	while (cur!=NULL)
	{
		if (cur->Coord.x==x&&cur->Coord.y==y)
		{
			return true;
		}
		cur = cur->next;
	}
	return false;
}


// 生成食物
// 1. 随机
// 2. 不能出框
// 3. 不能和蛇重叠
void FoodInit(Coordinate *pFood, int width, int height, const Snake *pSnake)
{
	int x; int y;
	do 
	{
		x = rand() % width;
		y = rand() % height;
	} while (IsOverlapSnake(x,y,pSnake));

	pFood->x = x;
	pFood->y = y;

	DisplayFood(x, y);
}


void GameInit(Game *pGame)
{
	SnakeInit(&pGame->snake);
	pGame->width = 28;
	pGame->height = 27;
	pGame->speed = 300;
	pGame->score = 0;
	FoodInit(&pGame->food,pGame->width,pGame->height,&pGame->snake);

}


static void SnakeDestroy(Snake *pSnake)
{
	Node* cur = pSnake->head;
	while (cur!=NULL)
	{
		Node* Del = cur;
		cur = cur->next;
		free(Del);
	}
}

void GameDestroy(Game *pGame)
{
	SnakeDestroy(&pGame->snake);
}



void AddSnakeHead(Snake* pSnake,Coordinate nextCoord)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->Coord.x = nextCoord.x;
	node->Coord.y = nextCoord.y;
	node->next = pSnake->head;
	pSnake->head = node;
	DisplaySnakeBlock(nextCoord.x, nextCoord.y);
}


void RemoveSnakeTail(Snake* pSnake)
{
	Node* cur = pSnake->head;
	while (cur->next->next!=NULL)
	{
		cur = cur->next;
	}
	CleanSnakeBlock(cur->next->Coord.x, cur->next->Coord.y);
	free(cur->next);
	
	cur->next = NULL;
}