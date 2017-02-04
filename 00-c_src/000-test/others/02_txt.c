#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	
	char *string = "this is a very good idear !";
	int len = sizeof(string);

	fd = creat("./test.txt",0777);
	int ret = write(fd,string,len);
	if(ret < 0)
		perror("write");

	return 0;
}
