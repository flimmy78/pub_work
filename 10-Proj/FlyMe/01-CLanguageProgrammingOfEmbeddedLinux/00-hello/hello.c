#define DEBUG

#ifdef DEBUG	/*如果宏被定义，则编译A*/
#include <my.h>	/*代码块A*/
#else
#include "my.h"	/*代码块B*/
#endif

int main(void)
{
	printf("Hello , world !\n");
	return 0;
}
