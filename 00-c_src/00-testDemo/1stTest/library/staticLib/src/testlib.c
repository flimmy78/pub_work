#include <stdio.h>

int fun(int a)
{
	printf("%s\t%s\t%d\n",__FILE__,__func__,__LINE__);
	printf("In lib file : a = %d\n",a);
	return a*a;
}
