/*******************************************************************
 *   > File Name: 02-isalpha.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 18 May 2017 01:10:41 PM CST
 ******************************************************************/
#if (0)
/*@FUNC:测试字符是否为英文字母；
 *@return：若参数c为英文字母，则返回TRUE，否则返回NULL（0）；
 * */
int isalpha(int c);
#endif

#include <stdio.h>
/*INC for isalpha*/
#include <ctype.h>

int main(int argc, char* argv[])
{
    char STR[] = "!@#%1ASghj789.\n";
    printf("STR :%s",STR);

    int i;
    for(i = 0; STR[i] != '\0'; i++){
        if(isalpha(STR[i])){
            printf("%c is an alphabetic character .\n", STR[i]);
        }
    }

    return 0;
}
