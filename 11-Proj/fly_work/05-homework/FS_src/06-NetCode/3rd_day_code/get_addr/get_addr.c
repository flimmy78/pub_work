#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h> 

int main(int argc, char *argv[])
{

    struct hostent *h_info;
    struct in_addr **p_addr;

    h_info = gethostbyname("baidu.com");

    p_addr = ((struct in_addr **)(h_info->h_addr_list));

    printf("h_info->h_name = %s\n", h_info->h_name);
    if(h_info->h_addrtype == AF_INET)
	printf("h_info->h_addrtype = AF_INET\n");
    else
	printf("h_info->type = AF_INET6\n");
    printf("h_info->h_length = %d\n", h_info->h_length);
    printf("h_info->h_aliases = %s\n", *(h_info->h_aliases));

    for(;  *p_addr != NULL;  p_addr++)	
	printf("h_info->h_addr_list = %s\n", inet_ntoa((*(*p_addr))));


    return 0;

}
