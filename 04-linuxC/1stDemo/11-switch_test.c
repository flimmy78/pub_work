#include <stdio.h>

int main(void)
{
	int value;
	fprintf(stdout,"Pls Input :");
	scanf("%d",&value);

	switch(value)
	{
		case 0:
			{
				printf("You Input zero !\n");
				break;
			}
		case 1:
			{
				printf("You Input one !\n");
				break;
			}
		default:
			{
				printf("You Input others !\n");
				break;
			}
	}
	return 0;
}
