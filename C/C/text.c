#include <stdio.h>

//int a = 100;

int main()
{
#if 0
	int age = 119;
	if (age < 18)
		printf("未成年\n");
	//不能写成18<=age<=28 编译器会认为是18<age的值 比如age=10，会先判断18<=10结果为假 假=0 在判断0<=28
	else if(age >= 18 && age <= 28) 
		printf("青年\n"); 
	else if (age > 28 && age <= 50)
		printf("壮年\n");
	else if (age > 50 && age <= 90)
		printf("老年\n");
	else
		printf("老不死\n");
#endif

#if 0
	//悬空else
	int a = 0;
	int b = 0;
	//else和离得最近的if匹配 标记点2和标记点3匹配
	if(a == 1) //标记点1
		if(b == 2) //标记点2
			printf("hehe\n");
		else //标记点3
			printf("haha\n");

	//标记点1和标记点3匹配
	if (a == 1) //标记点1
	{
		if (b == 2) //标记点2
			printf("hehe\n");
	}	
	else //标记点3
			printf("haha\n");
#endif

#if 0
	int num = 4;
	if (5 == num) //最好将变量放在等号右边 “=” 赋值 “==” 判断相等
	{
		printf("hehe\n");
	}
#endif

#if 0
	//输出1~100之间的奇数
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		if(i % 2 != 0)
			printf("%d ", i);
	}
#endif

	/*int num = 4;
	//字面常量
	3; 
	100;
	3.14;*/
	return 0;
}