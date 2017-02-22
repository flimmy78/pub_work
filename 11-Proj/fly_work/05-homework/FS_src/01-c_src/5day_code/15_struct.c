#include <stdio.h>

struct A{
	char a;
	int b;
	short c;
}st1;
struct B{
	char a;
	short c;
	int b;
}st2;

int main(void)
{
	printf("sizeof(st1) = %d\n",sizeof(st1));
	printf("sizeof(st2) = %d\n",sizeof(st2));
	return 0;
}
