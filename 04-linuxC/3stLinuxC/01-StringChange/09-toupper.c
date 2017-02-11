/******************************************************************
 *   > File Name: 09-toupper.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 10 Feb 2017 09:34:04 AM CST
 ******************************************************************/

#include <stdio.h>
#include <ctype.h>

#if (0)
int toupper(int c);
#endif

int main(int argc, char* argv[])
{
    char s[] = "aBcDeFgH123456;!#$";
    int i;

    printf("Before toupper() :%s\n",s);
    for(i = 0; s[i] != 0; i++)
        s[i] = toupper(s[i]);
    printf("After toupper() :%s\n",s);

    return 0;
}
