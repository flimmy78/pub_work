#include <stdio.h>

enum spectrum{ /* 定义一个枚举类型spectrum */
	red,		//0	默认值
	blue,		//1
	green,		//2
	yellow		//3
}color1;


int main(void)
{
	enum spectrum color2;   //color2为枚举变量，本质上也是整型变量
	
	color1 = 0;			//可读性差
	color1 = red;		//可读性好
	printf("color1 = %d\n",color1);

	color2 = 2;
	color2 = green;//可读性好
	printf("colorr2 = %d\n",color2);

	return 0;
}
