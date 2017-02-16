#include <stdio.h>

//函数中
void fun1(void)
{
	register int c;	//寄存器存储类型    
}


int  main(void)
{
	register int a;   //寄存器存储类型
	//无名的代码块中
	{
		register int b;	//寄存器存储类型
	}

	//控制流语句中
	while(1){
		register int i;	//寄存器存储类型
	}
}
