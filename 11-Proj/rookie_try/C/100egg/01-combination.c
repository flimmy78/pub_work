/*******************************************************************
 *   > File Name: 01-combination.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2017年06月28日 星期三 19时23分06秒
 ******************************************************************/
#if (0)
1、2、3、4能够组成多少个互不相同且无重复数字的三位数
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    int i,j,k;
    printf("\n");

    for(i = 1; i< 5; i++){
        for(j = 1; j< 5; j++){
            for(k = 1; k< 5; k++){
                if(i != k && i != j && k != j){
                    printf("%d, %d, %d\n", i, j, k);
                }
            }
        }
    }
    

    return 0;
}
