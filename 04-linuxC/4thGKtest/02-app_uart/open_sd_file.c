#include "open_sd_file.h"

//#define DEBUG_TEST

int gettimestr(char* tm_str, int len)
{
    time_t tm;
    struct tm* ptm;

    time(&tm);
    ptm = gmtime(&tm);
    snprintf(tm_str,19,"%04d-%02d-%02d_%02d:%02d:%02d\n",
            ptm->tm_year +1900,
            ptm->tm_mon + 1,
            ptm->tm_mday,
            ptm->tm_hour,
            ptm->tm_min,
            ptm->tm_sec);
    tm_str[19] = '\0';
    printf("[%s] %s\n",__func__,tm_str);

    return 0;
}

int open_sd_file(const char *pathname)
{
    int fret = -1;
    int sd_fd;
    //FILE* sd_fp;
    /* 1.文件夹是否存在 */
    if((fret = access(SD_DATA_DIR, F_OK)) != 0)
    {
        fret = mkdir(SD_DATA_DIR, 0777);
        if(fret != 0)
        {
            perror("mkdir SD_DATA_DIR err");
            return (-1);
        }
    }
    printf("%s is OK\n",SD_DATA_DIR);

    /* 2.创建文件 */
    if(pathname == NULL)
    {
        pathname = SD_DATA_FILE;
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
    fd = open_sd_file(SD_DATA_FILE);
    //write(fd,"ASDF",4);
    close(fd);

    return 0;
}
#endif
