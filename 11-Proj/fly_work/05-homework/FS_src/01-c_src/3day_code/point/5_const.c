#include <stdio.h>

int main(void)
{
	const int  a = 100;    //const关键字使a变为只读数据
	
	//a = 200;		//错误的
	printf("a  = %d\n",a);

	int *p;
	p = &a;
	*p = 200;
	printf("a  = %d\n",a);
	return 0;
}
