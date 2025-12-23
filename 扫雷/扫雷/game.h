#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 9
#define	COL 9 

#define ROWS ROW+2
#define	COLS COL+2
#define EASY_COUNT 10
void heding();
void game();
void outset(char sz1[ROWS][COLS],int hang,int lie,char set);
void displayboard(char sz1[ROWS][COLS], int hangs, int lies);///数组本质大小是11*11所以这里还是ROWS和COLS
void stemine(char sz1[ROWS][COLS], int hangs, int lies);
void dinf(char sz1[ROWS][COLS], char sz2[ROWS][COLS], int hangs, int lies);
void zhank(char sz1[ROWS][COLS],char sz2[ROWS][COLS], int x, int y);