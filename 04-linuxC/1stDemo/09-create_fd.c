#include <stdio.h>

#if (1)
int create_fd(static char *pathname)
{
	int fd;
	int ret;

	ret = access(pathname, F_OK);
	if(ret == -1)
	{
		ret = mkfifo(pathname, 0777);
		if(ret != 0)
		{
			fprintf(stderr,"Could not create fifo %s\n",pathname);
			return (-1);
		}
	}
	else
	{
		ret = chmod(pathname,0777);
		if(ret != 0)
		{
			fprintf(stderr,"Chmod fifo  %s failed \n",pathname);
		}
	}

	fd = open(pathname,O_RDWR);
	if(fd < 0)
	{
		fprintf(stderr,"Open  fifo %s failed \n",pathname);
		return (-1);
	}
	
	return fd;
}
#else
int create_fifo(const char *pathname)
{
	int fifo_fd;	/*定义一个文件描述符*/

	if(access(pathname, F_OK) != 0)	/*检测文件是否存在*/
	{
		if(mkfifo(pathname, 0777) != 0)	/*创建管道文件，存取权限：777*/
		{
			fprintf(stderr,"Couldn't create fifo %s \n",pathname);
			return (-1);
		}
	}
	else
	{
		if(chmod(pathname, 0777) != 0) /*使文件权限为：777*/
		{
			sprintf(stderr,"Chmod %s err \n",pathname);
		}
	}

	fifo_fd = open(pathname, O_RDWR);	/*以可读可写标志打开文件*/
	if(fifo_fd < 0)
	{
		fprintf(stderr,"Open %s err \n",pathname);
		return (-1);
	}

	return fifo_fd;	/*成功返回文件描述符*/
}
#endif
int close_fifo(int fifo_fd)
{
	close(fifo_fd);
	return 0;
}

