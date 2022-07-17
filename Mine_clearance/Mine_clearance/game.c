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
	//��ӡ�к�
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

//����ASCII��ɵ�
// '1' - '0' = 1 �ַ�1-�ַ�0 = ����1
// '3' - '0' = 3 �ַ�3-�ַ�0 = ����3
//ͳ���׵ĸ�����
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
	printf("������Ҫ�Ų��׵�����\n");
	while(1)
	{
		scanf("%d%d", &x, &y);
		if(x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if(mine[x][y] == '1') //��һ�βȵ��ײ���
			{
				mine[x][y] = '0';
				char ch = getMineCount(mine, x, y);
				//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
				show[x][y] = ch + '0';
				openMine(mine, show, x, y);
				displayBoard(show, row, col);
				while(ret)//�������пյĵط�����һ����
				{
					int x = rand()%row + 1; //1~row
					int y = rand()%col + 1; //1~col
					if (mine[x][y] == '0')//�Ҳ����׵ĵط�����
					{
						mine[x][y] = '1';
						ret--;
						break;
					}
				}
				break;//�����˺���	
			}
			if (mine[x][y] == '0')
			{
				char ch = getMineCount(mine, x, y);
				show[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
				openMine(mine, show, x, y);
				displayBoard(show, row, col);
				break;
			}
		}
		else//�������
		{
			printf("���������������\n");
		}
	}
}

void openMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if(mine[x - 1][y - 1] == '0')
	{
		//��ʾ��������Χ����
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
	//9*9-10 = 71 9*9������10���� ʣ��71�������׵�λ��
	while(win < row*col-EASE_COUNT)
	{
		printf("������Ҫ�Ų��׵�����\n");
		scanf("%d%d", &x, &y);
		if(x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����Ϸ�
			//1.����
			if(mine[x][y] == '1')
			{
				printf("���ź��� �㱻ը��\n");
				displayBoard(mine, row, col);
				break;
			}
			//������
			else
			{
				//����x y��Χ�м�����
				int count = getMineCount(mine, x, y);
				show[x][y] = count + '0';
				openMine(mine, show, x, y);
				displayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("��������Ƿ�������������\n");
		}
	}
	if(win == row * col - EASE_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		displayBoard(mine, row, col);
	}
}