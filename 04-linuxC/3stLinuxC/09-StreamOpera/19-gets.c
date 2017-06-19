/*******************************************************************
 *   > File Name: 19-gets.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 16:32:59 2017
 ******************************************************************/
#if (0)
char *gets(char *s);    //由标准输入设备内读进一字符串
//用来从标准设备读入字符并存到参数 s 所指的内存空间，
//直到出现换行字符或读到文件尾为止，最后加上 NULL 作为字符串结束。
//gets（）若成功则返回 s 指针，返回 NULL 则表示有错误发生。
//由于 gets（）无法知道字符串 s 的大小，必须遇到换行字符或文件
//尾才会结束输入，因此容易造成缓冲溢出的安全性问题。建议使用fgets（）取代。
#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{


    return 0;
}
