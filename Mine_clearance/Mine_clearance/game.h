#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASE_COUNT 10

//函数声明
//初始化棋盘
void initBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void displayBoard(char board[ROWS][COLS], int row, int col);

//布置雷
void setMine(char board[ROWS][COLS], int row, int col);

//确保第一次输入不被炸死
void safeMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col);

//坐标周围展开函数
void openMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);

//扫雷
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);