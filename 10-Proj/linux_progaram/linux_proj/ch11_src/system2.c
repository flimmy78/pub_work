#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    printf("Running ps with system\n");
    system("ps ax &");
    printf("Done.\n");

	//wait(NULL);
	waitpid(-1,NULL,0);
    exit(0);
}
