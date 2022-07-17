#define _CRT_SECURE_NO_WARNINGS 1
//��ʾ�õ���Χ�׵ĸ���
//��һ�����ӣ���ը��
//������Χû�ף�����ʵ��չ��
//��Ϸ������չʾ�����ʱ
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
	//�׵���Ϣ�洢
	//1.���úõ��۵���Ϣ
	char mine[ROWS][COLS] = {0}; //(row+2) * (col+2)
	//2.�Ų�õ��׵���Ϣ
	char show[ROWS][COLS] = {0}; //(row+2) * (col+2)
	//��ʼ��
	initBoard(mine, ROWS, COLS, '0');
	initBoard(show, ROWS, COLS, '*');
	//��ӡ����
	//displayBoard(mine, ROW, COL);
	displayBoard(show, ROW, COL);
	//������
	setMine(mine, ROW, COL);
	displayBoard(mine, ROW, COL);
	//ɨ��
	start = clock();
	safeMine(mine, show, ROW, COL);
	findMine(mine, show, ROW, COL);
	finish = clock();
	printf("��ʱ%d ��\n", (int)(finish - start) / CLOCKS_PER_SEC);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch(input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}while(input);
}

int main()
{
	test();
	return 0;
}