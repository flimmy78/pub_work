#include <stdio.h>

typedef int typeint;   //给int引入一个别名typeint
typedef int typearr[5];
typedef int * typeintp;
int  main(void)
{
	int a,i;   //用整型类型int定义变量a
	typeint b;   //用整型类型typeint定义变量b
	typearr c = {1,2,3,4,5};
	typeintp p;

	a = 100;
	b = 200;
	p = &a;
	printf("a = %d\n",a);
	printf("*p = %d\n",*p);
	printf("b = %d\n",b);
	for(i = 0; i < 5; i++)
		printf("%d\t",c[i]);
	printf("\n");
	return 0;
}
