#include <stdio.h>

//函数中
void fun1(void)
{
	int c;	//自动存储类型    
}


int  main(void)
{
	int a;   //自动存储类型
	//无名的代码块中
	{
		int b;	//自动存储类型
	}

	//控制流语句中
	while(1){
		int i;	//自动存储类型
	}
}
