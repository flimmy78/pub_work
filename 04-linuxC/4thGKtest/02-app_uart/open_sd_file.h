#ifndef __OPEN_SD_FILE__
#define __OPEN_SD_FILE__

#include <stdio.h>

#include <time.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define SD_DATA_DIR     "/mnt/sd01/DVR/DATA/"
#define SD_DATA_FILE    "/mnt/sd01/DVR/DATA/OBD"

int gettimestr(char* tm_str, int len);
int open_sd_file(const char *pathname);
#endif
