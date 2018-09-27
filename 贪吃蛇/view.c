#define _CRT_SECURE_NO_DEPRECATE 1

#include "Model.h"
#include <Windows.h>
#include <stdio.h>

static void SetCurPos(int X, int Y)
{
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	// 标准输入/标准输出/标准错误输出
	COORD coord = { X, Y };
	//设置终端光标位置
	SetConsoleCursorPosition(hStdOutput, coord);
}

void ViewInit(int width, int height)
{
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hStdOutput, &info);
	info.bVisible = 0;
	SetConsoleCursorInfo(hStdOutput, &info);
}


void DisplayWall(int width, int height)
{
	SetCurPos(0, 0);
	for (int i = 0; i < width + 2; i++)
	{
		printf("█");
	}

	SetCurPos(0, height + 1);
	for (int i = 0; i < width + 2; i++)
	{
		printf("█");
	}


	for (int j = 0; j < height + 2; j++)
	{
		SetCurPos(0, j);
		printf("█");
	}

	for (int j = 0; j < height + 2; j++)
	{
		SetCurPos(2*(width+1), j);
		printf("█");
	}
}


void Menu()
{
	SetCurPos(46, 10);
	printf("※※※贪吃蛇小游戏※※※\n");
	SetCurPos(50, 12);
	system("pause");
	system("cls");
}



void DisplaySnake(const Snake *pSnake)
{
	for (Node* cur = pSnake->head; cur != NULL;cur=cur->next)
	{
		SetCurPos(2*(cur->Coord.x+1), cur->Coord.y+1);
		printf("█");
	}
}

void DisplaySnakeBlock(int x, int y)
{
	SetCurPos(2*(x+1), y+1);	// 先统一两个坐标系
	printf("█");
}


void CleanSnakeBlock(int x, int y)
{
	SetCurPos(2*(x+1), y+1);	// 先统一两个坐标系
	printf("  ");
}


void DisplayFood(int x, int y)
{
	SetCurPos(2 * (x + 1), y+1);
	printf("█");
}


void DisplayScore(int score)
{
	SetCurPos(2 * 30, 20);
	printf("分数:%d", score);
}