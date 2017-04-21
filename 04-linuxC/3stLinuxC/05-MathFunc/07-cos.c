/*******************************************************************
 *   > File Name: 07-cos.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Apr 2017 03:28:19 PM CST
 ******************************************************************/

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double input = 0.0;
    double value = 0.0;

    while(1){
        printf("Pls input a double integer :");
        if((scanf("%lf", &input)) != 1){
            printf("Input err\n");break;
        }

        value = cos(input);
        printf("cos(%lf) = %lf\n", input, value);
    }

    return 0;
}
