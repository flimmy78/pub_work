#include <stdio.h>

void fun(int x,int y)
{
	printf("%d\t%d\n",x,y);
}


int main(void)
{
	int a = 5,b = 3;	
	//fun(a,b);
	
	void (*p)(int,int);    //p为函数指针
	p = fun;
	p(a,b); 
	return 0;
}
