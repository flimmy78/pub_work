/*******************************************************************
 *   > File Name: 16-fwrite.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 16:02:26 2017
 ******************************************************************/
#if (0)
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
//用来将数据写入文件流中。参数 stream 为已打开的文件
//指针，参数 ptr 指向欲写入的数据地址，总共写入的字符数以参数
//size*nmemb 来决定。fwrite（）会返回实际写入的 nmemb 数目。
//返回实际写入的 nmemb 数目
#endif

#include <stdio.h>
#define set_s(x,y) {strcpy();s[x].size = strlen(y);}
#define nmemb 3

struct test{
    char name[20];
    int size;
}s[nmemb];

int main(int argc, char* argv[])
{
    FILE *stream;
    set_s(0,"Linux!");
    set_s(1, "FreeBSD!");
    set_s(2, "Windows2000.");

    stream = fopen("/tmp/fwrite", "w");
    fwrite(s, sizeof(struct test), nmemb, stream);
    fclose(stream);

    return 0;
}
