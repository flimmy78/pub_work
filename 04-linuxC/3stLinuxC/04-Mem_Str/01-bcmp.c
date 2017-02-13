/*******************************************************************
 *   > File Name: 01-bcmp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Feb 2017 04:24:38 PM CST
 ******************************************************************/

#include <stdio.h>

#if (0)
int bcmp(const void *s1, const void *s2, size_t n);
//@func:比较s1与s2内存前n个字节，
//相同返回0，若n为0，返回0，否则返回非0值
#endif

int main(int argc, char* argv[])
{
    char *str1 = "abcde123456";
    char *str2 = "abcde7894567";
    int ret,n;

    printf("str1 :%s\nstr2 :%s\n",str1,str2);
    n = 5;
    ret = bcmp((void*)str1,(void*)str2,n);
    if(ret != 0)
    {
        printf("bcmp is error\n");
        return (-1);
    }
    else
    {
        printf("%dbyte is same\n",n);
    }

    n = 6;
    ret = bcmp((void*)str1,(void*)str2,n);
    if(ret != 0)
    {
        printf("bcmp is error\n");
        return (-1);
    }

    return 0;
}
