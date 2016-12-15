#include <stdio.h>
#include <string.h>

int memset_test(void)
{
	char str_src[10];
//	char str_dst[20];

	memset(str_src,65,sizeof(str_src));
	printf("%s\n",str_src);

	return 0;
}

int main(void)
{
	memset_test();

	return 0;
}
