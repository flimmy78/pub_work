#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	printf("PID = %d\tPPID = %d\n",getpid(),getppid());

	return 0;
}
