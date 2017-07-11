/*******************************************************************
 *   > File Name: 14-break.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 10:16:02 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int i,j;

    i = 0;

    for(j = 0; j < 3; j ++){
        while(i < 10){
            i ++;
            if(i % 2 == 0)
                break;  //执行时，跳出一层循环
            printf("i = %d\n", i);
        }
        printf("while end\n");
    }
    printf("for end\n");

    return 0;
}
