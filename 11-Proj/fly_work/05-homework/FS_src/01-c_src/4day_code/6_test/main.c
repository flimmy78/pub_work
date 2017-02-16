#include <stdio.h>

extern int x1;   //外部存储类型
//extern int x2;
extern void fun2(void);
extern void fun3(void);
void fun1(void)
{
	int a;	//自动存储类型
	static int b;	//局部static静态存储类型

}

int main(void)
{
	register int i;	//寄存器存储类型
	fun2();
	fun3();
	printf("x1 = %d\n",x1);
//	printf("x2 = %d\n",x2);
	return 0;
}
