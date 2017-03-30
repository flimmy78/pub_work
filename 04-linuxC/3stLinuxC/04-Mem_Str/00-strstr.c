/*******************************************************************
 *   > File Name: 00-strstr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Feb 2017 04:52:37 PM CST
 ******************************************************************/
#if (0)
char *strstr(const char *haystack, const char *needle);
#endif
#include <stdio.h>
/*include for strstr*/
#include <string.h>

#define HEAD "NULL"

char *addroffset = NULL;

int main(int argc, char* argv[])
{
    char *str = "abcdefghjkl123\0456";
    printf("str :%s\n",str);
    printf("HEAD :%s\n",HEAD);

    /*在字符串str找到HEAD，返回位置指针*/
    addroffset = strstr(str,HEAD);
    if(addroffset == NULL){
        printf("strstr err");
    }

    printf("addroffset :%s\n",addroffset);
    
    /*指针后移，跳过HEAD*/
    addroffset += strlen(HEAD);
    printf("addroffset :%s\n",addroffset);

    return 0;
}
