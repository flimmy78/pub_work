/*******************************************************************
 *   > File Name: 02-isalpha.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 05 Feb 2017 02:38:57 PM CST
 ******************************************************************/

#include <stdio.h>
#include <ctype.h>

#if (0)
int isalpha(int c);/*测试字符是否为英文字母*/
#endif

int main(int argc, char* argv[])
{
    char str[] = "123c@#FDsP[e";
    printf("String : %s\n",str);
    int i,ret;

    for(i = 0; str[i] != '\0';i++)
    {
        if(ret = isalpha(str[i]))
            printf("ret = %d  %c is an alphanumeric character\n",ret,str[i]);
    }
    return 0;
}
