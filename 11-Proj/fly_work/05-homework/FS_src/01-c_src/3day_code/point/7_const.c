#include <stdio.h>

int main(void)
{
	int  a = 100,b = 300;    
	int * const p =&a;    //const将p变为只读数据

	*p = 200;   
	//p = &b;    //err
	printf("a  = %d\n",a);
	return 0;
}
