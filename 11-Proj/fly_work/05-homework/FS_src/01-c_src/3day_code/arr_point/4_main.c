
#include <stdio.h>

//argc   表示命令行参数个数
//argv	 表示命令行参数
int main(int argc,char *argv[])
{
	int i;
	for(i = 0;i < argc; i++)
		printf("%s\n",argv[i]);
	return 0;
}
