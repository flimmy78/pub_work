#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p;

	//*p  = 100;   //P没有指向，不能取值运算
	p = (int*)malloc(sizeof(int));
	if(NULL == p){
		printf("malloc failed!\n");
		exit(1);
	}
	
	p += 10;
	*p = 200;
	printf("*p = %d\n",*p);

	return 0;
}
