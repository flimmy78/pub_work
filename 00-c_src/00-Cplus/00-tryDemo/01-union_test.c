#include <stdio.h>
#include <string.h>

union test
{
	unsigned int a;
	unsigned char b;
	char str[5];
	int c[6];
};

int main(void)
{
	union test T;
	T.str[0]='0';
	T.str[1]='1';
	T.str[2]='2';
	T.str[3]='3';
	T.str[4]='4';
	printf("%d\n%c\n%s\n",T.a,T.b,T.str);
    printf("sizeof(union test) = %d\n", sizeof(union test));

#if (1)
    char str1[5];
    char *str2 = "Hello";
    printf("strlen(str1) = %d\tstrlen(str2) = %d\n", strlen(str1), strlen(str2));
    printf("sizeof(str1) = %d\tsizeof(str2) = %d\n", sizeof(str1), sizeof(str2));

#endif

	return 0;
}


