/*******************************************************************
 *   > File Name: 08-tolower.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 10 Feb 2017 09:27:08 AM CST
 ******************************************************************/

#include <stdio.h>
#include <ctype.h>

#if (0)
#include <ctype.h>

int toupper(int c);
int tolower(int c);
#endif

int main(int argc, char* argv[])
{
    char s[] = "aBcDeFgH123456;!#$";
    int i;
    
    printf("Before tolower() :%s\n",s);
    for(i = 0; s[i] != 0; i++)
        s[i] = tolower(s[i]);
    printf("After tolower() :%s\n",s);

    return 0;
}
