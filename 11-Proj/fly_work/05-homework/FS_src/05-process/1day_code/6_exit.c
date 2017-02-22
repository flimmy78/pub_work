#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{

#if 1
    printf("hello world");
    exit(0);
    //_exit(0);
#else
    printf("EXIT_SUCCESS:%d\n", EXIT_SUCCESS);
    printf("EXIT_FAILURE:%d\n",EXIT_FAILURE);
#endif
    while(1);
   return 0;
}
