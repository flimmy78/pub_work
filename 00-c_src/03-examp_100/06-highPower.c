/*******************************************************************
 *   > File Name: 06-highPower.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue Jan  9 11:49:01 2018
 ******************************************************************/

/*Note:求13的13次方的最后三位数
 *规律：乘积的最后三位的值只与乘数和被乘数的后三位有关，与其高位无关
 * */
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i, x,y,last = 1;    /*变量last保存求X的Y次方过程中的部分积的后三位*/
    printf("Input X and Y (X**Y):");
    scanf("%d**%d", &x,&y);

    for(i = 1; i<= y; i++){
        last = last *x %1000;   /*取值求模，*/
    }

    printf("The last 3 digits of %d**%d is :%d\n", x, y, last%1000);

    return 0;
}
