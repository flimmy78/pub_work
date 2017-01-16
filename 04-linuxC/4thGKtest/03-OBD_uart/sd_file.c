#include "sd_file.h"

//#define DEBUG_TEST

char* gettimestr(char* tm_str, int len)
{
    time_t tm;
    struct tm* ptm;
    int gret = -1;

    if(len < FILE_NAME_SIZE)
    {
        printf("[%s] BufLen is less than %d bytes\n",\
                __func__,\
                FILE_NAME_SIZE);
        return NULL;
    }

    time(&tm);
    ptm = gmtime(&tm);
    gret = snprintf(tm_str,len,"%04d-%02d-%02d_%02d%02d%02d",
            ptm->tm_year +1900,
            ptm->tm_mon + 1,
            ptm->tm_mday,
            ptm->tm_hour ,  //系统实现细节不同，通用加8（时区）
            ptm->tm_min,
            ptm->tm_sec);
    if(gret < 0)
    {
        printf("Spnprintf %d bytes err : %s\n",len,strerror(errno));
        return NULL;
    }
    strncat(tm_str,FILE_SUFFIX,sizeof FILE_SUFFIX);/*根据时间，生成一个文件名*/
    return tm_str;
}


char* get_file_path(char *pathname, int len)
{   
    if(len < SD_NAMEPATH_SIZE)
    {
        printf("[%s] Namepathsize is less than %d bytes\n",\
                __func__,\
                SD_NAMEPATH_SIZE);
        return NULL;
    }

    strncpy(pathname, SD_DATA_DEFAULT_DIR, sizeof(SD_DATA_DEFAULT_DIR));
    if(gettimestr(pathname+DIR_SIZE-1,FILE_NAME_SIZE) != NULL)
        return pathname;
    else
        return NULL;
}

int open_sd_file(const char *pathname)
{
    int fret = -1, sd_fd;
    /* 1.文件夹是否存在 */
    if((fret = access(SD_DATA_DEFAULT_DIR, F_OK)) != 0)
    {
        fret = mkdir(SD_DATA_DEFAULT_DIR, 0777);
        if(fret != 0)
        {
            perror("mkdir SD_DATA_DEFAULT_DIR err");
            return (-1);
        }
        printf("mkdir SD_DATA_DEFAULT_DIR succeed\n");
    }
    printf("%s is OK\n",SD_DATA_DEFAULT_DIR);

    /* 2.创建文件 */
    if(pathname == NULL)
    {
        pathname = SD_DATA_DEFAULT_FILE;
    }
    sd_fd = open(pathname,O_WRONLY|O_CREAT|O_TRUNC, 0777);
    if(sd_fd < 0)
    {
        printf("open %s err : %s\n",pathname,strerror(errno));
        return (-1);
    }

    return sd_fd;
}

int close_sd_file(int fd)
{
    int ret;
    ret = close(fd);
    if(ret < 0)
    {
        printf("Close fd %d err : %s\n",fd,strerror(errno));
    }
    return ret;
}
#ifdef DEBUG_TEST
int main(int argc, char* argv[])
{
    char pathname[SD_NAMEPATH_SIZE];
    int fd;

    printf("%s\n",get_file_path(pathname,SD_NAMEPATH_SIZE));
    fd = open_sd_file(pathname);
    write(fd,"1234567890",10);
    close(fd);
    

    return 0;
}
#endif
