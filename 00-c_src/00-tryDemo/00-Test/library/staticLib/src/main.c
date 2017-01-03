#include <stdio.h>

#include "testlib.h"

int main(void)
{
	int n;

	printf("%s\t%s\t%d\n",__FILE__,__func__,__LINE__);
	printf("Pls input n : ");
	scanf("%d",&n);
	printf("In main file : %d\n",fun(n));

	return 0;
}
