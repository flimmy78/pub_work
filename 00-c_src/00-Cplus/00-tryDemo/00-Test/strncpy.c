#include <stdio.h>
#include <string.h>
#include <strings.h>

char *strncpy(char *dest, const char *src ,size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for(; i < n ; i++)
		dest[i] = '\0';

	return dest;
}

int main(void)
{
	char buf_dest[128];

	char str_src[] = "ABCEDFghijklmnopqRST";

	printf("\nbuf_dest :%s\nstr_src : %s\n",buf_dest,str_src);
#if 1
	bzero(buf_dest,10);
	memset(str_src,35,2);
#else
	memset(buf_dest,0,10);
#endif

	strncpy(buf_dest,str_src,10);
	printf("After copy :\n");
	printf("buf_dest :%s\nstr_src :%s\n",buf_dest,str_src);

	return 0;
}
