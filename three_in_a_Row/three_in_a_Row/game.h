#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROW 3
#define COL 3

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void computerMove(char board[ROW][COL], int row, int col);

//判断输赢
//电脑赢 返回 *
//玩家赢 返回 #
//平局 返回 Q
//继续 返回 C
char IsWin(char board[ROW][COL], int row, int col);