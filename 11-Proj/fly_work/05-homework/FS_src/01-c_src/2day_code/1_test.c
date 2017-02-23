#include <stdio.h>
#include <string.h>

int main(void)
{
	int len;

	//len = strlen("helloworld");
	len = sizeof("helloworld");
	printf("len = %d\n",len);
	return 0;
}
