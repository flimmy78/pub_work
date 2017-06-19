/*******************************************************************
 *   > File Name: 06-fgets.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 13:38:16 2017
 ******************************************************************/
#if (0)
int fputs(const char *s, FILE *stream);
char *fgets(char *s , int size, FILE *stream);  //由文件中读取一字符串
//从参数 stream 所指的文件内读入字符并存到参数 s 所
//指的内存空间，直到出现换行字符、读到文件尾或是已读了 size-1
//个字符为止，最后会加上 NULL 作为字符串结束。
//fgets（）若成功则返回 s 指针，返回 NULL 则表示有错误发生
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    char s[8];
    fputs(fgets(s, 8, stdin), stdout);

    return 0;
}
