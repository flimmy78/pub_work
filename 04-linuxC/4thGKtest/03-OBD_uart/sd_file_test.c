/*******************************************************************
 *   > File Name: sd_file_test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Feb 2017 02:01:44 PM CST
 ******************************************************************/

#include <stdio.h>
#include "sd_file.h"

int main(int argc, char* argv[])
{
#if 0
    char tm_string[FILE_NAME_SIZE];
    if(gettimestr(tm_string,FILE_NAME_SIZE) == NULL)
    {
        printf("gettimestr error\n");
    }
    else
    {
        printf("gettimestr :%s\n",tm_string);
    }
#endif
    /*获取文件路径名*/
    char filepathname[SD_NAMEPATH_SIZE];
    if(get_file_path(filepathname, SD_NAMEPATH_SIZE) == NULL)
    {
        printf("get_file_path err\n");
        return (-1);
    }
    else
    {
        printf("filenamepath :%s\n",filepathname);
    }
    
    /*打开文件*/
    int ret, file_fd;
    ret = open_sd_file(filepathname);
    if(ret < 0)
    {
        printf("open_sd_file %s err\n",filepathname);
        return (-1);
    }
    else
    {
        printf("open_sd_file %s ok fd is %d\n",filepathname,ret);
        file_fd = ret;
    }


    /*关闭文件*/
    ret = close_sd_file(file_fd);
    if(ret != 0)
    {
        printf("close_sd_file err\n");
        return (-1);
    }
    else
    {
        printf("clsoe_sd_file ok\n");
    }

    return 0;
}
