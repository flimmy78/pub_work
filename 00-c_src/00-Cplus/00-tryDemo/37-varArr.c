/*******************************************************************
 *   > File Name: 37-varArr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 05 May 2017 02:39:59 PM CST
 ******************************************************************/

#include <stdio.h>

void fun1(int n, int *b){
    int i;
    for(i = 0; i< n; i++){
        printf("%d\t", b[i]);
    }
    printf("\n");
}

void fun2(int n, int *b){
    int i;
    for(i = 0; i < n; i++){
        b[i] *= 2;
    }
    //printf("\n");
}

int main(int argc, char* argv[])
{
    int a[] = {1, 2, 3, 4, 5};

    fun1(5, a); //地址传递
    fun2(5, a);
    fun1(5, a);

    return 0;
}
