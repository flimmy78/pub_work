//用变参函数实现，打印若干个整数
#include <stdio.h>
#include <stdarg.h>

//n为要打印的整数的个数
void myprint(int n,...)
{
	va_list p;
	int i;

	va_start(p,n);

	for(i = 0; i < n; i++)
		printf("%d\t",va_arg(p,int));
	printf("\n");
	va_end(p);
}

int main(void)
{
	myprint(5,10,11,12,13,14);
	myprint(7,10,11,12,13,14,15,16);
	return 0;
}
