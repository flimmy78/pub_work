/*******************************************************************
 *   > File Name: 06-fgetc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 13:19:41 2017
 ******************************************************************/
#if (0)
int fgetc(FILE *stream);    //由文件中读取一个字符
//从参数 stream 所指的文件中读取一个字符。若读到文
//件尾而无数据时便返回 EOF
#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    int c;

    fp = fopen("test.file", "r");
    if(fp == NULL){
        perror("fopen");exit(EXIT_FAILURE);
    }

    /*输出文本文件中的所有字符*/
    while((c = fgetc(fp)) != EOF)
        printf("%c", c);

    fclose(fp);

    return 0;
}
