/*******************************************************************
 *   > File Name: 3-scanf.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 01:34:33 PM CST
 ******************************************************************/

#include <stdio.h>

/*说明：
 *int scanf(const char *format, ...);//从键盘接收数据
 *int fscanf(FILE *stream, const char *format,...);//从文件接收数据到程序中
 *int sscanf(const char *str, const char *format, ...);//从内存空间中接收数据到程序中
 * */

void scanf_test(void){
    int a, ret;
    float b;
    double c;

    ret = scanf("%d%f%lf",&a, &b, &c);
    printf("ret = %d\n", ret);
    printf("a = %d, b = %f, c= %f\n", a, b, c);
}

int main(int argc, char* argv[])
{
    scanf_test();

    return 0;
}
