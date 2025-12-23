#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void game()
{
	char sz1[ROWS][COLS] = { 0 };//布雷棋盘
	char sz2[ROWS][COLS] = { 0 };//打印棋盘
	//初始化数组内容
	outset(sz1, ROWS, COLS, '0');
	outset(sz2, ROWS, COLS, '*');
	//布雷
	stemine(sz1, ROW, COL);
	//打印
	displayboard(sz2, ROW, COL);
	//排雷
	dinf(sz1, sz2, ROW, COL);
}
int main()
{
	srand ((unsigned int)time(NULL));
	int opt = 0;
	do
	{
		heding();
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误");
			break;
		}
	} while (opt);
	return 0;
}