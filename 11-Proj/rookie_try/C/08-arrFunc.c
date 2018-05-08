/*******************************************************************
 *   > File Name: 08-arrFunc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年04月24日 星期二 20时21分23秒
 ******************************************************************/

#include <stdio.h>

double getAverage(int arr[], int size);

int main(int argc, char* argv[])
{
    int balance[5] = {1000, 2 , 3 , 17 , 50};
    double avg;

    avg = getAverage(balance, 5);

    printf("平均值是: %f\n", avg);

    return 0;
}

/*它把数组作为参数，同时还传递了另一个参数，
根据所传的参数，会返回数组中各元素的平均值：*/
double getAverage(int arr[], int size)
{
    int i;
    double avg;
    double sum;

    for(i = 0; i< size; ++i)
    {
        sum += arr[i];
    }

    avg = sum /size;

    return avg;
}
