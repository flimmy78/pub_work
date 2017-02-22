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
#include <sys/select.h>
#include <poll.h>
#include <linux/un.h>

#define UNIX_PATH "/tmp/mysock"


#endif
