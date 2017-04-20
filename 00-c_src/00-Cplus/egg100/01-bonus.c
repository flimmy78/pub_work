/*******************************************************************
 *   > File Name: 01-bonus.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 05:41:50 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{

    double i;
    double bonus, bonus1, bonus2, bonus3, bonus4, bonus5, bonus6;

    printf("Pls input your retained profits :");
    scanf("%lf", &i);

    bonus1 = 100000 * 0.1;
    bonus2 = bonus1 + 100000 * 0.075;
    bonus3 = bonus2 + 200000 * 0.05;
    bonus4 = bonus3 + 200000 * 0.03;
    bonus5 = bonus4 + 400000 * 0.015;
    
    if(i <= 100000){
        bonus = i * 0.1;
    }else if( 100000< i <= 200000){
        bonus = bonus1 + (i - 100000) * 0.075;
    }else if( 200000< i <= 400000){
        bonus = bonus2 + (i - 200000) * 0.05;
    }else if( 400000< i <= 600000){
        bonus = bonus3 + (i - 400000) * 0.03;
    }else if( 60000< i <= 1000000){
        bonus = bonus4 + (i - 600000) * 0.015;
    }else if(i > 1000000){
        bonus = bonus5 + (i - 1000000) * 0.01;
    }
    
    printf("提成为：%lf\n", bonus);
    return 0;
}
