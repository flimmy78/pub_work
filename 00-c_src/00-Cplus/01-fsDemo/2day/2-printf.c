/*******************************************************************
 *   > File Name: 2-printf.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 11:20:07 AM CST
 ******************************************************************/

#include <stdio.h>

/*说明：
 * int printf(const char *format, ...);//将程序中的数据输出到屏幕
 *%d:十进制
 *%o:八进制
 *%u:无符号十进制
 *%x:无符号十六进制
 *%c:字符
 *%s:字符串
 *%f:浮点数
 *%e:计数法的浮点数
 *%p:指针
 *printf修饰符：-、+、0、digit(s)、h、l、ll
 *int fprintf(FILE *stream, const char *format, ...);//输出到文件
 *int spritf(char *str, const char *format, ...);   //输出到内存空间
 *int snprintf(char *str, size_t size, const char *format, ...);//输出到内存空间
 * */

void print_test(void){
    int a;
    float b;
    double c;

    int ret;

    a = 123;
    b = 23.45;
    c = 123.456;

     ret = printf("a = %d, b = %f, c = %f\n", a, b, c);
   printf("  ret = %d\n",ret);
     ret = printf("a = %d, b = %f\n", 100, 100.123);
   printf("  ret = %d\n",ret);
     ret = printf("a = %d\n", 100 + 120);
   printf("  ret = %d\n",ret);
     ret = printf("%s\n", "hello world");
   printf("  ret = %d\n",ret);
     ret = printf("%%\n");
   printf("  ret = %d\n",ret);
}

int main(int argc, char* argv[])
{
    print_test();

    return 0;
}
