/*******************************************************************
 *   > File Name: 18-getchar.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 16:24:00 2017
 ******************************************************************/
#if (0)
int getchar(void);  //由标准输入设备内读进一字符；
//用来从标准输入设备中读取一个字符。然后将该字符从
//unsigned char 转换成 int 后返回。
//会返回读取到的字符，若返回 EOF 则表示有错误发生。
//附加说明 getchar（）非真正函数，而是 getc（stdin）宏定义。
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    //FILE *fp;

    int c, i;
    for(i = 0; i< 5; i++){
        c = getchar();
        putchar(c);
    }

    return 0;
}
