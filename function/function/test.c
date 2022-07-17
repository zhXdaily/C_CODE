#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>


#if 0
int add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
int main()
{
	int a = 10;
	int b = 20;
	int sum = add(a, b);
	printf("%d\n", sum);
	return 0;
}
#endif

#if 0
int main()
{
	char arr1[] = "bit";
	char arr2[20] = "@@@@@@@";
	strcpy(arr2, arr1);
	printf("%s\n", arr2);
	return 0;
}
#endif

#if 0
// memset void *memset ( void * ptr, int value, size_t num );
int main()
{
	char arr[] = "hello world";
	memset(arr, '*', 5);
	printf("%s\n", arr);
}

#endif

#if 0
int getMax(int x, int y)
{
	if(x > y)
		return x;
	else
		return y;
}
int main()
{
	int a = 10;
	int b = 20;

	int max = getMax(a, b);
	printf("最大值为： %d\n", max);

	return 0;
}
#endif

#if 0
//这种交换方法使得x,y另开辟了一块地址空间，与main函数里的a,b没有联系，交换失败
//void Swap(int x, int y) //传值
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//}

void Swap(int *x, int *y) //传址
{
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	int a = 10;
	int b = 20;
	printf("交换前：a = %d, b = %d\n", a, b);
	Swap(&a, &b);
	printf("交换后：a = %d, b = %d\n", a, b);
	return 0;
}
#endif

#if 0
//是素数返回1 不是返回零
int is_prime(int n)
{
	int j = 0;
	for(j = 2; j < n; j++)
	{
		if(n % j == 0)
			return 0;
	}
	return 1;
}
int main()
{
	//打印100~200之间的素数
	int i = 0;
	for(i = 100; i <= 200; i++)
	{
		//判断i是否为素数
		if(is_prime(i) == 1)
			printf("%d ", i);
	}
	return 0;
}
#endif

#if 0
int is_leap_year(int y)
{
	if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		return 1;
	else 
		return 0;.
	//不要在函数里打印
}
int main()
{
	//打印闰年
	int year = 0;
	for(year = 1000; year <= 2000; year++)
	{
		//判断是否为闰年
		if(1 == is_leap_year(year))
		{
			printf("%d ", year);
		}
	}
	return 0;
}	
#endif

#if 0
//                    arr[]实际是指针
int binary_search(int arr[], int k, int sz)
{
	//int sz = sizeof(arr) / sizeof(arr[0]); //求的是指针的大小 不是数组的大小
	int left = 0;
	int right = sz - 1;

	while(left <= right)
	{
		int mid = (left + right) / 2; //中间元素坐标
		if(arr[mid] < k)
		{
			left = mid + 1;
		}
		else if(arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	//二分查找
	//在一个有序数组中查找具体的某个数
	//找到返回下标，找不到返回-1
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//                      传递的是arr首元素的地址
	int ret = binary_search(arr, k, sz);
	if(ret == -1)
	{
		printf("找不到指定的数字\n");
	}
	else
	{
		printf("找到了，下标是：%d\n", ret);
	}
	return 0;
}
#endif

#if 0
void Add(int* p)
{
	//*p++; //++优先级较高 执行的是p++ 不是*p++
	(*p)++;
}

int main()
{
	//写一个函数 每调用一次这个函数 就会将num值+1
	int num = 0;
	Add(&num);
	printf("num = %d\n", num);
	Add(&num);
	printf("num = %d\n", num);
	Add(&num);
	printf("num = %d\n", num);
	return 0;
}
#endif

#if 0
void new_line()
{
	printf("hehe\n");
}

void three_line()
{
	int i = 0;
	for(i = 0; i < 3; i++)
	{
		new_line();
	}
}
//函数的嵌套调用
int main()
{
	three_line();
	return 0;
}
#endif

#if 0
//函数的链式访问：把一个函数的返回值作为另外一个函数的参数
int main()
{
	int len = 0;
	//1
	len = strlen("abc");
	printf("%d\n", len);
	//2
	printf("%d\n", strlen("abc"));
	return 0;
}
#endif

#if 0
int main()
{   //printf的返回值是字符的个数
	//变成printf("%d\n", 1)   <- 2.变成printf("%d\n", 2) 返回1     <- 1.打印43 返回2           
	printf("%d ",             printf("%d ",                       printf("%d ", 43)));
	return 0;
}
#endif

#if 0
//函数声明
//若将函数定义写在主函数后 由于程序从上往下扫描 会有找不到函数Add的警告 要在main函数前加上函数声明来解决
int Add(int x, int y); 

int main()
{	
	int a = 10;
	int b = 20;
	int sum = 0;
	//函数调用
	sum = Add(a, b);
	printf("%d\n", sum);
	return 0;
}
//函数定义
int Add(int x, int y)
{
	int z = x + y;
	return z;
}
#endif

#if 0
//函数声明
#include "add.h"
int main()
{
	int a = 10;
	int b = 20;
	int sum = 0;
	//函数调用
	sum = Add(a, b);
	printf("%d\n", sum);
	return 0;
	return 0;
}
#endif

#if 0
//递归->大事化小
int main()
{
	//最简单的递归
	printf("haha\n");
	main(); //stack overflow 栈溢出错误 无条件调用自己 导致栈溢出
	return 0;
}
#endif

#if 0
//递归的两个必要条件
//1.存在限制条件 当满足限制条件后 递归便不在继续
//2.每次递归调用之后越来月接近这个限制条件
void print(int n)
{
	if(n > 9) //有条件调用自己 不溢出
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}

int main()
{
	//接受一个整型无符号 按照顺序打印他的每一位
	unsigned int num = 0;
	scanf("%d", &num);
	//递归
	print(num);

	return 0;
}
#endif

#if 0
int my_strlen(char *str)
{
	/*int count = 0;
	while(*str != '\0')
	{
		count++;
		str++;
	}
	return count;*/
	if(*str != '\0')
		return 1 + my_strlen(str + 1);
	else
		return 0;
}

int main()
{
	//编写函数不用中间变量求字符串长度
	char arr[] = "bit";
	int len = my_strlen(arr); //arr是数组 数组传参 传过去的不是整个数组 而是第一个元素的地址
	printf("len = %d\n", len);
	return 0;
}
#endif

#if 0
int Facl(int n)
{
	//循环方式
	//int i = 0;
	//int ret = 1;
	//for(i = 1; i <= n; i++)
	//{
	//	//ret *= i;
	//	ret = ret * i;
	//}
	//return ret;

	//递归方式
	if(n <= 1)
		return 1;
	else
		return n * Facl(n - 1);
}

int main()
{
	//求n的阶乘
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Facl(n);
	printf("%d\n", ret);

	return 0;
}
#endif

#if 1
int count = 0;
int Fib(int n)
{
	if(n == 3) //测试第三个斐波那契数的计算次数
		count ++;

	if(n <= 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}
int main()
{
	//求斐波那契数列
	int n = 0; 
	int ret = 0;
	scanf("%d", &n);
	ret = Fib(n);
	printf("ret = %d\n", ret);
	printf("count = %d\n", count);
	return 0;
}
#endif