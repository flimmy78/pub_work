#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char **argv)
{

    if(chown(argv[1],0,0) < 0){
	perror("chown");
	exit(1);
    }
    return 0;
}
