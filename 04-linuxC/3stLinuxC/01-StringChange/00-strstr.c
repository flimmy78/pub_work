#include <stdio.h>
#include <string.h>

#if 0
#include <string.h>

	char *strstr(const char *haystack, const char *needle);

#define _GNU_SOURCE         /* See feature_test_macros(7) */

#include <string.h>

	char *strcasestr(const char *haystack, const char *needle);
#endif


int main(void)
{
	char str[] = "12394567890asdf";
	char *p;

    printf("%s\n",str);
    printf("str----%p\n",str);
	p = strstr(str,"789");
    printf("p----%p\n",p);
	printf("%s\n",p);

	return 0;
}
