/*******************************************************************
 *   > File Name: 61-strcmp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年04月27日 星期五 11时42分15秒
 ******************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char s1[]="a";
    char s2[]="b";
    char s3[]="c";
    char s4[]="a";
    char s5[]="A";

    int ret;

    ret = strcmp(s1, s2);
    printf("ret = %d\n", ret);

    ret = strcmp(s1, s3);
    printf("ret = %d\n", ret);

    ret = strcmp(s1, s4);
    printf("ret = %d\n", ret);

    ret = strcmp(s1, s5);
    printf("ret = %d\n", ret);

    return 0;
}
