/*******************************************************************
 *   > File Name: 09-pascalTriangle.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue Jan 23 17:35:12 2018
 ******************************************************************/

#include <stdio.h>

int c(int x, int y);

int main(int argc, char* argv[])
{
    int a,b;
    printf("Pls input(a,b):");
    scanf("%d,%d", &a, &b);

    printf("c(%d, %d) = %d\n", a,b, c(a,b));

    return 0;
}



int c(int x, int y){
    /*X代表行数，Y代表第X行的第Y个值*/
    int z;

    if(y > x+1){/*第x行最多有x+1个数*/
        printf("Param_in(@y) Error !\r\n");
        return (-1);
    }

    if((y == 1) || (y == x + 1)){
        return (1);
    }

    z = c(x-1, y -1) + c(x-1, y);

    return z;
}

void printf_blank(int x){
}
