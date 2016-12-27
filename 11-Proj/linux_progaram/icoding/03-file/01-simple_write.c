#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int test(void);

#if (0)
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);
#endif

int main(void)
{
	test();

	exit(EXIT_SUCCESS);
}

static int  test(void)
{
	char ERR_STR[] = "A write error has occurred on file descriptor 1 \n";
	int ret1 = -1,ret2 = -1;

	if((ret1 = write(1,"Her is some data\n",18)) != 19)
		ret2 = write(2,ERR_STR,sizeof(ERR_STR));
	printf("ret1 = %d\tret2 = %d\n",ret1,ret2);

	return 0;
}

#ifdef DEBUG
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int ret1 = -1,ret2 = -1;

	if((ret1 = write(1,"Her is some data\n",18)) != 18)
		ret2 = write(2,"A write err has occurred in file descriptor 1\n",46);

	printf("ret1 = %d\tret2 = %d\n",ret1,ret2);
	exit(1);
}
#endif
