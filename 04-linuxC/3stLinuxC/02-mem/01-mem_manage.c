#include <stdio.h>

#if (0)
#include <stdlib.h>
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);

#include <unistd.h>
int getpagesize(void);

#include <sys/mman.h>
void *mmap(void *addr, size_t length, int prot, int flags,
int fd, off_t offset);
int munmap(void *addr, size_t length);
#endif

#define DEBUG_TEST
#define NAMEMAXSIZE 10

#ifdef DEBUG_TEST
int main(int argc,char **argv)
{
	char func[][NAMEMAXSIZE] = {"calloc","free","getpagesize","malloc","mmap","munmap"};

	enum FUNC{
		CALLOC,
		FREE,
		GETPAGESIZE,
		MALLOC,
		MMAP,
		MUNMAP
	}func_name;

	if(argv < 2)
	{
		printf("Usage : %s funcname\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	return 0;
}
#endif
