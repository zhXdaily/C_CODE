#define _CRT_SECURE_NO_WARNINGS 1
//显示该点周围雷的个数
//第一次下子，不炸死
//坐标周围没雷，可以实现展开
//游戏结束后展示玩家用时
#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("*********  1.play  ********\n");
	printf("*********  2.exit  ********\n");
	printf("***************************\n");
}

void game()
{
	double start, finish;
	//雷的信息存储
	//1.布置好的累的信息
	char mine[ROWS][COLS] = {0}; //(row+2) * (col+2)
	//2.排查好的雷的信息
	char show[ROWS][COLS] = {0}; //(row+2) * (col+2)
	//初始化
	initBoard(mine, ROWS, COLS, '0');
	initBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//displayBoard(mine, ROW, COL);
	displayBoard(show, ROW, COL);
	//布置雷
	setMine(mine, ROW, COL);
	displayBoard(mine, ROW, COL);
	//扫雷
	start = clock();
	safeMine(mine, show, ROW, COL);
	findMine(mine, show, ROW, COL);
	finish = clock();
	printf("用时%d 秒\n", (int)(finish - start) / CLOCKS_PER_SEC);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch(input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	}while(input);
}

int main()
{
	test();
	return 0;
}