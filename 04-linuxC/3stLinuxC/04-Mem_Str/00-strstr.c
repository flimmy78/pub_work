/*******************************************************************
 *   > File Name: 00-strstr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Feb 2017 04:52:37 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

#define HEAD "cdef"

char *addroffset = NULL;

int main(int argc, char* argv[])
{
    char *str = "abcdefghjkl123456";
    printf("str :%s\n",str);
    printf("HEAD :%s\n",HEAD);

    addroffset = strstr(str,HEAD);
    if(addroffset == NULL)
    {
        printf("strstr err");
    }

    printf("addroffset :%s\n",addroffset);

    addroffset += strlen(HEAD);
    printf("addroffset :%s\n",addroffset);

    return 0;
}
