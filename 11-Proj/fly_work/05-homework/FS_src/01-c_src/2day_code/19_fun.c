#include <stdio.h>

void fun(int x)
{
	printf("x = %d\n",x);
}

int main(void)      //函数头
{					//函数体
	fun(100);   //传常量
	fun(3+5);	//传表达式
	return 0;
}
