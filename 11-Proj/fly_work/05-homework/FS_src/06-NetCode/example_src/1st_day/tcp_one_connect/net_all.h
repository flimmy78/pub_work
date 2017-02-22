#ifndef  __NET_ALL_H__
#define __NET_ALL_H__

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* only one macro can be define*/
//#define STREAM_TEST
//#define SEND_LONG_DATA
#define NONBLOCK_TEST

/*for udp test*/
//#define DGRAM_TEST
//#define UDP_TEST


struct file_info{
        int size;
        char name[64];
};


#endif 
