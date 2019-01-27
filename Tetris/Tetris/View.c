#define _CRT_SECURE_NO_DEPRECATE 1

#include "Model.h"
#include "Windows.h"
#include "stdio.h"

void SetCurPos(int X, int Y)
{
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	// 标准输入/标准输出/标准错误输出
	COORD coord = { X, Y };
	//设置终端光标位置
	SetConsoleCursorPosition(hStdOutput, coord);
}


void hide_cursor()
{
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hStdOutput, &info);
	info.bVisible = 0;
	SetConsoleCursorInfo(hStdOutput, &info);
}

void dispay_menu()
{
	SetCurPos(27, 14);
	printf("俄罗斯方块");
	SetCurPos(27, 16);
	system("pause");
	system("cls");
}

void display_face(Face* face, int maxscore, int score)
{
	int i, j;
	for (i = 0; i < FACE_Y; i++)
	{
		for (j = 0; j < FACE_X + 10; j++)
		{
			if (j == 0 || j == FACE_X - 1 || j == FACE_X + 9)
			{
				face->data[i][j] = WALL;
				SetCurPos(2 * j, i);
				printf("█");
			}
			else if (i == FACE_Y - 1)
			{
				face->data[i][j] = BOX;
				SetCurPos(2 * j, i);
				printf("█");
			}
			else
			{
				face->data[i][j] = KONG;
			}
		}
	}

	SetCurPos(2 * FACE_X + 2, FACE_Y - 18);
	printf("左移:←");

	SetCurPos(2 * FACE_X + 2, FACE_Y - 16);
	printf("右移:→");

	SetCurPos(2 * FACE_X + 2, FACE_Y - 14);
	printf("旋转:space");

	SetCurPos(2 * FACE_X + 2, FACE_Y - 12);
	printf("暂停: F1");

	SetCurPos(2 * FACE_X + 2, FACE_Y - 10);
	printf("退出: ESC");

	SetCurPos(2 * FACE_X + 2, FACE_Y - 8);
	printf("重新开始: F2");

	SetCurPos(2 * FACE_X + 2, FACE_Y - 6);
	printf("最高记录:%d", maxscore);

	SetCurPos(2 * FACE_X + 2, FACE_Y - 4);
	printf("分数:%d", score);
}


void display_kong(int nn, int space_c, int x, int y, Face face)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			SetCurPos(2 * (x + j), i + y);
			if (dia[nn][space_c].space[i][j] == 1 && face.data[i + y][j + x] != 1)
			{
				printf("  ");
			}
		}
	}
}


display_kong1(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			SetCurPos(2 * (x + j), i + y);
			printf("  ");
		}
	}
}



void display_dia(int nn, int space_c, int x, int y)
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			SetCurPos(2 * (x + j), i + y);
			if (dia[nn][space_c].space[i][j] == 1)
			{
				printf("█");
			}
		}
	}
}



void read_maxscore(int* maxsorse)
{
	FILE* pf;
	pf = fopen("俄罗斯方块记录.txt", "rb");
	if (NULL == pf)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	fread(maxsorse, sizeof(int), 1, pf);

	fclose(pf);
	pf = NULL;
}


void write_maxscore(int* maxsorse)
{
	FILE* pf;
	pf = fopen("俄罗斯方块记录.txt", "wb");
	if (NULL == pf)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
	}

	fwrite(maxsorse, sizeof(int), 1, pf);

	fclose(pf);
	pf = NULL;
}

