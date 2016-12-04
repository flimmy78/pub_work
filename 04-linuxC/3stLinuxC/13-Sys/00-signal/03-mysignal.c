#include <stdio.h>
#include <signal.h>

void signal_cap_test(int sig)
{
	printf("---->[Got siganl : %d]<----\n", sig);
}

void register_all_signal()
{
	struct sigaction act;
	act.sa_handler = signal_cap_test;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	int signal_pos = 0;

	int GKSIGNALS[3] = {SIGINT, SIGBUS,SIGPIPE};
	for(signal_pos = 0; signal_pos< 3; signal_pos++)
	{
		if(sigaction(GKSIGNALS[signal_pos], &act, NULL) <0)
			perror("sigaction");
	}
}

int main(void)
{
	register_all_signal();

	while(1)
	{
		printf("signal test\n");
		sleep(1);
	}

	return 0;
}
