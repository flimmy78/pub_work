#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>



int main(int argc,char **argv)
{

    struct stat st;
    if(argc != 2){
	fprintf(stderr,"Usage: %s [filename]\n",argv[0]);
	exit(1);
    }
#if 0
    if(stat(argv[1],&st) < 0){
	perror("stat");
	exit(1);
    }
#else
    if(lstat(argv[1],&st) < 0){
	perror("stat");
	exit(1);
    }
#endif
    //获取文件类型
    if(S_ISREG(st.st_mode))
	printf("-");
    else if(S_ISDIR(st.st_mode))
	printf("d");
    else if(S_ISCHR(st.st_mode))
	printf("c");
    else if(S_ISBLK(st.st_mode))
	printf("b");
    else if(S_ISFIFO(st.st_mode))
	printf("p");
    else if(S_ISLNK(st.st_mode))
	printf("l");
    else if(S_ISSOCK(st.st_mode))
	printf("s");
    //获取文件权限
    int i;
    char str[] = "xwr-";
    for(i = 8; i>= 0; i--){
	if(st.st_mode & (1<<i))
	    printf("%c",str[i%3]);
	else
	    printf("-");
    }
    printf(" ");
    printf("%u ",st.st_nlink);    //获取文件的硬链接数

    //获取文件的拥有者的名称
#if 1
    struct passwd *pw;
    pw = getpwuid(st.st_uid);
    printf("%s ",pw->pw_name);
#else
    printf("%u ",st.st_uid);
#endif
    //获取文件的所属组的名称
#if 1
    struct group *gp;
    gp = getgrgid(st.st_gid);
    printf("%s ",gp->gr_name);
#else
    printf("%u ",st.st_gid);
#endif
    printf("%ld ",st.st_size);  //获取文件大小

    struct tm *pt;
    pt = localtime(&st.st_atime);
    printf("%02d-%02d %02d:%02d ",pt->tm_mon+1,pt->tm_mday,pt->tm_hour,pt->tm_min);

    printf("%s\n",argv[1]);
    return 0;
}
