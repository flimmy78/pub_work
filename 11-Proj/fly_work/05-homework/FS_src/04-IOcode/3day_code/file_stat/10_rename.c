#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char **argv)
{


    if(rename(argv[1],argv[2]) < 0){
	perror("rename");
	exit(1);
    }
    return 0;
}
