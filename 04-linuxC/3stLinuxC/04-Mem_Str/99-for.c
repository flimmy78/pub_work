/*******************************************************************
 *   > File Name: 99-for.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Mar 2017 02:12:15 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;

    for(i = 0; i <5; i++){
        printf("i = %d\n",i);
    }

    printf("out for i = %d\n",i);
    printf("out for i = %d\n",i);

    int j;
    for(j = 0; j < 5; ++j){
        printf("j = %d\n",j);
    }

    printf("out for j = %d\n",j);
    printf("out for j = %d\n",j);
    for(;;);
    

    return 0;
}
