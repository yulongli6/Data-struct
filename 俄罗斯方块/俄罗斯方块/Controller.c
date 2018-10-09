#define _CRT_SECURE_NO_DEPRECATE 1

#include "Model.h"
#include "view.h"
#include "Windows.h"
#include "time.h"
#include "stdio.h"

static void _Pause()
{
	while (1)
	{
		Sleep(300);
		if (GetAsyncKeyState(VK_F1))
		{
			break;
		}
	}
}


int pd_wall(Face* face, int nn, int space_c, int x, int y)   //判断是否到底
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (dia[nn][space_c].space[i][j] == 0)
				continue;
			else if (face->data[y + i][x + j] == WALL || face->data[y + i][x + j] == BOX)
				return 0;
		}
	}
	return 1;
}


void go_game(Game* pGame, int nn)
{
	int x = FACE_X / 2 - 2;
	int y = 0;
	int space_c = 0; //旋转次数
	display_kong1(nn, space_c, FACE_X + 3, 4);
	nn = rand() % 7;
	color(nn);
	display_dia(nn, space_c, FACE_X + 3, 4);
	while (1)
	{
		color(nn);
		display_dia(nn, space_c, x, y);
		Sleep(pGame->speed);


		if (pd_wall(&pGame->face, nn, space_c, x - 1, y + 1) == 1 && GetAsyncKeyState(VK_LEFT))
		{
			display_kong(nn, space_c, x, y);
			x--;
		}
		else if (pd_wall(&pGame->face, nn, space_c, x + 1, y + 1) == 1 && GetAsyncKeyState(VK_RIGHT))
		{
			display_kong(nn, space_c, x, y);
			x++;
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			pGame->speed = 50;
		}
		else if (GetAsyncKeyState(VK_UP))
		{
			pGame->speed = 300;
		}
		else if (pd_wall(&pGame->face, nn, (space_c + 1) % 4, x + 1, y) == 1 && GetAsyncKeyState(VK_SPACE))
		{
			display_kong(nn, space_c, x, y);
			space_c = (space_c + 1) % 4;
		}

		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			system("cls");
			SetCurPos(FACE_X, FACE_Y / 2);
			printf("---游戏结束!---\n\n");
			SetCurPos(FACE_X, FACE_Y / 2 + 2);
			exit(0);
		}

		else if (GetAsyncKeyState(VK_F1))
		{
			_Pause();
		}

		else if (GetAsyncKeyState(VK_F2))
		{
			main();
			exit(0);
		}


		if (pd_wall(&pGame->face, nn, space_c, x, y + 1) == 1)
		{
			display_kong(nn, space_c, x, y);
			y++;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (dia[nn][space_c].space[i][j] == 1)
					{
						pGame->face.data[y + i][x + j] = BOX;
						pGame->face.color[y + i][x + j] = nn;
						while (Remove(pGame));
					}
				}
			}
			return;
		}

	}

}



int Remove(Game *pGame)
{
	int sum;
	int i;
	for (i = FACE_Y - 2; i > 4; i--)
	{
		sum = 0;
		for (int j = 1; j < FACE_X - 1; j++)
		{
			sum += pGame->face.data[i][j];
		}
		if (sum == 0)
		{
			break;
		}
		if (sum == FACE_X - 2)//满了一行
		{
			pGame->score += 10;
			pGame->speed -= 2;
			color(7);
			SetCurPos(2 * FACE_X + 2, FACE_Y - 4);
			printf("分数:%d", pGame->score);
			for (int j = 1; j < FACE_X - 1; j++)
			{
				pGame->face.data[i][j] = KONG;
				SetCurPos(2 * j, i);
				printf("  ");
			}
			for (int j = i; j > 1; j--)
			{
				sum = 0;
				for (int k = 1; k < FACE_X - 1; k++)
				{
					sum += pGame->face.data[j][k] + pGame->face.data[j - 1][k];
					pGame->face.data[j][k] = pGame->face.data[j - 1][k];
					if (pGame->face.data[j][k] == KONG)
					{
						SetCurPos(2 * k, j);
						printf("  ");
					}
					else
					{
						SetCurPos(2 * k, j);
						color(pGame->face.color[j][k]);
						printf("█");
					}
				}
				if (sum == 0)
				{
					return 1;
				}
			}
		}
	}
	for (int j = 1; j < FACE_X - 1; j++)
	{
		if (pGame->face.data[1][j] == BOX)
		{
			Sleep(2000);
			system("cls");
			color(7);
			SetCurPos(2 * (FACE_X / 3), FACE_Y / 2 - 2);
			if (pGame->score > pGame->maxscore)
			{
				printf("恭喜打破纪录，目前最高记录：%d", pGame->score);
				write_maxscore(&pGame->score);
			}
			else if (pGame->score == pGame->maxscore)
			{
				printf("与记录持平，继续努力");
			}
			else
			{
				printf("请继续努力，离最高记录只差：%d", pGame->maxscore - pGame->score);
			}

			SetCurPos(2 * (FACE_X / 3), FACE_Y / 2);
			printf("GAME OVER!");

			SetCurPos(2 * (FACE_X / 3), FACE_Y / 2 + 2);
			printf("是否重新开始游戏(F3/F4): ");
			if (GetAsyncKeyState(VK_F3))
			{
				main();
			}
			else if (GetAsyncKeyState(VK_F4))
			{
				SetCurPos(2 * (FACE_X / 3), FACE_Y / 2 + 4);
				printf("按任意键退出游戏！");
				exit(0);
			}

		}
	}
	return 0;
}



int main()
{
	int nn;
	system("cls");
	system("title 俄罗斯方块");
	color(7);
	system("mode con cols=60 lines=30");
	Game game;
	srand((unsigned)time(NULL));
	read_maxscore(&game.maxscore);
	GameInit(&game);
	Init_dia();
	hide_cursor();
	nn = rand() % 7;
	while (1)
	{
		go_game(&game, nn);
	}
	return 0;
}





