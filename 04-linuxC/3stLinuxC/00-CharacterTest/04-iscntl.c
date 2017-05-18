/*******************************************************************
 *   > File Name: 04-iscntl.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 18 May 2017 02:02:29 PM CST
 ******************************************************************/
#if (0)
/*@FUNC:测试字符是否为ASCII码的控制字符；
 *@return：若是，返回TRUE；否则，返回NULL(0);
 * */
int iscntrl(int c);
#endif

#include <stdio.h>
/*INC for iscntrl*/
#include <ctype.h>

int main(int argc, char* argv[])
{
    int i;
    
    int step;
    step = 1;

    for(i = 0; i < 50; i+=step){
        if(iscntrl(i)){
            printf("%d--%c is a control character\n", i,i);
        }else{
            printf("%d--%c is not a control character\n", i,i);
        }
    }

    return 0;
}
