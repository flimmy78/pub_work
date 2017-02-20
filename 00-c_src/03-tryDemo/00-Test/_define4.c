/*	#ifdef 宏
 *		代码块A：	// 如果宏被定义，则编译代码块A
 *	#else
 *		代码块B：	//如果宏未被定义，则编译代码块B
 *	#endif
 *
 */
#include <stdio.h>

#define DEBUG

void fun1(void)
{
	printf("This is fun1 !\n");
}

void fun2(void)
{
	printf("This is fun2 !\n");
}

#ifdef DEBUG
int main(void)
{
	fun1();
	fun2();

	return 0;
}
#endif
