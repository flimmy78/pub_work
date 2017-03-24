/*******************************************************************
 *   > File Name: 01-gsensor_update_average.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 24 Mar 2017 10:20:17 AM CST
 ******************************************************************/

#include <stdio.h>

struct gsen_ave{
    int data[8];/*8次数据*/
    int ave;    /*平均值*/
    int sum;    /*总值*/
};

static void gsensor_update_average(int count, struct gsen_ave *ave, int x){
    int i;
    int old;

    i = count % 8;
    old = ave->data[i];
    ave->data[i] = x;

    if(count <= 8){
        ave->sum += x;
    }else{
        ave->sum = ave->sum + x - old;
    }
    ave->ave = (ave->sum) / 8;/*8次平均值*/
}



int main(int argc, char* argv[])
{
    return 0;
}
