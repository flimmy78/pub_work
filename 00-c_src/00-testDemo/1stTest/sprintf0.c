#include <stdio.h>

int main(void)
{
	int a;
	char *str;

	while(1)
	{	
		printf("Pls input a integer :");
		scanf("%d",&a);
		sprintf(str,"%d",a);
		printf("The string : %s \n",str);
		
	}

	return 0;
}
