#include <stdio.h>
#include <string.h>

int main(int ac,char **av)
{
	int i;
	
	for(i = 0; i < ac; i++)
	{
		printf("argv[%d]: %s\n",i,av[i]);
		puts("");
		printf("sizeof(argv[%d]) = %d\tstrlen(argv[%d]) = %d\n",i,sizeof(av[i]),i,strlen(av[i]));
	}
	
	return 0;
}
