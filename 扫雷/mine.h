#ifndef _MINE_H
#define _MINE_H
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#define ROW 12//10+2
#define COL 12//10+2
#define TOTAL 10*10
#define MINE_NUM 20
void SetMine(char mine[][COL], int row, int col);
void ShowBoard(char board[][COL], int row, int col);
char GetMines(char mine[][COL], int row, int col);
void Game();
#endif
