#include "open_sd_file.h"

//#define DEBUG_TEST

int gettimestr(char* tm_str, int len)
{
    time_t tm;
    struct tm* ptm;

    if(len < 20)
    {
        printf("[%s] BufLen is less than 20 bytes\n", __func__);
        return (-1);
    }

    time(&tm);
    ptm = gmtime(&tm);
    snprintf(tm_str,len,"%04d-%02d-%02d_%02d:%02d:%02d",
            ptm->tm_year +1900,
            ptm->tm_mon + 1,
            ptm->tm_mday,
            ptm->tm_hour ,  //系统实现细节不同，通用加8（时区）
            ptm->tm_min,
            ptm->tm_sec);
    return 0;
}

char* get_file_name(char *filename, int len)
{
    int ret;
    if(len < 24)
    {
        printf("[%s] NameLen is less than 24 bytes\n",__func__);
        return NULL;
    }
    
    char timestr[24]; 
    ret = gettimestr(timestr,len);
    if(ret < 0)
    {
        printf("[%s] Gettimestr err\n",__func__);
        return NULL;
    }

    strncat(filename, timestr, 24);
    
    return filename;
}

int open_sd_file(const char *pathname)
{
    int fret = -1;
    int sd_fd;
    //FILE* sd_fp;
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
        printf("open %s err\n",pathname);
        return (-1);
    }

    return sd_fd;
}

#ifdef DEBUG_TEST
int main(int argc, char* argv[])
{
    int fd;
    fd = open_sd_file(SD_DATA_DEFAULT_FILE);
    //write(fd,"ASDF",4);
    close(fd);

    return 0;
}
#endif
