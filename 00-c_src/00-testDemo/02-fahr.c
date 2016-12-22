#include <stdio.h>

#define VERSION_0

#ifndef VERSION_0
/* 当fahr = 0 , 20 , ... , 300 时，
   分别打印华氏温度与摄氏温度对照表 */

int main(void)
{
	int fahr , celsius;
	int lower, upper, step;

	lower = 0;		/*温度表的下限*/
	upper = 300;	/*温度表的上限*/
	step = 20;		/*步长*/

	fahr = lower;
	while(fahr <= upper)
	{
		celsius = 5*(fahr - 32) / 9;
		printf("%d\t%d\n",fahr,celsius);
		fahr = fahr + step;
	}
	
	return 0;
}
#else
/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ... , 300;floating-point version*/
int main(void)
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;		/* lower limit of temperatuire scale */
	upper = 300;	/*upper limit*/
	step = 20;		/* step size */

	fahr = lower;
	while(fahr <= upper )
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n",fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}
#endif

