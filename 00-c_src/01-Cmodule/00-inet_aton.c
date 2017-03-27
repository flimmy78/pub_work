/*******************************************************************
 *   > File Name: 00-inet_aton.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 27 Mar 2017 03:03:22 PM CST
 ******************************************************************/

#define _BSD_SOURCE
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

    int
main(int argc, char *argv[])
{
    struct in_addr addr;
    int ret;

    if (argc != 2) {
        fprintf(stderr, "%s <dotted-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (ret = inet_aton(argv[1], &addr) == 0) {
        fprintf(stderr, "Invalid address\n");
        exit(EXIT_FAILURE);
    }
    printf("ret = %d\n",ret);

    printf("%s\n", inet_ntoa(addr));
    exit(EXIT_SUCCESS);
}

