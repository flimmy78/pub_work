#include <stdio.h>

typedef void (*TF)(void);

/*修饰指针：表示定义一个通用的指针，即，该指针中可以存储任何类型的地址*/

void fun(void)
{
	printf("Hello World !\n");
}

int main(void)
{
	void *p;	//定义通用指针p，p中可以存储内存中的任何类型的地址

	int a = 100;
	int *p1 = &a;
	p = &a;		//p中存放整型变量的地址

	printf("%d\n",*(int *)p);
	printf("%d\n\n",*p1);

	p = &p1;	//p中存放整形指针变量地址
	printf("%d\n\n",**(int **)p);

	char ch	= 'H';
	p = &ch;	//p中存放字符型变量的地址
	printf("%c\n\n",*(char *)p);

	float f = 12.345;
	p = &f;		//p中存放浮点型变量的地址
	printf("%f\n\n",*(float *)p);

	p = fun;
	((TF)p)();

	return 0;
}
