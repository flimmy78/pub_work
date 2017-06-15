/*******************************************************************
 *   > File Name: 02-bcopy.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 10:29:43 2017
 ******************************************************************/
#if (0)
void bcopy(const void *src, void *dest, size_t n);
//@RETURN:用来拷贝 src 所指的内存内容前 n
//个字节到 dest 所指的地址，不过参数 src 与 dest 在传给函数时是相
//反的位置
#endif

#include <stdio.h>
#include <strings.h>
#include <string.h>

int main(int argc, char* argv[])
{
#if 0
    char src[] = "123456789QAZWSXCDE";
    char dest[] = "qazwsxedc123456789";

    printf("src:%s\ndest:%s\n", src, dest);
    bcopy((void*)src,(void*)dest, sizeof(dest));
    printf("After bcopy()\nsrc:%s\ndest:%s\n", src, dest);
#endif

    char dest[30] = "string(a)";
    char src[30] = "string\0string";
    printf("dest -> %s\nsrc -> %s\n", dest, src);

    int i;
    bcopy(src, dest, 30);
    printf("bcopy()");
    for(i = 0; i< 30; i++){
        printf("%c", dest[i]);
    }
    memcpy(dest, src, 30);
    printf("\n");
    for(i = 0; i< 30; i++){
        printf("%c",dest[i]);
    }

    return 0;
}
