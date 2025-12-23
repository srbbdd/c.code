#include "game.h"
void heding()
{
	printf("*********************************\n");
	printf("**************1.play*************\n");
	printf("**************0.exti*************\n");
	printf("*********************************\n");
}
void outset(char sz1[ROWS][COLS], int hang, int lie,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)
		{
			sz1[i][j] = set;
		}
	}
}
void displayboard(char sz1[ROWS][COLS], int hangs, int lies)
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= lies; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= hangs; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= lies; j++)
		{
			printf("%c ", sz1[i][j]);
		}
		printf("\n");
	}
}
void stemine(char sz1[ROWS][COLS], int hangs, int lies)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand()%hangs +1;
		int y = rand()%lies +1;
		if (sz1[x][y] != '1')
		{
			sz1[x][y] = '1';
			count--;
		}
	}
}
int getcoun(char sz1[ROWS][COLS], int x, int y)
{
	return sz1[x - 1][y] + sz1[x - 1][y - 1] + sz1[x][y - 1] + sz1[x + 1][y - 1] + sz1[x + 1][y] + sz1[x + 1][y + 1] + sz1[x][y + 1] + sz1[x - 1][y + 1]-8*'0';
}
void zhank(int bj[ROWS][COLS],char sz1[ROWS][COLS], char sz2[ROWS][COLS], int x, int y)
{
    if (sz1[x][y] == '1')
    {
        return;
    }
	if (x<1 || x> ROW || y<1 || y>COL)
	{
		return ;
    }
	if (bj[x][y] == 1)
	{
		return ;
	}
	bj[x][y] = 1;
	int count = getcoun(sz1, x, y);
	if (count > 0)
	{
		sz2[x][y] = count + '0';
		return ;
	}
		sz2[x][y] = ' ';
		zhank(bj,sz1,sz2,x - 1, y - 1);
		zhank(bj,sz1,sz2,x - 1, y);
		zhank(bj,sz1, sz2, x - 1, y + 1);
		zhank(bj,sz1, sz2, x, y - 1);
		zhank(bj,sz1, sz2, x, y + 1);
		zhank(bj,sz1, sz2, x + 1, y - 1);
		zhank(bj,sz1, sz2, x + 1, y);
		zhank(bj,sz1, sz2, x + 1, y + 1);
}
void dinf(char sz1[ROWS][COLS], char sz2[ROWS][COLS], int hangs, int lies)
{
	int x = 0;
	int y = 0;
	int ccc = 0; 
	int win =ROW*COL;//排雷的个数)
	int bj[ROWS][COLS] = { 0 };
	while (1)
	{
		printf("输入排雷坐标\n");
		printf("输入0，0可以标记雷\n");
		scanf_s("%d %d", &x, &y);
		if (x == 0 && y == 0)
		{
			displayboard(sz2, ROW, COL);
			int a = 0;
			int b = 0;
			printf("输入00,00可以撤回标记\n");
			printf("输入标记坐标\n");
			scanf_s("%d %d", &a, &b);
			if (sz2[a][b] != '!' && a != 00 && b != 00 && a > 0 && a < ROWS && b>0 && b < COLS)
			{
				sz2[a][b] = '!';
				if (sz1[a][b] == '1')
				{
					system("cls");
					win--;
					ccc++;
					displayboard(sz2, ROW, COL);
				}
				system("cls");
				displayboard(sz2, ROW, COL);
			}
			if (a == 00 && b == 00)
			{
				printf("输入撤回坐标\n");
				scanf_s("%d %d", &a, &b);
				if (a > 0 && a < ROWS && b>0 && b < COLS && sz2[a][b] == '!')
				{
					sz2[a][b] = '*';

					if (sz1[a][b] == '1')
					{
						system("cls");
						win++;
						displayboard(sz2, ROW, COL);
					}
					system("cls");
					displayboard(sz2, ROW, COL);
				}
			}
		}
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (sz2[x][y] != '*')
			{
				printf("坐标重复\n");
			}
			else
			{
				if (sz1[x][y] == '1')
				{
					system("cls");
					printf("你被炸死了\n");
					displayboard(sz1, ROW, COL);
					break;
				}
				else
				{
					win--;
					// 统计xy坐标旁边雷的数里
					int count = getcoun(sz1, x, y);
					sz2[x][y] = count + '0';//转换成数字字符
					if (sz2[x][y] == '0')
					{
						sz2[x][y] = ' ';
					}
					system("cls");
					if (win == ROW * COL - 1)
					{
						zhank(bj,sz1,sz2, x, y);
					}
					displayboard(sz2, ROW, COL);
				}
			}
		}
		if (x<0 && x>ROWS && y<0 && y>COLS)
		{
			printf("坐标非法\n");
		}

		if (win == EASY_COUNT||ccc == EASY_COUNT)
		{
			printf("哦没得都，你赢了\n");
			displayboard(sz1, ROW, COL);
			return 0;
		}
	}
}                                                                                                         