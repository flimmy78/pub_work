#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(void)
{
        struct in_addr a1;
        struct in_addr a2;

#if 0
        inet_aton("192.168.7.2", &a1);
        inet_aton("192.168.7.3", &a2);
        printf("a1 = 0x%x\n", a1);
        printf("a2 = 0x%x\n", a2);
        
        printf("addr1 = %s\n",  inet_ntoa(a1));
        printf("addr2 = %s\n", inet_ntoa(a2));
#else
        inet_pton(AF_INET, "192.168.7.4", &a1);
        printf("a1 = 0x%x\n", a1.s_addr);

        a2.s_addr = inet_addr("192.168.7.5");
        printf("a2 = 0x%x\n", a2.s_addr);

#endif
        return 0;
}
