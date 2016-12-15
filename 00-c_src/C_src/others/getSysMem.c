#include <stdio.h>
#include <string.h>

int gk_atoi(char *line, int size)
{
	int value;
	if(size == 0)
	{
		return -1;
	}
	for (value = 0; size--; line++)
	{
		if(*line < '0' || *line > '9')
		{
			continue;
		}
		value = value * 10 + (*line - '0');
	}
	if(value < 0)
	{
		return -1;
	}
	else
	{
		return value;
	}
}

#define MAX_LINE (128)
#define MEMTOTAL "MemTotal"
unsigned int get_system_memtotal(void)
{
	int ret = -1;
	char tmp[MAX_LINE], *read, *start;
	FILE *mem = NULL;
	mem = fopen("/proc/meminfo", "r");
	if(mem == NULL)
	{
		perror("Fopen /proc/meminfo failed! Reason:\n");
		ret = -1;
	}
	else
	{
		while(1)
		{
			read = fgets(tmp, MAX_LINE, mem);
			if(read == NULL)
			{
				perror("Fgets /proc/meminfo failed! Reason:\n");
				ret = -1;
				break;
			}
			else
			{
				if((start = strcasestr(tmp, MEMTOTAL)) != NULL)
				{
					start += strlen(MEMTOTAL);
					ret = gk_atoi(start, strlen(start));
					break;
				}
			}
		}
	}
	return ret;
}

int main(void)
{
	int MemTotal;

	MemTotal = get_system_memtotal();
	printf("MemTotal = %d\n",MemTotal);

	return 0;
}
