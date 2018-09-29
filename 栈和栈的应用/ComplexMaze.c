#define _CRT_SECURE_NO_DEPRECATE 1

#include "Windows.h"
#include "stdio.h"

typedef struct
{
	int x;
	int y;
}position;

#include "stack.h"

#define ROWS (6)
#define COLS (6)

int g_maze[ROWS][COLS] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 }
};



void PrintMaze()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (g_maze[i][j] == 1)
			{
				printf("  ");
			}
			else if (g_maze[i][j] == 0)
			{
				printf("■");
			}
			else if (g_maze[i][j] == 2) {
				printf("⊙");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
}


int IsExit(position pos)
{
	if (pos.y == COLS - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



int CanPass(position pos)
{
	// 先判断是否越界
	if (pos.x < 0 || pos.x >= ROWS) {
		return 0;
	}

	if (pos.y < 0 || pos.y >= COLS) {
		return 0;
	}

	// 再判断是否是路
	if (g_maze[pos.x][pos.y] == 1)
	{
		return 1;
	}
	else {
		return 0;
	}
}

void GoMaze(position entry)
{
	Stack stack;

	StackInit(&stack);
	position pos = entry;
	position nextpos;

	while (1)
	{
		g_maze[pos.x][pos.y] = 2;//走过的路标记为2

		system("cls");
		PrintMaze();
		Sleep(300);

		StackPush(&stack, pos);

		if (IsExit(pos))
		{
			printf("找到出口\n");
			return;
		}


		nextpos = pos;
		nextpos.y--;
		if (CanPass(nextpos))
		{
			pos = nextpos;
			continue;
		}

		nextpos = pos;
		nextpos.x -= 1;
		if (CanPass(nextpos)) {
			pos = nextpos;
			continue;
		}

		nextpos = pos;
		nextpos.y += 1;
		if (CanPass(nextpos)) {
			pos = nextpos;
			continue;
		}

		nextpos = pos;
		nextpos.x += 1;
		if (CanPass(nextpos)) {
			pos = nextpos;
			continue;
		}


		g_maze[pos.x][pos.y] = 3;
		pos = StackTop(&stack);
		StackPop(&stack);
		if (StackEmpty(&stack))
		{
			printf("结束\n");
			return;
		}
		pos = StackTop(&stack);
		StackPop(&stack);
	}

}


int  main()
{
	position entry = { 5, 2 };
	GoMaze(entry);
	return 0;
}


