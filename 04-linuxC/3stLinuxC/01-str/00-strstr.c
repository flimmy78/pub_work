#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "12394567890asdf";
	char *p;

#if 0
#include <string.h>

	char *strstr(const char *haystack, const char *needle);

#define _GNU_SOURCE         /* See feature_test_macros(7) */

#include <string.h>

	char *strcasestr(const char *haystack, const char *needle);
#endif

	p = strstr(str,"789");
	printf("%s\n",p);

	return 0;
}
