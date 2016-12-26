#include <stdio.h>
#include <unistd.h>

#define DEBUG_TEST

#if (0)
#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <unistd.h>

char *crypt(const char *key, const char *salt);

#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <crypt.h>

char *crypt_r(const char *key, const char *salt,
		struct crypt_data *data);

Link with -lcrypt.
#endif

#ifdef DEBUG_TEST
int main(void)
{
	char passwd[13];
	char *key;
	char slat[2];

	key=getpass("Input First Password:");
	slat[0] = key[0];
	slat[1] = key[1];
	strcpy(passwd,crypt(key ,slat));
	key=getpass("Input Second Password");
	slat[0]=passwd[0];
	slat[1]=passwd[1];
	printf("After crpyt(),1st passwd:%s\n",passwd);
	printf("After crpyt(),2nd passwd:%s\n",crypt(key,slat));

	return 0;
}
#endif
