/*******************************************************************
 *   > File Name: 20-strtok.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 01:22:50 PM CST
 ******************************************************************/
#if (0)
char *strtok(char *str, const char *delim);
//@FUNC:
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char s[] = "ab-cd:ef;gh:i-jkl;mnop;qrs-tu:vwx-y;z";
    char *delim = "-:";
    char *p;
    
    printf("%s\n", s);
    printf("%s\n\n", strtok(s, delim));
    while((p = strtok(NULL, delim)))
        printf("%s", p);
    printf("\n");

    return 0;
}
