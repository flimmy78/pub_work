#include <stdio.h>
#include <unistd.h>

int main(int argc ,char **argv)
{
	pid_t pid;
	char *Msg;
	int n = 0;

	pid = fork();
	switch(pid)
	{
		case -1:
			 perror("fork error :");
			 break;
		case 0:
			 Msg = "I am child process";
			 n = 5;
			 break;
		default:
			 Msg = "I am parent process";
			 n = 3;
			 break;
	}

	for(; n > 0; n--)
	{	
		printf("%s !\n",Msg);
		sleep(1);
	}

	return 0;
}
