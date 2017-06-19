/*******************************************************************
 *   > File Name: 12-fread.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 14:43:43 2017
 ******************************************************************/
#if (0)
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
//从文件流中读取数据。参数 stream 为已打开的文件指
//针，参数 ptr 指向欲存放读取进来的数据空间，读取的字符数以参
//数 size*nmemb 来决定。fread（）会返回实际读取到的 nmemb 数目，
//如果此值比参数 nmemb 来得小，则代表可能读到了文件尾或有错
//误发生，这时必须用 feof（）或 ferror（）来决定发生什么情况。
//返回实际读取到的 nmemb 数目。
#endif

#include <stdio.h>
#define nmemb   3

struct test{
    char name[20];
    int size;
}s[nmemb];

int main(int argc, char* argv[])
{
    FILE *stream;
    int i;

    stream = fopen("/tmp/fwrite", "r");
    fread(s, sizeof(struct test), nmemb, stream);

    fclose(stream);

    for(i = 0; i < nmemb; i++){
        printf("name[%d] = %-20s:size[%d] = %d\n", i, s[i].name, i, s[i].size);
    }

    return 0;
}
