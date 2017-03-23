/*******************************************************************
 *   > File Name: 01-abs.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 22 Feb 2017 01:50:03 PM CST
 ******************************************************************/
#if (0)
/*计算整型数的绝对值*/
#include <stdlib.h>

int abs(int j);
//计算j的绝对值，然后将结果返回
long int labs(long int j);
long long int llabs(long long int j);

#include <inttypes.h>

intmax_t imaxabs(intmax_t j);
#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int answer,res;
#if (0)
    answer = -100;

    printf("|%d| = %d\n",answer,abs(answer));
#else
    int count = 10;
    while(count--){
        printf("(%d). Please input a integer :  ",count);
        if((res = scanf("%d",&answer)) != 1){
            puts("input error");break;
        }
        printf("|%d| = %d\n",answer,abs(answer));
    }
#endif

    return 0;
}
