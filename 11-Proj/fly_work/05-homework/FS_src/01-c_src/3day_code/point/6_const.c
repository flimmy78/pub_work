#include <stdio.h>

int main(void)
{
	int  a = 100;    
	//int const *p = &a;   // *p为只读,等价与下面的语句
	const int *p =&a;

//	*p = 200;   //err
	a = 200;
	printf("a  = %d\n",a);
	return 0;
}
