#include <stdio.h>

//int a = 100;

int main()
{
#if 0
	int age = 119;
	if (age < 18)
		printf("δ����\n");
	//����д��18<=age<=28 ����������Ϊ��18<age��ֵ ����age=10�������ж�18<=10���Ϊ�� ��=0 ���ж�0<=28
	else if(age >= 18 && age <= 28) 
		printf("����\n"); 
	else if (age > 28 && age <= 50)
		printf("׳��\n");
	else if (age > 50 && age <= 90)
		printf("����\n");
	else
		printf("�ϲ���\n");
#endif

#if 0
	//����else
	int a = 0;
	int b = 0;
	//else����������ifƥ�� ��ǵ�2�ͱ�ǵ�3ƥ��
	if(a == 1) //��ǵ�1
		if(b == 2) //��ǵ�2
			printf("hehe\n");
		else //��ǵ�3
			printf("haha\n");

	//��ǵ�1�ͱ�ǵ�3ƥ��
	if (a == 1) //��ǵ�1
	{
		if (b == 2) //��ǵ�2
			printf("hehe\n");
	}	
	else //��ǵ�3
			printf("haha\n");
#endif

#if 0
	int num = 4;
	if (5 == num) //��ý��������ڵȺ��ұ� ��=�� ��ֵ ��==�� �ж����
	{
		printf("hehe\n");
	}
#endif

#if 0
	//���1~100֮�������
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		if(i % 2 != 0)
			printf("%d ", i);
	}
#endif

	/*int num = 4;
	//���泣��
	3; 
	100;
	3.14;*/
	return 0;
}