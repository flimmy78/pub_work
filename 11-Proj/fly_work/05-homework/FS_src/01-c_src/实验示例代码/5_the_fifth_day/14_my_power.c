#include <stdio.h>
#include <errno.h>
#define EPSINON 1e-38

float my_power(float num, int pow)
{
	if(pow == 0)
		return 1;
	else if(pow == 1)
		return num;

	num *= my_power(num, pow-1);
	return num;
}

int main(void)
{
	float num;
	int pow;
	printf("Pls input the base and power number(e.g. 3.14, 2):");
	if(scanf("%f,%d", &num, &pow) != 2){
		printf("we need an float digit and integer. Bye-bye.\n");
		return -1;
	}

	if(num>-EPSINON && num<EPSINON){ //-EPSINON < num < EPSINON
		if(pow == 0) //forbiden!
			printf("forbiden!\n");
		else
			printf("answer: 0\n");
	}
	else{
		if(pow > 0)
			printf("answer: %.6f\n", my_power(num, pow));
		else if(pow == 0)
			printf("answer: 1\n");
		else{
			pow *= -1;
			printf("answer: %.6f\n", 1/my_power(num, pow));
		}
	}
	return 0;
}
