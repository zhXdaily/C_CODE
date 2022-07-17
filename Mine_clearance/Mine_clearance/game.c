#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void initBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void displayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for(i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for(i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for(j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASE_COUNT;
	while(count)
	{
		int x = rand()%row + 1; //1~row
		int y = rand()%col + 1; //1~col
		if(board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//根据ASCII表可得
// '1' - '0' = 1 字符1-字符0 = 数字1
// '3' - '0' = 3 字符3-字符0 = 数字3
//统计雷的个个数
int getMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + 
		   mine[x - 1][y - 1] + 
		   mine[x][y - 1] +
		   mine[x + 1][y - 1] +
		   mine[x + 1][y] +
		   mine[x + 1][y + 1] +
		   mine[x][y + 1] +
		   mine[x - 1][y + 1] - 8 * '0';
}

void safeMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col)
{
	int x = 0;
	int y = 0;
	char ch = 0;
	int ret = 1;
	printf("请输入要排查雷的坐标\n");
	while(1)
	{
		scanf("%d%d", &x, &y);
		if(x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if(mine[x][y] == '1') //第一次踩到雷补救
			{
				mine[x][y] = '0';
				char ch = getMineCount(mine, x, y);
				//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
				show[x][y] = ch + '0';
				openMine(mine, show, x, y);
				displayBoard(show, row, col);
				while(ret)//在其余有空的地方设置一个雷
				{
					int x = rand()%row + 1; //1~row
					int y = rand()%col + 1; //1~col
					if (mine[x][y] == '0')//找不是雷的地方布雷
					{
						mine[x][y] = '1';
						ret--;
						break;
					}
				}
				break;//跳出此函数	
			}
			if (mine[x][y] == '0')
			{
				char ch = getMineCount(mine, x, y);
				show[x][y] = ch + '0';//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
				openMine(mine, show, x, y);
				displayBoard(show, row, col);
				break;
			}
		}
		else//坐标错误
		{
			printf("输入错误重新输入\n");
		}
	}
}

void openMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if(mine[x - 1][y - 1] == '0')
	{
		//显示该坐标周围雷数
		show[x - 1][y - 1] = getMineCount(mine, x - 1, y - 1);
	}
	if (mine[x - 1][y] == '0')
	{
		show[x - 1][y] = getMineCount(mine, x - 1, y) + '0';
	}
	if (mine[x - 1][y + 1] == '0')
	{
		show[x - 1][y + 1] = getMineCount(mine, x - 1, y + 1) + '0';
	}
	if (mine[x][y - 1] == '0')
	{
		show[x][y - 1] = getMineCount(mine, x, y - 1) + '0';
	}
	if (mine[x][y + 1] == '0')
	{
		show[x][y + 1] = getMineCount(mine, x, y + 1) + '0';
	}
	if (mine[x + 1][y - 1] == '0')
	{
		show[x + 1][y - 1] = getMineCount(mine, x + 1, y - 1) + '0';
	}
	if (mine[x + 1][y] == '0')
	{
		show[x + 1][y] = getMineCount(mine, x + 1, y) + '0';
	}
	if (mine[x + 1][y + 1] == '0')
	{
		show[x + 1][y + 1] = getMineCount(mine, x + 1, y + 1) + '0';
	}
}

void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;

	char ch = 0;
	int ret = 1;

	int win = 0;
	//9*9-10 = 71 9*9的棋盘10个雷 剩下71个不是雷的位置
	while(win < row*col-EASE_COUNT)
	{
		printf("请输入要排查雷的坐标\n");
		scanf("%d%d", &x, &y);
		if(x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法
			//1.踩雷
			if(mine[x][y] == '1')
			{
				printf("很遗憾， 你被炸死\n");
				displayBoard(mine, row, col);
				break;
			}
			//不是雷
			else
			{
				//计算x y周围有几个雷
				int count = getMineCount(mine, x, y);
				show[x][y] = count + '0';
				openMine(mine, show, x, y);
				displayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}
	if(win == row * col - EASE_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		displayBoard(mine, row, col);
	}
}