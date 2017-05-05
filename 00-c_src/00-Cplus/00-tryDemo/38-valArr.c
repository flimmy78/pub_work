/*******************************************************************
 *   > File Name: 38-valArr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 05 May 2017 02:49:12 PM CST
 ******************************************************************/

#include <stdio.h>

void fun1(int n, int m, int (*b)[m]){
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
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

    fun1(2, 3, a);

    return 0;
}
