/*******************************************************************
 *   > File Name: 01-recursionFunc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 16 Sep 2017 05:19:38 PM CST
 ******************************************************************/

#include <stdio.h> 

void fun(int n){
    printf("n = %d\n", n);
    n --;
    if(n > 0){
        fun(n);
    }
}

int main(int argc, char* argv[])
{
    fun(5);
    return 0;
}
