#include <stdio.h>

extern void fun1(int ,int);

int main(void)
{
	int a,b;

	scanf("%d%d",&a,&b);
	fun1(a,b);
	return 0;
}
