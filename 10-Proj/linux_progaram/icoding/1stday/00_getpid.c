#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define TEST (1)

typedef struct _pid_num{
	pid_t PID;
	pid_t PPID;
}pid_num,*p_pid_num;

p_pid_num getpidnum(void)
{
	p_pid_num p_self;

	p_self=(p_pid_num)malloc(sizeof(pid_num));
	if(p_self == NULL)
	{
		perror("malloc error !");
		return NULL;
	}

	p_self->PID = getpid();
	//printf("%d\n",self.PID);
	p_self->PPID = getppid();
	//printf("%d\n",self.PPID);

	return p_self;
}

#if TEST
int main(void)
{
	p_pid_num P_pid ;

	P_pid = getpidnum();

	printf("PID_NUM = %d\n",P_pid->PID);
	printf("PPID_NUM = %d\n",P_pid->PPID);

	return 0;	
}

#endif
