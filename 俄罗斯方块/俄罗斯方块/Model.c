#define _CRT_SECURE_NO_DEPRECATE 1

#include "Model.h"
#include "Windows.h"
#include "view.h"

void Init_dia()
{
	for (int i = 0; i < 3; i++)
	{
		//0 1 0 0
		dia[0][0].space[1][i] = 1;  //1 1 1 0
		dia[0][0].space[0][1] = 1;  //0 0 0 0
		//0 0 0 0
	}


	for (int i = 0; i < 3; i++)
	{
		//1 1 1 0
		dia[1][0].space[0][i] = 1;  //1 0 0 0
		dia[1][0].space[1][0] = 1;  //0 0 0 0
		//0 0 0 0
	}

	for (int i = 0; i < 3; i++)
	{
		//1 1 1 0
		dia[2][0].space[0][i] = 1;  //0 0 1 0
		dia[2][0].space[1][2] = 1;  //0 0 0 0
		//0 0 0 0
	}

	for (int i = 0; i < 2; i++)
	{
		//1 1 0 0
		dia[3][0].space[0][i] = 1;          //0 1 1 0
		dia[3][0].space[1][i + 1] = 1;      //0 0 0 0
		//0 0 0 0

		//0 1 1 0
		dia[4][0].space[0][i + 1] = 1;      //1 1 0 0
		dia[4][0].space[1][i] = 1;          //0 0 0 0
		//0 0 0 0

		//1 1 0 0
		dia[5][0].space[0][i] = 1;      //1 1 0 0
		dia[5][0].space[1][i] = 1;      //0 0 0 0
		//0 0 0 0
	}

	for (int i = 0; i < 4; i++)
	{
		//1 1 1 1
		dia[6][0].space[0][i] = 1;      //0 0 0 0
		//0 0 0 0
		//0 0 0 0
	}

	int tmp[4][4];
	for (int i = 0; i < 7; i++)      //方块种类
	{
		for (int j = 0; j < 3; j++)  //旋转次数
		{
			for (int k = 0; k < 4; k++)
			{
				for (int z = 0; z < 4; z++)
				{
					tmp[k][z] = dia[i][j].space[k][z];
				}
			}

			for (int k = 0; k < 4; k++)
			{
				for (int z = 0; z < 4; z++)
				{
					dia[i][j + 1].space[k][z] = tmp[4 - z - 1][k];
				}
			}
		}
	}
}

void GameInit(Game *pGame)
{
	pGame->score = 0;
	pGame->speed = 300;
	display_face(&pGame->face, pGame->maxscore, pGame->score);
}





int color(int c)
{
	switch (c)
	{
	case 0: c = 9; break;
	case 1:
	case 2: c = 12; break;
	case 3:
	case 4: c = 14; break;
	case 5: c = 10; break;
	case 6: c = 13; break;
	default: c = 7; break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}
