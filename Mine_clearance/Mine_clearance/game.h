#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASE_COUNT 10

//��������
//��ʼ������
void initBoard(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void displayBoard(char board[ROWS][COLS], int row, int col);

//������
void setMine(char board[ROWS][COLS], int row, int col);

//ȷ����һ�����벻��ը��
void safeMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col);

//������Χչ������
void openMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);

//ɨ��
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);