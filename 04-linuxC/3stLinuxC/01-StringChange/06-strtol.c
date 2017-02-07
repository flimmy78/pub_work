/*******************************************************************
 *   > File Name: 06-strtol.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Feb 2017 12:28:04 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#if (0)
long int strtol(const char *nptr,char **endptr, int base);/*将字符串转换成长整型*/
//str 为要转换的字符串，endstr 为第一个不能转换的字符的指针，base 为字符串 str 所采用的进制。
#endif

int main(int argc, char* argv[])
{
#if (0)
    char a[] = "1000000000";
    char b[] = "1000000000";
    char c[] = "ffff";
    char **a1;
    char **b1;
    char **c1;

    printf("&a...%p sizeof a = %2d String a :%s\n",a,sizeof a,a);
    printf("&b...%p sizeof b = %2d String b :%s\n",b,sizeof b,b);
    printf("&c...%p sizeof c = %2d String c :%s\n",c,sizeof c,c);
    
    printf("a = %ld\n",strtol(a,NULL,10));
    printf("b = %ld\n",strtol(b,NULL,2));
    printf("c = %ld\n",strtol(c,NULL,16));
#endif

    char test[4]="abc";
    printf("&test...%p sizeof test = %d String test :%s\n",test,sizeof test,test);

    char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
    printf("&szNumbers ...%p sizeof szNumbers = %d String szNumber :%s\n",szNumbers,sizeof szNumbers,szNumbers);
    char *pEnd;
    long int li1,li2,li3,li4;
    li1 = strtol(szNumbers,&pEnd,10);
    printf("&pEnd...%p\n",pEnd);
    li2 = strtol(pEnd,&pEnd,16);
    printf("&pEnd...%p\n",pEnd);
    li3 = strtol(pEnd,&pEnd,2);
    printf("&pEnd...%p\n",pEnd);
    li4 = strtol(pEnd,NULL,0);

    printf("li1 = %ld li2 = %ld li3 = %ld li4 = %ld\n",li1,li2,li3,li4);

    return 0;
}
