/*******************************************************************
 *   > File Name: 10-arrPointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年05月07日 星期一 11时17分19秒
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{   
    /*带有5个元素的整型数组*/
    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p;
    int i;

    p = balance;

    /*输出数组中每一个元素的值*/
    printf("使用指针的数组值\n");
    for(i = 0; i< 5; i++)
    {
        printf("*(p + %d) :%f\n", i, *(p+i));
    }

    printf("使用balance作为地址的数组值\n");
    for(i = 0; i< 5; i++)
    {
        printf("*(balance + %d) : %f\n", i, *(balance + i));
    }


    return 0;
}
