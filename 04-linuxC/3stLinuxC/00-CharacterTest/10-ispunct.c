/*******************************************************************
 *   > File Name: 10-ispunct.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 05 Feb 2017 03:52:43 PM CST
 ******************************************************************/

#include <stdio.h>

#if (0)
int ispunct(int c);/*测试字符是否为标点符号或特殊字符*/
#endif

int main(int argc, char* argv[])
{
    char str[] = "123c@#FDsP[e?";
    printf("String : %s\n",str);
    int i,ret;

    for(i = 0; str[i] != 0; i++)
    {
        if(ret = ispunct(str[i]))
            printf("ret = %d %c\n",ret,str[i]);
    }
    return 0;
}
