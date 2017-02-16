#include <stdio.h>

int fun1(int x,int y)
{
	return x+y;
}
int fun2(int x,int y)
{
	return x-y;
}
int fun3(int x,int y)
{
	return x*y;
}
int fun4(int x,int y)
{
	return x/y;
}


int main(void)
{
	int a = 5,b = 3;	
	
	int (*arr[4])(int,int) = {fun1,fun2,fun3,fun4};   //arr为函数指针数组
	char str[] = "+-*/";
	int i;

	for(i = 0; i < 4; i++)
			printf("%d %c %d = %d\n",a,str[i],b,arr[i](a,b));
	return 0;
}
