/*******************************************************************
 *   > File Name: 12-switch.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 08:34:58 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int day;
    int ret;

    while(1){
        printf("Pls input a integer(1~7):");
        ret = scanf("%d", &day);
        switch(day){
            case 1:
                printf("Today is Moday\n");
                break;
            case 2:
                printf("Today is Tuesday\n");
                break;
            case 3:
                printf("Today is Wndnesday\n");
                break;
            case 4:
                printf("Today is Thursday\n");
                break;
            case 5:
                printf("Today is Friday\n");
                break;
            case 6:
                printf("Today is Saturday\n");
                break;
            case 7:
                printf("Today is Sunday\n");
                break;
            default:
                printf("Input err, pls input again!\n");
        }
        if(ret != 1){
            break;
        }
    }

    return 0;
}
