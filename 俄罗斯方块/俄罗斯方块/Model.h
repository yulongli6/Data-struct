
#pragma once

#define  FACE_X 20
#define FACE_Y 29
#define WALL 2
#define BOX  1
#define KONG 0

typedef struct Face
{
	int data[FACE_Y][FACE_X + 10];      //1->���飬2->�ո�
	int color[FACE_Y][FACE_X + 10];   //��Ӧ�������ɫ
}Face;


typedef struct DownDiamonds
{
	int space[4][4];
}DownDia;

DownDia dia[7][4];

typedef struct Game
{
	Face face;
	int maxscore;
	int score;
	int speed;
}Game;

void GameInit(Game *pGame);

void Init_dia();  //��ʼ������
int color(int c);
