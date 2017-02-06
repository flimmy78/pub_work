#if 0
//函数名: gcvt
//功 能: 把浮点数转换成字符串
//用 法: char *gcvt(double value, int ndigit, char *buf);
//程序例: 
#include <stdlib.h> 
#include <stdio.h>
int main(void)
{
	char str[25];
	double num;
	int sig = 5; /* significant digits */
	/* a regular number */
	num = 9.876;
	gcvt(num, sig, str);
	printf("string = %s\n", str);
	/* a negative number */
	num = -123.4567;
	gcvt(num, sig, str);
	printf("string = %s\n", str);
	/* scientific notation */
	num = 0.678e5;
	gcvt(num, sig, str);
	printf("string = %s\n", str);
	return(0);
}
//参数
//value——被转换的值。
//Digits——存储的有效数字位数。
//Buffe——结果的存储位置。
//说明
//gcvt函数把一个浮点值转换成一个字符串(包括一个小数点和可能的
//符号字节)并存储该字符串在buffer中。该buffer应足够大以便容纳转换
//的值加上结尾的空格字符,它是自动添加的。如果一个缓冲区的尺寸为
//digits的尺寸+1,该函数覆盖该缓冲区的末尾。这是因为转换的字符串包
//括一个小数点以及可能包含符号和指数信息。不提供上溢出。gcvt试图
//以十进制格式产生digits数字,如果不可能,它以指数格式产生digits数字,
//在转换时可能截除尾部的0。
#else
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    double a = 12.45781;
    double b = -12.56789;
    char ptr[20];
    //int decpt,sign;
    printf("a = %f\tb = %f\n",a,b);

    gcvt(a,5,ptr);
    printf("a value = %s\n",ptr);
    gcvt(b,6,ptr);
    printf("b value = %s\n",ptr);
}
#endif
