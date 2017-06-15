/*******************************************************************
 *   > File Name: 11-isupper.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 11:30:29 2017
 ******************************************************************/
#if (0)
int isupper(int c);
//是否为大写字母；
#endif

#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    char str[] = "123@#FDsP[e?";
    int i;
    
    printf("%s\n", str);
    for(i = 0; str[i] != 0; i++){
        if(isupper(str[i])){
            printf("%c is an uppercase character\n", str[i]);
        }
    }

    return 0;
}
