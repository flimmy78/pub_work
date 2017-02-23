#include <stdio.h>
#include <limits.h>

int main(void)
{
	int boundary;
	printf("pls input a integer: ");

	if((scanf("%d", &boundary)) != 1){
		printf("we need an integer. Bye-bye.\n");
		return -1;
	}
	else if(boundary < 0 || boundary > INT_MAX){
		printf("we need an integer. Bye-bye.\n");
		return -1;
	}

	int sum;
	sum = boundary*(1+boundary)/2;

	if(sum < 0){
		printf("summary from 1 to %d is out of range.\n", boundary);
		return -2;
	}
	if(boundary > 2)
		printf("1 + ... + %d = %d\n", boundary, sum);
	else if(boundary == 2)
		printf("1 + 2 = %d\n", sum);
	else
		printf("answer: %d\n", sum);
	return 0;
}
