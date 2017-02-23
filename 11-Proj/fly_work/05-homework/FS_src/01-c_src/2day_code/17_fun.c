#include <stdio.h>


int fun1(int a,int b);   //函数的声明

int main(void)      //函数头
{					//函数体
	int a = 5,b = 3;
	int s;

	s = fun1(a,b);   //函数的调用,a和b为实参
	printf("s = %d\n",s);
	printf("a = %d,b = %d\n",a,b);
	return 0;
}

//定义函数fun1，功能：计算两个整形数据的和，并将其返回
int fun1(int x,int y)  //x和y为形参
{
	int sum;

	sum = x + y;
	x = 100;
	y = 200;
	printf("x = %d,y = %d\n",x,y);
	return sum;
}
