/*******************************************************************
 *   > File Name: 06-arr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年04月24日 星期二 20时08分51秒
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{   
    int n[10];  /*n是包含10个整数的数组*/
    int i,j;

    /*init the member of array*/
    for(i = 0; i< 10; i++)
    {
        n[i] = i+100;
    }

    /*output the member of array*/
    for(j = 0; j< 10; j++)
    {
        printf("Element[%d] = %d\n", j, n[j]);
    }

    return 0;
}
