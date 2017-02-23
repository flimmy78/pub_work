#include <stdio.h>

int main(void)
{
	int  a = 100,b = 300;    
	const int * const p =&a;    //const将p和*p都变为只读数据

//	*p = 200;   //err
//	p = &b;    //err
	printf("a  = %d\n",a);
	return 0;
}
