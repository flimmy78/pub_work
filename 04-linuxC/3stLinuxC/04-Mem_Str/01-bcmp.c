/*******************************************************************
 *   > File Name: 01-bcmp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Feb 2017 04:24:38 PM CST
 ******************************************************************/
#if (0)
int bcmp(const void *s1, const void *s2, size_t n);
//@func:比较s1与s2内存前n个字节，
//相同返回0，若n为0，返回0，否则返回非0值
//返回-1，S1大于S2
//返回1，S1小于S2
#endif

#include <stdio.h>
/*include for bcmp*/
#include <strings.h>

#define S1  "abcdE6789"
#define S2  "abcde6789"
#define N   6

int main(int argc, char* argv[])
{
    int ret;
    
    ret = bcmp((const void *)S1, (const void *)S2, N);
    printf("ret = %d\n",ret);


#if (0)
    char *str1 = "abcde123456";
    char *str2 = "abcde7894567";
    int ret,n;

    printf("str1 :%s\nstr2 :%s\n",str1,str2);
    n = 5;
    /*比较字符串str1、str2前5个字节*/
    ret = bcmp((void*)str1,(void*)str2,n);
    if(ret != 0){
        printf("bcmp is error\n");return (-1);
    }else{
        printf("ret = %d %dbyte is same\n",ret,n);
    }

    n = 6;
    /*比较字符串str1、str2的前6个字节*/
    ret = bcmp((void*)str1,(void*)str2,n);
    if(ret != 0){
        printf("ret = %d bcmp is error\n",ret);return (-1);
    }
#endif

    return 0;
}
