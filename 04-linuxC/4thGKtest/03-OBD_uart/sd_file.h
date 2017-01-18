#ifndef __SD_FILE_H__
#define __SD_FILE_H__

#include <stdio.h>

#include <time.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define SD_DATA_DEFAULT_DIR     "/mnt/sd01/DVR/DATA/"
#define SD_DATA_DEFAULT_FILE    "/mnt/sd01/DVR/DATA/OBD"
#define TIME_FORMAT     "XXXX-XX-XX_XXXXXX"
#define FILE_SUFFIX     ".OBD"
#define FILE_FORMAT     (TIME_FORMAT FILE_SUFFIX)   /*例：2017-01-16_171302.OBD*/
#define DIR_SIZE        (sizeof SD_DATA_DEFAULT_DIR)    /*20*/
#define FILE_NAME_SIZE      (sizeof FILE_FORMAT)    /*22*/
#define SD_NAMEPATH_SIZE    (sizeof(SD_DATA_DEFAULT_DIR)+FILE_NAME_SIZE)    /*42*/


char* gettimestr(char* tm_str, int len);    /*获取时间文件名*/
char* get_file_path(char* pathname, int len);/*获取文件路径*/
int open_sd_file(const char *pathname);     /*打开文件*/
int close_sd_file(int fd);      /*关闭文件*/
#endif
