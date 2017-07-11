/*******************************************************************
 *   > File Name: 11-if.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 05:51:01 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int day;
    int ret;

    while(1){
        printf("Pls input integer:");
        ret = scanf("%d", &day);
        if(day == 1){
            printf("今天是周一\n");
        }else if(day == 2){
            printf("今天是周二\n");
        }else if(day == 3){
            printf("今天是周三\n");
        }else if(day == 4){
            printf("今天是周四\n");
        }else if(day == 5){
            printf("今天是周五\n");
        }else if(day == 6){
            printf("今天是周六\n");
        }else if(day == 7){
            printf("今天是周日\n");
        }else{
            printf("输入错误，重新输入！ret = %d\n",ret);
            if(ret != 1){
                //break;  //跳出循环
                fflush(NULL);
            }
        }
    }


    return 0;
}
