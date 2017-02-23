#include <stdio.h>
#include <stdlib.h>

int* fun(void)
{
	int a;    //a在栈里
	a = 100;
	printf("a = %d\n",a);

	int *p;
	p = (int*)malloc(sizeof(int));
	if(NULL == p){
		printf("malloc failed!\n");
		exit(1);   //调用exit使程序结束
	}
	*p = 100;
	printf("*p = %d\n",*p);
	return &a;
}
int main(void)
{
	int *pa;

	pa  = fun();
	printf("*pa = %d\n",*pa);
	return 0;
}
