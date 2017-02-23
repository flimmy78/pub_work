#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	/*
	bool a;
	a = !4;   //逻辑取反
	printf("a = %d\n",a);
	*/
	
	/*
	int a = 5,b = 3;
	if(a < b && (a = 100)){
		printf("farsight\n");
	}
	printf("a = %d,b = %d\n",a,b);
	*/
	int a = 5,b = 3;
	if(a > b || (a = 100)){
		printf("内部语句\n");
	}
	printf("a = %d,b = %d\n",a,b);
	return 0;
}
