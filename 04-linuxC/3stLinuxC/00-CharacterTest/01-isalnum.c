/*******************************************************************
 *   > File Name: 01-isalnum.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 05 Feb 2017 02:21:12 PM CST
 ******************************************************************/

#include <stdio.h>
#include <ctype.h>

#if (0)
int isalnum(int c);/*测试字符是否为英文或数字*/
#endif

int main(int argc, char* argv[])
{   
    int ret, i;
    char str[] = "123c@#FDsP[e?";
    printf("String : %s\n",str);
    
    for(i = 0;str[i] != 0; i++)
    {
        if(ret = isalnum(str[i]))
            printf("ret = %d  %c is an alphanumeric character\n",ret, str[i]);
        else
            printf("ret = %d\n",ret);
    }

    return 0;
}
