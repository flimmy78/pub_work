/*******************************************************************
 *   > File Name: 02-fclose.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 12:02:22 2017
 ******************************************************************/
#if (0)
int fclose(FILE *fp);   //关闭文件
//用来关闭先前 fopen（）打开的文件。此动作会让缓冲区
//内的数据写入文件中，并释放系统所提供的文件资源。
//若关文件动作成功则返回 0，有错误发生时则返回 EOF 并把错误代
//码存到 errno。
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    return 0;
}
