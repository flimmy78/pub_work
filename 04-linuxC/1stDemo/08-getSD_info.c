#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define SD_PATH "/mnt/sd01"

int get_SD_info(void)
{
	int sd_fd;
	struct stat sd_info;

	/*取得文件状态*/
	stat(SD_PATH,&sd_info);/*将SD_PATH所指的文件状态，复制到sd_info所指的结构体中*/
	printf("Device : %d\n",sd_info.st_dev);
	printf("Inode : %d\n",sd_info.st_ino);
	printf("Protection : %d\n",sd_info.st_mode);
	printf("Number of hard links :%d\n",sd_info.st_nlink);
	printf("User ID of owner : %d\n",sd_info.st_uid);
	printf("Group ID of owner : %d\n",sd_info.st_gid);
	printf("Device type :%d\n",sd_info.st_rdev);
	printf("Total size (byte): %d\n",sd_info.st_size);
	printf("Blocksize for filesystem I/O : %d \n",sd_info.st_blksize);
	printf("Number of blocks allocated : %d \n",sd_info.st_blocks);
	printf("Time of lastaccess : %d\n",sd_info.st_atime);
	printf("Time of last modification : %d\n",sd_info.st_mtime);
	printf("Time of last change :%d\n",sd_info.st_ctime);

	return 0;
}

int main(void)
{
	return get_SD_info();
}
