/*******************************************************************
 *   > File Name: 7-arr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 06:11:30 PM CST
 ******************************************************************/

#include <stdio.h>

void fun(int n, int b[]){
    int i;

    for(i = 0; i< n; i++){
        printf("%d\t", b[i]);
    }

    printf("\n");
}

int main(int argc, char* argv[])
{
    int a[] = {1, 2, 3, 4}; //完全初始化

    fun(4, a);  //数组传参：数组名和元素个数

    return 0;
}
