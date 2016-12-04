#include <stdio.h>
#include <signal.h>

void ouch(int sgn)
{
	printf("OUCH - I got a signal  %d\n",sgn);
	(void)signal(SIGINT, SIG_DFL);
	(void)signal(SIGQUIT,SIG_IGN);
}

int main(void)
{
	(void)signal(SIGINT,ouch);

	while(1)
	{
		printf("This is a signal test !\n");
		sleep(1);
	}

	return 0;
}
