#include <stdio.h>

int fun0(int x, int y)
{
	return x + y;
}

int fun1(int x, int y)
{
	return x - y;
}

int fun2(int x, int y)
{
	return x * y;
}

int fun3(int x, int y)
{
	return x / y;
}

int fun4(int x, int y)
{
	return x % y;
}

int main(void)
{
	int a = 0, b = 0;

	printf("Pls input integer a and b :");
	scanf("%d%d",&a,&b);
	printf("\na = %d\tb = %d\n ",a,b);

	int (*arr[5])(int ,int) = {fun0,fun1,fun2,fun3,fun4};
	char str[] = "+-*/%";

	int i;
	
	for(i = 0 ; i < 5; i++)
		printf("%d %c %d = %d\n",a,str[i],b,arr[i](a,b));

	return 0;
}
