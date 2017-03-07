/*******************************************************************
 *   > File Name: 03-bzero.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Feb 2017 02:19:59 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

#if (0)
#include <strings.h>
void bzero(void *s, size_t n);
//@function:将s所指的内存区域的前n个字节置为0
#endif

int main(int argc, char* argv[])
{
    char ZERO = 0;
    printf("\"Zero\":%d\n",ZERO);

    char STR[10] = "ABCDEFGHIJ";
    printf("%s\n",STR);
    printf("sizeof STR %d\tsizeof STR[10] %d\n",sizeof(STR),sizeof STR[10]);
    printf("strlen STR %d\tbyte\n",strlen(STR));
    /*将字符串STR处sizeof STR个字节置0*/
    bzero(STR,sizeof STR);
    printf("Bzero :%s\n",STR);

    int i;
    for(i=0 ; i < 15; i++){
        printf("%d--%d\n",i,STR[i]);
    }

    return 0;
}
