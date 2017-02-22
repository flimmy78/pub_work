#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char **argv)
{


    if(remove(argv[1]) < 0){
	perror("remove");
	exit(1);
    }
    return 0;
}
