#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROW 3
#define COL 3

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void computerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
//����Ӯ ���� *
//���Ӯ ���� #
//ƽ�� ���� Q
//���� ���� C
char IsWin(char board[ROW][COL], int row, int col);