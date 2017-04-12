/*******************************************************************
 *   > File Name: 27-bool.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 12 Apr 2017 09:51:11 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static inline bool isLarge(int a, int b){
    return (a > b);
}

int main(int argc, char* argv[])
{   
    if(argc < 3){
        printf("Usage :%s <Val1> <Val2>\n", argv[0]);exit(-1);
    }

    printf("return :%d\n", isLarge(atoi(argv[1]) ,atoi(argv[2])));

    return 0;
}
