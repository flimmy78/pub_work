/*******************************************************************
 *   > File Name: 12-licensePlateNumber.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jan 26 17:18:48 2018
 ******************************************************************/
/*
要求造出一个前两位数相同、后两位数相同但相互间又互不相同的整数，
然后判断该整数是否已另一个整数的平方。
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
	int i,j,k,c;

	for(i=0; i<=9; i++) {		/*i:车号的前二位的取值*/
		for(j=0; j<=9; j++) {	/*j:车号的后二位取值*/
			if(i != j) {		/*判断两位数字是否相异*/
				k = i*1000 + i*100 + j*10 + j;	/*计算出可能的整数*/
				for(c = 31; c*c < k; c++);		/*判断该数是否是另一数的平方*/
				if(c*c == k) {					/*若是，打印*/
					printf("Lorry---No. is %d.\n", k);
				}
			}
		}
	}

	return 0;
}
