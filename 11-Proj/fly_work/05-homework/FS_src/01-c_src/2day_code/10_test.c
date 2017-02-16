#include <stdio.h>

int main(void)
{
	int a;

	printf("sizeof(double) = %d\n",sizeof(double));  //ok
//	printf("sizeof(double) = %d\n",sizeof double);   //err
	printf("sizeof(a) = %d\n",sizeof(a));	//ok
	printf("sizeof(a) = %d\n",sizeof a);	//ok
	return 0;
}
