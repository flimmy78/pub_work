/*******************************************************************
 *   > File Name: 01-isalnum.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 18 May 2017 11:25:08 AM CST
 ******************************************************************/
#if (0)
/*测试字符是否为英文或数字
 * 若参数c为字符或数字，则返回TRUE，否则返回NULL（0）；
 * */
int isalnum(int c);
#endif

#include <stdio.h>
/*INC for isalnum*/
#include <ctype.h>

int main(int argc, char* argv[])
{
    char str[] = "123@#$%^&AsdFG.\n";
    printf("str :%s",str);

    int i;
    for(i = 0; str[i] != '\0'; i++){
        if(isalnum(str[i])){
            printf("%c is an alphanummeric character\n", str[i]);
        }
    }

    return 0;
}
