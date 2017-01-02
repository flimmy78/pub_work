#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#if (0)
 #include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);
#endif

int main(void)
{
    if((write(1, "Here is some data\n", 18)) != 19)
        write(2, "A write error has occured on file descriptor 1\n",sizeof("A write error has occured on file descriptor 1\n"));

    write(0,"Hahahahahahahahah\n",20);
    
    exit(EXIT_SUCCESS);
}
