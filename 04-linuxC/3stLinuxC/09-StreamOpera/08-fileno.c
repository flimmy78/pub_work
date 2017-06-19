/*******************************************************************
 *   > File Name: 08-fileno.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 13:46:27 2017
 ******************************************************************/
#if (0)
int fileno(FILE *stream);   // 返回文件流所使用的的文件描述词
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    int fd;

    fp = fopen("/etc/passwd", "r");
    fd = fileno(fp);
    printf("fd = %d\n", fd);
    fclose(fp);

    return 0;
}
