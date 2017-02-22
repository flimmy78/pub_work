#include <stdio.h>

int main(void)
{
    printf("process ID:%d\n",getpid());
    printf("parent process ID:%d\n",getppid());
    return 0;
}
