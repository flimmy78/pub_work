/*******************************************************************
 *   > File Name: 00-combination.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 05:16:30 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{   
    /*1,2,3,4个数，组合无重复的三位数*/
    int i,j,k;
    int n = 0;
    printf("\n");

    for(i = 0; i< 5; i++){
        for(j = 0; j< 5; j++){
            for(k = 0; k< 5; k++){
                if(i != j && j != k && i != k){
                    printf("%4d :%d%d%d\n", n++, i, j, k);
                }
            }
        }
    }

    return 0;
}
