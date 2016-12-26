#include <stdio.h>


char *itoa(int a)
{
	char str[25];
	
	sprintf(str,"%d",a);

	return str;
}

int main(void)
{
	while(1)
	{
		int a;
		char *str;

		printf("Pls input a integer:");
		scanf("%d",&a);
		str = itoa(a);

		printf("The string :%s\n",str);
	}

	return 0;
}
