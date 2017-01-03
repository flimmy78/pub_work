/*
 *int →unsigned int → long → unsigned long → long long → unsigned long long → float → double → long double
*由系统自动进行数据类型转换称为隐式转换（如上，从左止右，低精度向高精度）
*强制类型转换（如上，从右至左 ）
 */
#include <stdio.h>

int main(void)
{
	int a = 10;
	float b = 12.9;

	printf("\na = %d\tb = %f\t(int)b = %d\n",a,b,(int)b);
	printf("a + (int)b = %d\n",a + (int)b);		//强制类型转换

	return 0;
}
