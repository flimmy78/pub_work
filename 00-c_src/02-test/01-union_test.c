#include <stdio.h>

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

	return 0;
}


