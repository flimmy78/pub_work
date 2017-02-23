#ifndef __NET_H__
#define __NET_H__

#include <stdio.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>


//设计一个对象,描述文件的信息
struct file_info{
    char name[32];
    size_t size;
};

#endif
