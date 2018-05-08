/*******************************************************************
 *   > File Name: 13-saveMoney.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jan 26 17:28:07 2018
 ******************************************************************/
 /*
 假设银行一年整存零取的月息为0.63%。现在某人手中有一笔钱，他打算在今后的五年中每年的年底取出1000元，
 到第五年时刚好取完，请算出他存钱时应该存入多少。
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    float total = 0;
	
	for(i = 0; i< 5; i++){
		total = (total + 1000)/(1+0.0063*12);
	}
	printf("He must save %.2f at first.\n", total);

    return 0;
}
