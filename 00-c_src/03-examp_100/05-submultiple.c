/*******************************************************************
 *   > File Name: 05-submultiple.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 15 Oct 2017 10:47:40 PM CST
 ******************************************************************/

#include <stdio.h>

/*555 555的约数中最大的三位数是多少？
 * */

int main(int argc, char* argv[])
{
    long i; /*使用长整型变量，以免超出整数的表示范围*/
    int j;

    printf("Pls input number :");
    scanf("%ld", &i);
    for(j = 999; j >= 100; j --){
        if(i % j == 0){ /*所求的约数的可能取值是从999到100，j从大到小*/
            printf("The max factor with 3 digits is %ld is :%d .\n", i, j);
            break;/*跳出for循环*/
        }
    }

    return 0;
}
