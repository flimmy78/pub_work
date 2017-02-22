#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
#if 1
    fopen("1.txt","r");
    printf("errno = %d\n",errno);
    fprintf(stderr,"fopen:%s\n",strerror(errno));
#else
    int i;

    for(i = 1; i < 134; i++)
	printf("%d:%s\n",i,strerror(i));
#endif
    return 0;
}
