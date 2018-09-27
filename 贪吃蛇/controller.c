#define _CRT_SECURE_NO_DEPRECATE 1

#include "Model.h"
#include "Windows.h"
#include "stdbool.h"
#include "view.h"
#include "time.h"


static void _Pause()
{
	while (1)
	{
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
	}
}

static Coordinate GetNextCoord(Snake* pSnake)
{
	Coordinate nextCoord = pSnake->head->Coord;
	switch (pSnake->direction)
	{
	case UP:
		nextCoord.y -= 1;
		break;
	case DOWN:
		nextCoord.y += 1;
		break;
	case LEFT:
		nextCoord.x -= 1;
		break;
	case RIGHT:
		nextCoord.x += 1;
		break;
	default:
		break;
	}
	return nextCoord;
}


static bool IsFood(Coordinate nextCord, Coordinate Food)
{
	return nextCord.x == Food.x && nextCord.y == Food.y ? true : false;
}


static bool IsHitWall(int width, int height, Coordinate nextCoord)
{
	if (nextCoord.x<0||nextCoord.x>=width||nextCoord.y<0||nextCoord.y>=height)
	{
		return true;
	}
	return false;
}


static bool IsHitSelf(Snake* pSnake, Coordinate nextCoord)
{
	Node*cur = pSnake->head->next;
	while (cur!=NULL)
	{
		if (cur->Coord.x==nextCoord.x&&cur->Coord.y==nextCoord.y)
		{
			return true;
		}

		cur = cur->next;
	}
	return false;
}



void RunGame()
{
	Game game;
	GameInit(&game);
	ViewInit(game.width, game.height);
	DisplayWall(game.width, game.height);
	DisplaySnake(&game.snake);
	while (1)
	{
		if (GetAsyncKeyState(VK_UP)&&game.snake.direction!=DOWN)
		{
			game.snake.direction = UP;
		}
		else if (GetAsyncKeyState(VK_DOWN) && game.snake.direction != UP)
		{
			game.snake.direction = DOWN;
		}
		else if (GetAsyncKeyState(VK_LEFT) && game.snake.direction != RIGHT)
		{
			game.snake.direction = LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && game.snake.direction != LEFT)
		{
			game.snake.direction = RIGHT;
		}
		else if (GetAsyncKeyState(VK_SPACE))
		{
			_Pause();
		}
		else if (GetAsyncKeyState(VK_ESCAPE)) 
		{
			break;
		}
		else if (GetAsyncKeyState(VK_F1)) 
		{
			game.speed = 100;
		}

		Coordinate nextCoord = GetNextCoord(&game.snake);

		if (IsFood(nextCoord,game.food))
		{
			AddSnakeHead(&game.snake, nextCoord);
			game.score += 10;
			if (game.speed>=100)
			{
				game.speed -= 10;
			}

			DisplayScore(game.score);
			FoodInit(&game.food, game.width, game.height, &game.snake);
		}
		else
		{
			RemoveSnakeTail(&game.snake);
			AddSnakeHead(&game.snake, nextCoord);
		}
		if (IsHitWall(game.width, game.height, nextCoord))
		{
			break;
		}
		if (IsHitSelf(&game.snake,nextCoord))
		{
			break;
		}
		Sleep(game.speed);
	}
	GameDestroy(&game);
}



int main()
{
	srand((unsigned)time(NULL));
	Menu();
	RunGame();
	return 0;
}