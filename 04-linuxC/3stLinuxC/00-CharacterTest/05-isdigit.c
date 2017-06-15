/*******************************************************************
 *   > File Name: 05-isdigit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun  7 11:10:15 2017
 ******************************************************************/
#if (0)
int isdigit(int c);
//@FUNC:检查参数c是否为数字0到9；
//@Return:为真，返回TRUE；否则，返回NULL；
#endif

#include <stdio.h>
/*INC for isdigit*/
#include <ctype.h>

int main(int argc, char* argv[])
{   
    char str[] = "123@#FDsP[e?";
    int i;
    
    /*对字符串中的字符进行测试*/
    for(i = 0; str[i] != 0; i++){
        if(isdigit(str[i])){
            printf("%c is digit character\n", str[i]);
        }
    }

    return 0;
}
