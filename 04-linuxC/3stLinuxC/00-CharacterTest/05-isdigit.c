/*******************************************************************
 *   > File Name: 05-isdigit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 05 Feb 2017 03:16:39 PM CST
 ******************************************************************/

#include <stdio.h>
#include <ctype.h>

#if (0)
int isdigit(int c);/*测试字符是否为阿拉伯数字*/
#endif

int main(int argc, char* argv[])
{
    char str[] = "123@#FDsP[e";
    printf("String : %s\n",str);
    int i,ret;

    for(i = 0; str[i] != 0;i ++)
    {
        if(ret = isdigit(str[i]))
            printf("ret = %d %c is an digit character\n",ret,str[i]);
    }

    return 0;
}
