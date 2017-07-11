/*******************************************************************
 *   > File Name: 6-str.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 05:42:52 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a[2][3];

    int i,j;

    for(i = 0; i< 2; i++){
        for(j = 0; j< 3; j++){
            printf("Pls input:");
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i< 2; i++){
        for(j = 0; j< 3; j++){
            printf("%d\t", a[i][j]);
        }
        puts("");
    }

    return 0;
}
