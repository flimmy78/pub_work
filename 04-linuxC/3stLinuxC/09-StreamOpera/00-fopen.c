#include <stdio.h>
#include <stdlib.h>

#if (0)
#include <stdio.h>

FILE *fopen(const char *path, const char *mode);

FILE *fdopen(int fd, const char *mode);

FILE *freopen(const char *path, const char *mode, FILE *stream);

the argument mode points to a string

	r		只读方式打开文件，文件必须存在

	r+		可读写方式打开文件，文件必须存在

	w		只写方式打开文件，文件存在，则清空；文件不存在，则创建；

	w+		可读写方式打开文件，...

	a		只写方式打开文件，文件存在，则在末尾添加，不存在，创建

	a+		可读写方式打开文件，...

#endif

#define FILEPATH "/home/fly/pub_work/04-linuxC/3stLinuxC/09-StreamOpera/mytestfile/test.txt"

int main(void)
{
	FILE *fp;
	int c;

	fp = fopen(FILEPATH,"r+");
	if(fp == NULL)
	{
		perror("fopen FILEPATH err");
		exit(1);
	}
	puts("fopen FILEPATH ok");
	fclose(fp);

	return 0;
}
