#include <stdio.h>
#include <string.h>

#define MAX_LINE (128)
#define MEMTOTAL "MemTotal"

unsigned int getSysMemTotal(void)
{
	int ret = -1;
	char tmp[MAX_LINE], *read, *start;
	FILE *mem = NULL;
	
	mem = fopen("/proc/meminfo","r");
	if(mem == NULL)
	{
		perror("Fopen /proc/meminfo failed ! Reason :\n");
		ret = -1;
	}
	else
	{
		while(1)
		{
			read = fgets(tmp,MAX_LINE,mem);
			if(read == NULL)
			{
				perror("Fgets /proc/meminfo failed ! Reason :\n");
				ret = -1;
				break;
			}
			else
			{
				if((start =(char *) strcasestr(tmp,MEMTOTAL)) != NULL)
				{
					start += (strlen(MEMTOTAL) + 1);
					ret = 0;
					printf("start = %s\n",start);
					break;
				}
			}
		}
	}
	return ret;
}

int main(void)
{
	int ret;

	ret = getSysMemTotal();
	printf("ret = %d \n",ret);

	return 0;
}
