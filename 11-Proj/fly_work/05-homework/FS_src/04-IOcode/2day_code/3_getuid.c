#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
    printf("uid = %d\n",getuid());
    return 0;
}
