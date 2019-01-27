#pragma once

#include "Model.h"

void dispay_menu();
void display_face(Face* face, int maxscore, int score);
void display_kong(int nn, int space_c, int x, int y, Face face);
void display_dia(int nn, int space_c, int x, int y);
void hide_cursor();
void SetCurPos(int X, int Y);
void display_kong1(int x, int y);
void read_maxscore(int* maxsorse);
void write_maxscore(int* maxsorse);