#include <stdio.h>

//#define DEBUG

//有如下两个函数， 如果要测试这两个函数是否正确，则必须要写主函数测试
void fun1(void)
{
	printf("hello world\n");
}

void fun2(void)
{
	printf("farsight\n");
}

//下面为测试代码
#ifdef DEBUG
int main(void)
{
	fun1();
	fun2();
	return 0;
}
#endif
