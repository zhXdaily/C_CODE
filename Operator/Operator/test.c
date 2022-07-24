#define _CRT_SECURE_NO_WARNINGS 1
//C语言操作符详解
#include <stdio.h>

#if 0
//算术操作符 + - * / %
int main()
{
	double a = 5 / 2.0; //商2余1
	//double a = 5 % 2.0; //%操作符只能是整型 error
	printf("a = %lf", a);
	return 0;
}
#endif

#if 0
//移位操作符 <<左移操作符  >>右移操作符

//正数右移
int main()
{
	int a = 16; //整型是4个字节 32bit
	//int a = -1;
	//>> 右移操作符
	//移动的是二进制位
	//16的二进制00000000000000000000000000010000
	//算数右移->右边丢弃 左边补原符号位 0为正 1为负
	//逻辑右移->右边丢弃 左边补0
	int b = a >> 1; //默认算数以为
	printf("%d", b); //8
	return 0;
}
#endif

#if 0
//负数右移
int main()
{
	int a = -1;
	//整数的二进制表示有原码、反码、补码
	//存储到内存中的是补码
	//正数 原码=反码=补码
	//10000000000000000000000000000001 -1的在内存中的原码 第一个1表示符号位 第二个1是值
	//11111111111111111111111111111110 -1的在内存中的反码 符号位不变，其它位取反
	//11111111111111111111111111111111 -1的在内存中的补码 反码+1
	int b = a >> 1;
	printf("%d\n", b);

	return 0;
}
#endif

#if 0
//正数左移
int main()
{
	//00000000000000000000000000000101  5在计算机中的值
	int a = 5;
	int b = a << 1;
	//00000000000000000000000000001010 左移一位的结果
	//左移操作符
	//左边丢弃 右边补0
	printf("%d\n", b);

	return 0;
}
//对于移位运算符 不要移动负数位 这个标准是未定义的
//eg:
//int num = 10;
//num >> -1; //error！！！！
#endif

#if 0
//位操作符  &按位与  |按位或  ^按位异或 
//注：他们的操作数必须是整数。

int main()
{
	int a = 3; //011  32位 前面28个零
	int b = 5; //101  32位 前面28个零
	int c = a & b;
	int d = a | b;
	int e = a ^ b; //相同为0 不同为1
	printf("a&b = %d\n", c); //001
	printf("a|b = %d\n", d); //111
	printf("a^b = %d\n", e); //110

	return 0;
}
#endif

#if 0
int main()
{
	//不使用第三个变量 交换两个数
	int a = 3; //011
	int b = 5; //101
	printf("交换前：a = %d,b = %d\n", a, b);

	//一旦超出整型能表达的最大值 可能会溢出 只能解决部分问题
	/*a = a + b; //a=8 b=5
	b = a - b; //a=8 b=3
	a = a - b; //a=5 b=3
	printf("交换后: a = %d,b = %d\n", a, b);*/
	a = a ^ b; //a = 011 ^ 101 = 110 -> 6
	b = a ^ b; //b = 110 ^ 101 = 011 -> 3
	a = a ^ b; //a = 110 ^ 011 = 101 -> 5 
	printf("交换后: a = %d,b = %d\n", a, b);

	return 0;
}
#endif

#if 0
int main()
{
	//求一个整数存储在内存中1的个数
	int num = 0;
	int count = 0;
	scanf("%d", &num);
	//统计num的补码中有几个1
	/*//方法1
	while(num)
	{
	//这种算法不适用于负数
		if(num % 2 == 1)
			count++;
		num = num /2;
	}*/

	//整形占32bit
	//num&1
	//方法2
	/*int i = 0;
	for(i = 0; i < 32; i++)
	{
		if(1 == ((num >> i) & 1))
			count++;
	}
	printf("%d\n", count);*/

	//方法3
	while(num)
	{
		count++;
		num = num & (num - 1); //真妙啊
	}
	printf("%d\n", count);

	return 0;
}
#endif

#if 0
int main()
{
	short s = 0;
	int a = 10;
	printf("%d\n", sizeof(s = a + 5)); //sizeof内部表达式不参与运算
	printf("%d\n", s);
	//int a = 0;
	//char b = 'w';
	//int arr[10] = {0};

	//printf("%d\n", sizeof(a)); //4
	//printf("%d\n", sizeof(int)); //4

	//printf("%d\n", sizeof(b)); //1
	//printf("%d\n", sizeof(char)); //1

	//printf("%d\n", sizeof(arr)); //10个元素 x 4（整型占4bit）=40
	//printf("%d\n", sizeof(int[10])); //40

	return 0;
}
#endif

#if 0
int main()
{
	int a = 11;
	
	//将数的某一位改成1 例如下面将倒数第三位的0改成1 只需要将该位置或1其他位置或0
	//00000000000000000000000000001011 num1
	//00000000000000000000000000000100 num2
	//num2相当于将1左移两位 1 << 2
	//00000000000000000000000000001111 num1 | num2
	a = a | (1 << 2);
	printf("%d\n", a); //15
	
	//将数的某一位改成0 只需要将该位置与0其他位置与1
	//00000000000000000000000000001111 num1
	//11111111111111111111111111111011 num2
	//00000000000000000000000000001011 num1 & num2
	//num2相当于左移两位 在按位取反 ~(1 << 2)
	a = a & (~(1 << 2)); //11
	printf("%d\n", a);
	
	//int a = 0;
	//~按位取反
	//00000000000000000000000000000000  补码
	//11111111111111111111111111111110  反码
	//10000000000000000000000000000001  原码
	//printf("%d\n", ~a); //-1

	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;
	//printf("%d\n", ++a); //前置++ 先++ 后使用 11
	printf("%d\n", a++); //后置++ 先使用 在++ 10

	int a = (int)3.14; //强制转换

	return 0;
}
#endif

#if 0
void test1(int arr[])
{
	printf("%d\n", sizeof(arr));//(2)
}
void test2(char ch[])
{
	printf("%d\n", sizeof(ch)); //(4)
}

int main()
{
	int arr[10] = {0};
	char ch[10] = {0};
	printf("%d\n", sizeof(arr));//(1)  40
	printf("%d\n", sizeof(ch)); //(3)  10
	test1(arr);    //8
	test2(ch);     //8
	return 0;

	return 0;
}
#endif