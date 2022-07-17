#include <stdio.h>
#include <string.h>

#if 0
int main()
{
	//����һ������ �������
	//int arr[10] = {1, 2, 3}; //����ȫ��ʼ�� ʣ�µ�Ԫ��Ĭ�ϳ�ʼ��Ϊ0
	//char arr2[5] = {'a', 'b'}; //ʣ�µ�Ԫ��Ĭ��Ϊ\0
	//char arr3[5] = "ab";
	char arr4[] = "abcdef";
	printf("%d\n", sizeof(arr4)); //����arr4��ռ�ռ�Ĵ�С a b c d e f \0
	printf("%d\n", strlen(arr4)); //���ַ������� \0֮ǰ�ĳ��� a b c d e f
	/*
	int n = 5;
	char ch[n]; // error! ���鴴�� []��Ҫ�������ſ��� ������ʹ�ñ���
	*/

	return 0;
}
#endif

#if 0
int main()
{
	char arr1[] = "abc"; //a b c \0
	char arr2[] = {'a', 'b', 'c'}; //a b c
	printf("%d\n", sizeof(arr1));
	printf("%d\n", sizeof(arr2));
	printf("%d\n", strlen(arr1));
	printf("%d\n", strlen(arr2));

	return 0;
}
#endif

#if 0
int main()
{
	//char arr[] = "abcdef";
	////printf("%c\n", arr[3]);
	//int i = 0;
	//int len = strlen(arr);
	//for(i = 0; i < len; i++)
	//{
	//	printf("%c ", arr[i]);
	//}

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for(i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
#endif

#if 0
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for(i = 0; i < sz; i++)
	{
		printf("&arr[%d] = %p\n", i, &arr[i]);
	}

	return 0;
}
#endif

#if 0
int main()
{
	int arr[3][4] = {{1, 2, 3}, {4, 5}}; /*1 2 3
										   4 5*/
	int i = 0;
	int j = 0;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	//int arr1[3][4] = {1, 2, 3, 4, 5}; /*1 2 3 4
	//								    5*/
	//int arr2[][4] = {1, 2, 3, 4, 5, 6}; //�п���ʡ�� �в�����ʡ��
	return 0;
}
#endif

#if 0
int main()
{
	//�ڴ��ʽ��������[0][0] [0][1] [0][2] [0][3] [1][0] [1][1] [1][2] [1][3] [2][0] [2][1] [2][2] [2][3]
	int arr[3][4] = {{1, 2, 3}, {4, 5}};
	int i = 0;
	int j = 0;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
		}
	}

	return 0;
}
#endif

#if 0
void bubbleSort(int arr[], int sz)
{
	int flag = 1; //������һ��Ҫ����������Ѿ�����
	//ȷ��ð�����������
	int i = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]); //�����arr��Ԫ��ָ��Ĵ�С ���������С error��������
	for(i = 0; i < sz - 1; i++)
	{
		//ÿһ��ð�����������
		int j = 0;
		for(j = 0; j < sz - 1 - i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0; //����������ȫ��
			}
		}
		if(flag == 1)
		{
			break;
		}
	}
}

int main()
{
	//������Ϊ��������
	//ð������
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, sz); //����ȥ����arr���׵�ַ &arr[0]
	for(i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
#endif

#if 1
int main()
{
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	printf("%p\n", arr); //��Ԫ�ص�ַ
	printf("%p\n", arr + 1); //�ڶ���Ԫ�صĵ�ַ

	printf("%p\n", &arr[0]); //��Ԫ�ص�ַ
	printf("%p\n", &arr[0] + 1); //�ڶ���Ԫ�صĵ�ַ

	printf("%p\n", &arr); //���������ַ
	printf("%p\n", &arr + 1); //������������ĵ�ַ 0֮��ĵ�ַ

	return 0;
}
#endif