#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 100;
	char str[25];

	sprintf(str,"%d",num);
	printf("The number 'num' is %d the string 'str' is %s .\n",num,str);

	return 0;
}
