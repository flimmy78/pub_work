#include <stdio.h>

int main(void)
{
	int a = 100;
	int *pa = &a;    //对p初始化，即定义p的同时给p赋值。
	printf("pa = %p\n",pa);
	printf("pa+1 = %p\n",pa+1);
	printf("pa+3 = %p\n",pa+3);
	printf("*******************\n");

	short b = 50;
	short *pb = &b;
	printf("pb = %p\n",pb);
	printf("pb+1 = %p\n",pb+1);
	printf("pb+3 = %p\n",pb+3);
	printf("*******************\n");

	double c = 12.34;
	double *pc = &c;
	printf("pc = %p\n",pc);
	printf("pc+1 = %p\n",pc+1);
	printf("pc+3 = %p\n",pc+3);
	return 0;
}
