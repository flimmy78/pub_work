/*******************************************************************
 *   > File Name: 04-iscntrl.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 05 Feb 2017 03:00:16 PM CST
 ******************************************************************/

#include <stdio.h>
#include <ctype.h>

#if (0)
int iscntrl(int c); /*测试字符是否为ascii码的测试字符*/
#endif

int main(int argc, char* argv[])
{
    int i,ret;

    for(i = 0; i<200; i++)
    {
        if(ret = iscntrl(i))
            printf("ret = %d %3d is an ascii control character\n",ret,i);
    }
    return 0;
}
