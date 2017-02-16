#include <stdio.h>

void fun1(int* x,int* y)
{
	*x = 100;
	*y = 200;
}

int main(void)      //函数头
{					//函数体
	int a = 5,b = 3;
	printf("a = %d,b = %d\n",a,b);
	fun1(&a,&b);  //地址传递
	printf("a = %d,b = %d\n",a,b);

	return 0;
}
