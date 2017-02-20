#include <stdio.h>

int main(void)
{
	int len;
	char str[] = "HelloWorld";

	len = sizeof(str);
	printf("sizeof(str) = %d\n",len);

	int a;
	printf("sizeof(a) = %d\n",sizeof(a));
	printf("sizeof(a) = %d\n",sizeof a);

	return 0;
}
