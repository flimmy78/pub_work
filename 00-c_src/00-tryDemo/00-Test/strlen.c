#include <stdio.h>
#include <string.h>

int main(void)
{
	int len;
	char str[] = "HelloWorld";
	char str_1[] = "";

	/*The strlen() function calculates the length of the string , excluding the terminating null byte('\0')*/
	len = strlen(str);
	printf("strlen(str) = %d\n",len);
	printf("strlen(str_1) = %d\n",strlen(str_1));

	return 0;
}
