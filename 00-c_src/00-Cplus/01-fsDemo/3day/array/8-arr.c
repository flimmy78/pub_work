/*******************************************************************
 *   > File Name: 8-arr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 10:34:28 PM CST
 ******************************************************************/

#include <stdio.h>

void fun(int n, int m, int b[][m]){
    int i,j;

    for(i = 0; i< n; i++){
        for(j = 0; j< m; j++){
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    int a[][3] = {{1, 2, 3},{4, 5, 6}}; //完全初始化

    fun(2, 3, a);   //数组传参

    return 0;
}
