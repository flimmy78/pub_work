/*******************************************************************
 *   > File Name: 05-getname.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 24 May 2017 03:48:09 PM CST
 ******************************************************************/
#if (0)
unsigned long int   htonl(unsigned long int hostlong);
unsigned short int  htons(unsigned short int hostshort);
unsigned long int   ntohl(unsigned long int netlong);
unsigned short int  ntohs(unsigned short int netshort);

struct hostent *gethostbyaddr(const void *addr, size_t len, int type);
struct hostent *gethostbyname(const char *name);

struct hostent {
    char  *h_name;            /* official name of host */
    char **h_aliases;         /* alias list */
    int    h_addrtype;        /* host address type */
    int    h_length;          /* length of address */
    char **h_addr_list;       /* list of addresses */
}

struct servent *getservbyname(const char *name, const char *proto);
struct servent *getservbyport(int port, const char *proto);

struct servent {
    char  *s_name;       /* official service name */
    char **s_aliases;    /* alias list */
    int    s_port;       /* port number */
    char  *s_proto;      /* protocol to use */
}

#endif
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    char *host, **names, **addrs;
    struct hostent *hostinfo;

    if(argc == 1){
        char myname[256];
        gethostname(myname, 255);
        host = myname;
    }else{
        host = argv[1];
    }

    hostinfo = gethostbyname(host);
    if(!hostinfo){
        fprintf(stderr, "Cannot get info for host :%s\n", host);exit(1);
    }
    
    /*显示主机名和所有的别名*/
    printf("results for host %s :\n", host);
    printf("Name :%s\n", hostinfo -> h_name);
    printf("Aliases :");
    names = hostinfo -> h_aliases;
    while(*names){
        printf("%s", *names);
        names ++;
    }

    printf("\n");
    /*是否是一个IP主机*/
    if(hostinfo -> h_addrtype != AF_INET){
        fprintf(stderr, "not an IP host !\n");exit(1);
    }

    /*显示所有IP*/
    addrs = hostinfo -> h_addr_list;
    while(*addrs){
        printf("%s", inet_ntoa(*(struct in_addr *)*addrs));
        addrs ++;
    }
    printf("\n");
    exit(1);
}
