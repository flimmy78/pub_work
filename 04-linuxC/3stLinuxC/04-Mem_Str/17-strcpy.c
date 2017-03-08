/*******************************************************************
 *   > File Name: 17-strcpy.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 08 Mar 2017 10:03:14 AM CST
 ******************************************************************/
#if (0)
char *strcpy(char *dest, const char *src);
//@FUNC:复制字符串src（包括'\0'）,如果dest指向的空间不够大
//可能会溢出，建议使用strncpy（）；
//@Return:返回指针dest

char *strncpy(char *dest, const char *src, size_t n);
#endif

#include <stdio.h>
/*INC for strcpy*/
#include <string.h>

char *mystrncpy(char *dest, const char *src, size_t n){
    size_t i;
    
    /*复制src的n个字节到dest，直到遇到结束符*/
    for(i = 0; i < n && src[i] != '\0'; i++){
        dest[i] = src[i];
        printf("[%c]-%d  ",dest[i],dest[i]);
    }
    for(;i < n; i++){
        dest[i] = '\0';
        printf("[%c]-%d  ",dest[i],dest[i]);
    }
    puts("");
    return dest;
}

int main(int argc, char* argv[])
{
    char S1[30] = "STRING[a]IHaveAGoodIdear";
    char S2[] = "string[b]";
    
    printf("Before copy :%s\n",S1);
#if (0)
    printf("strcpy :%s\n",strcpy(S1, S2));
#else
    //printf("strncpy :%s\n",strncpy(S1, S2, 5));
    //printf("strncpy :%s\n",strncpy(S2, S1, 30));
    printf("mystrncpy :%s\n",mystrncpy(S2, S1, 30));
#endif

    return 0;
}
