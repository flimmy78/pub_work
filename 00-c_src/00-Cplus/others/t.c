#include <stdio.h>
#include <stdlib.h>

#define MAX_NET_TYPE 2
char net_type[MAX_NET_TYPE][16] = {
	"eth0"
	"wlan0"
};

void main(void)
{
	printf("This is test file !\n");
	printf("%s\t%s\t%s\n",__FILE__,__DATE__,__TIME__);

	exit(0);
}
