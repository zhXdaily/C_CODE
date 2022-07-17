#include <stdio.h>
#include <string.h>

#if 0
int main()
{
	//创建一个数组 存放整型
	//int arr[10] = {1, 2, 3}; //不完全初始化 剩下的元素默认初始化为0
	//char arr2[5] = {'a', 'b'}; //剩下的元素默认为\0
	//char arr3[5] = "ab";
	char arr4[] = "abcdef";
	printf("%d\n", sizeof(arr4)); //计算arr4所占空间的大小 a b c d e f \0
	printf("%d\n", strlen(arr4)); //求字符串长度 \0之前的长度 a b c d e f
	/*
	int n = 5;
	char ch[n]; // error! 数组创建 []中要给常量才可以 不可以使用变量
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
	//int arr2[][4] = {1, 2, 3, 4, 5, 6}; //行可以省略 列不可以省略
	return 0;
}
#endif

#if 0
int main()
{
	//内存格式是连续的[0][0] [0][1] [0][2] [0][3] [1][0] [1][1] [1][2] [1][3] [2][0] [2][1] [2][2] [2][3]
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
	int flag = 1; //假设这一趟要排序的数据已经有序
	//确定冒泡排序的趟数
	int i = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]); //求的是arr首元素指针的大小 不是数组大小 error！！！！
	for(i = 0; i < sz - 1; i++)
	{
		//每一趟冒泡排序的内容
		int j = 0;
		for(j = 0; j < sz - 1 - i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0; //本趟排序不完全序
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
	//数组作为函数参数
	//冒泡排序
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, sz); //传过去的是arr的首地址 &arr[0]
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
	printf("%p\n", arr); //首元素地址
	printf("%p\n", arr + 1); //第二个元素的地址

	printf("%p\n", &arr[0]); //首元素地址
	printf("%p\n", &arr[0] + 1); //第二个元素的地址

	printf("%p\n", &arr); //整个数组地址
	printf("%p\n", &arr + 1); //跳过整个数组的地址 0之后的地址

	return 0;
}
#endif