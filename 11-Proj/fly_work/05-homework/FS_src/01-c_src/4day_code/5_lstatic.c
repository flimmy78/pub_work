#include <stdio.h>

//函数中
void fun1(void)
{
	static int c;	//局部static静态存储类型    
}


int  main(void)
{
	static int a;	//局部static静态存储类型    
	//无名的代码块中
	{
		static int b;	//局部static静态存储类型    
	}

	//控制流语句中
	while(1){
		static int i;	//局部static静态存储类型    
	}
}
