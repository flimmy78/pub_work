/*******************************************************************
 *   > File Name: 03-isascii.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 18 May 2017 01:54:29 PM CST
 ******************************************************************/
#if (0)
/*@FUNC：检查参数c是否为ASCII码字符，判断c的范围是否在0到127之间；
 *@return：若参数c为ASCII码字符，则返回TRUE；否则返回NULL(0);
 * */
int isascii(int c);
#endif

#include <stdio.h>
/*INC for isascii*/
#include <ctype.h>

int main(int argc, char* argv[])
{
    int i;
    for(i = 125; i< 130; i++){
        if(isascii(i))
            printf("%c is ASCII character\n", i);
        else
            printf("%c is not ASCII character\n", i);
    }

    return 0;
}
