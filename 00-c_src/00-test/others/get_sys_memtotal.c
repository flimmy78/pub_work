
#define MEMTOTAL "MemTotal"
#define Printf(string...)	\
	do{\
		printf("%s(%d)[%s]:",__FILE__,__LINE__,__func__);\
		printf(string);\
	}while(0)

unsigned int get_sys_memtotal(void)
{
	int ret = -1;
	char tmp[MAX_LINE], *read, *start;
	FILE *mem = NULL;

	mem = fopen("/proc/meminfo","r");
	if(mem == NULL)
	{
		perror("Fopen /proc/meminfo failed ! :");
		ret = -1;
	}
	else
	{
		while(1)
		{
			
		}
	}
}
