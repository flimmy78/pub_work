#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    printf("uid = %d\n",geteuid());
    return 0;
}
