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
	printf("���ֵΪ�� %d\n", max);

	return 0;
}
#endif

#if 0
//���ֽ�������ʹ��x,y������һ���ַ�ռ䣬��main�������a,bû����ϵ������ʧ��
//void Swap(int x, int y) //��ֵ
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//}

void Swap(int *x, int *y) //��ַ
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
	printf("����ǰ��a = %d, b = %d\n", a, b);
	Swap(&a, &b);
	printf("������a = %d, b = %d\n", a, b);
	return 0;
}
#endif

#if 0
//����������1 ���Ƿ�����
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
	//��ӡ100~200֮�������
	int i = 0;
	for(i = 100; i <= 200; i++)
	{
		//�ж�i�Ƿ�Ϊ����
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
	//��Ҫ�ں������ӡ
}
int main()
{
	//��ӡ����
	int year = 0;
	for(year = 1000; year <= 2000; year++)
	{
		//�ж��Ƿ�Ϊ����
		if(1 == is_leap_year(year))
		{
			printf("%d ", year);
		}
	}
	return 0;
}	
#endif

#if 0
//                    arr[]ʵ����ָ��
int binary_search(int arr[], int k, int sz)
{
	//int sz = sizeof(arr) / sizeof(arr[0]); //�����ָ��Ĵ�С ��������Ĵ�С
	int left = 0;
	int right = sz - 1;

	while(left <= right)
	{
		int mid = (left + right) / 2; //�м�Ԫ������
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
	//���ֲ���
	//��һ�����������в��Ҿ����ĳ����
	//�ҵ������±꣬�Ҳ�������-1
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//                      ���ݵ���arr��Ԫ�صĵ�ַ
	int ret = binary_search(arr, k, sz);
	if(ret == -1)
	{
		printf("�Ҳ���ָ��������\n");
	}
	else
	{
		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
	}
	return 0;
}
#endif

#if 0
void Add(int* p)
{
	//*p++; //++���ȼ��ϸ� ִ�е���p++ ����*p++
	(*p)++;
}

int main()
{
	//дһ������ ÿ����һ��������� �ͻὫnumֵ+1
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
//������Ƕ�׵���
int main()
{
	three_line();
	return 0;
}
#endif

#if 0
//��������ʽ���ʣ���һ�������ķ���ֵ��Ϊ����һ�������Ĳ���
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
{   //printf�ķ���ֵ���ַ��ĸ���
	//���printf("%d\n", 1)   <- 2.���printf("%d\n", 2) ����1     <- 1.��ӡ43 ����2           
	printf("%d ",             printf("%d ",                       printf("%d ", 43)));
	return 0;
}
#endif

#if 0
//��������
//������������д���������� ���ڳ����������ɨ�� �����Ҳ�������Add�ľ��� Ҫ��main����ǰ���Ϻ������������
int Add(int x, int y); 

int main()
{	
	int a = 10;
	int b = 20;
	int sum = 0;
	//��������
	sum = Add(a, b);
	printf("%d\n", sum);
	return 0;
}
//��������
int Add(int x, int y)
{
	int z = x + y;
	return z;
}
#endif

#if 0
//��������
#include "add.h"
int main()
{
	int a = 10;
	int b = 20;
	int sum = 0;
	//��������
	sum = Add(a, b);
	printf("%d\n", sum);
	return 0;
	return 0;
}
#endif

#if 0
//�ݹ�->���»�С
int main()
{
	//��򵥵ĵݹ�
	printf("haha\n");
	main(); //stack overflow ջ������� �����������Լ� ����ջ���
	return 0;
}
#endif

#if 0
//�ݹ��������Ҫ����
//1.������������ ���������������� �ݹ�㲻�ڼ���
//2.ÿ�εݹ����֮��Խ���½ӽ������������
void print(int n)
{
	if(n > 9) //�����������Լ� �����
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}

int main()
{
	//����һ�������޷��� ����˳���ӡ����ÿһλ
	unsigned int num = 0;
	scanf("%d", &num);
	//�ݹ�
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
	//��д���������м�������ַ�������
	char arr[] = "bit";
	int len = my_strlen(arr); //arr������ ���鴫�� ����ȥ�Ĳ����������� ���ǵ�һ��Ԫ�صĵ�ַ
	printf("len = %d\n", len);
	return 0;
}
#endif

#if 0
int Facl(int n)
{
	//ѭ����ʽ
	//int i = 0;
	//int ret = 1;
	//for(i = 1; i <= n; i++)
	//{
	//	//ret *= i;
	//	ret = ret * i;
	//}
	//return ret;

	//�ݹ鷽ʽ
	if(n <= 1)
		return 1;
	else
		return n * Facl(n - 1);
}

int main()
{
	//��n�Ľ׳�
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
	if(n == 3) //���Ե�����쳲��������ļ������
		count ++;

	if(n <= 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}
int main()
{
	//��쳲���������
	int n = 0; 
	int ret = 0;
	scanf("%d", &n);
	ret = Fib(n);
	printf("ret = %d\n", ret);
	printf("count = %d\n", count);
	return 0;
}
#endif