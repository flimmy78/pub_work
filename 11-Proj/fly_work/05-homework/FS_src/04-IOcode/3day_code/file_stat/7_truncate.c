#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char **argv)
{

    int len = atoi(argv[2]);

    if(truncate(argv[1],len) < 0){
	perror("truncate");
	exit(1);
    }
    return 0;
}
