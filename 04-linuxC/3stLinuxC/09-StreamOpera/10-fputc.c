/*******************************************************************
 *   > File Name: 10-fputc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 14:13:02 2017
 ******************************************************************/
#if (0)
int fputc(int c, FILE *stream);     //将一指定字符写入文件流中
//参数 c 转为 unsigned char 后写入参数 stream 指定的文件中。
//fputc（）会返回写入成功的字符，即参数 c。若返回 EOF 则代表写
//入失败
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    char a[26] = "abcdefghijklmnopqrstuvwxyz";
    int i;
    fp = fopen("test.file", "w");

    for(i = 0; i < 26; i++){
        fputc(a[i], fp);
    }
    fclose(fp);

    return 0;
}
