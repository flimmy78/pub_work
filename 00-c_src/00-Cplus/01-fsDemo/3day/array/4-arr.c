/*******************************************************************
 *   > File Name: 4-arr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 03:40:00 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a[5], i;

    //a = {1, 2, 3, 4, 5};  //err
    //a[5] = {1, 2, 3, 4, 5};   //err
    for(i = 0; i< 5; i++){
        printf("Pls input a[%d] for Arr :", i);
        //a[i] = i + 1;
        scanf("%d", &a[i]);
    }

    for(i = 0; i< 5; i++){
        printf("%d\t", a[i]);
    }
    puts("");

    return 0;
}
