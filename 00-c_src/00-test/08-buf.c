#include <stdio.h>
#include <string.h>

int main(void)
{
	char Buf[100];
	memset(Buf,0,100);

	printf("sizeof = %d\tstrlen = %d\n",sizeof(Buf),strlen(Buf));
	return 0;
}
