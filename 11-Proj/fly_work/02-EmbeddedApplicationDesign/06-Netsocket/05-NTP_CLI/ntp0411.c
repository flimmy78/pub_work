/*******************************************************************
 *   > File Name: ntp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Apr 2017 02:38:41 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define NTP_PORT        123             /*NTP专用端口号字符串*/
#define TIME_PORT       37              /*TIME/UDP端口号*/
#define NTP_SERVER_IP   "210.72.145.44" /*国家授时中心IP*/
#define NTP_PORT_STR    "123"           /*NTP专用端口号字符串*/
#define NTPV1           "NTP/V1"        /*协议及其版本号*/
#define NTPV2           "NTP/V2"
#define NTPV3           "NTP/V3"
#define NTPV4           "NTP/V4"
#define TIME            "TIME/UDP"

#define NTP_PCK_LEN     48
#define LI              0
#define VN              3
#define MODE            3
#define STRATUM         0
#define POLL            4
#define PREC            (-6)

#define JAN_1970        0x83aa7e80      /*从1900年到1970年之间的秒数*/
#define NTPFRAC(x)      (4294 * (x) + ((1981 * (x)) >> 11))
#define USEC(x)         (((x) >> 12) - 759 * ((((x) >> 10) + 32768) >> 16)

typedef struct _ntp_time{
    unsigned int coarse;
    unsigned int fine;
}ntp_time;

struct ntp_packet{
    unsigned char leap_ver_mode;
    unsigned char startum;
    char poll;
    char precision;
    int root_delay;
    int root_dispersion;
    int reference_identifier;
    ntp_time reference_timestamp;
    ntp_time originage_timestamp;
    ntp_time receive_timestamp;
    ntp_time transmit_timestamp;
};

char protocol[32];

    /* 使用construct_packet()函数构造NTP包 */
int construct_packet(char *packet){
    char version = 1;
    long tmp_wrd;
    int port;
    time_t timer;
    strcpy(protocol, NTPV3);

    /*判断协议版本*/
    if(!strcmp(protocol, NTPV1) || !strcmp(protocol, NTPV2) || !strcmp(protocol, NTPV3) || !strcmp(protocol, NTPV4)){
        memset(packet, 0, NTP_PCK_LEN);
        port = NTP_PORT;

        /*设置16字节的包头*/
        version = protocol[5] - 0x30;
        tmp_wrd = htonl((LI << 30) | (version << 27) | (MODE << 24) | (STRATUM << 16) | (POLL << 8) | (PREC & 0xff));
        memcpy(packet, &tmp_wrd, sizeof(tmp_wrd));

        /*设置Root Delay、Root Dispersion、Reference Indentifier*/
        tmp_wrd = htonl(1 << 16);
        memcpy(&packet[4], &tmp_wrd, sizeof(tmp_wrd));
        memcpy(&packet[8], &tmp_wrd, sizeof(tmp_wrd));
        
        /*设置Timestamp*/
        time(&timer);

        /*设置Transmit Timestamp coarse*/
        tmp_wrd = htonl(JAN_1970 + (long)timer);
        memcpy(&packet[40], &tmp_wrd, sizeof(tmp_wrd));

        /*设置Transmit Timestamp fine*/
        tmp_wrd = htonl((long)NTPFRAC(timer));
        memcpy(&packet[44], &tmp_wrd, sizeof(tmp_wrd));
        return NTP_PCK_LEN;
    }else if( !strcmp(protocol, TIME)){
        /* "TIME/UDP" */
        port = TIME_PORT;
        memset(packet, 0, 4);
        return 4;
    }
    return 0;
}

    /* 通过网络从NTP服务器获取NTP时间 */
int get_ntp_time(int sk, struct addrinfo *addr, struct ntp_packet *ret_time){
    fd_set pending_data;
    struct timeval block_time;
    char data[NTP_PCK_LEN * 8];
    int packet_len, data_len = addr->ai_addrlen, count = 0, result, i, re;

    if(!(packet_len = construct_packet(data))){
        return 0;
    }

    /*客户端给服务器发送NTP数据包*/
    if((result = sendto(sk, data, packet_len, 0, addr->ai_addr, data_len)) < 0){
        perror("sendto");return 0; 
    }

    /*调用select()函数，并设定超时间为1s*/
    FD_ZERO(&pending_data);
    FD_SET(sk, &pending_data);
    block_time.tv_sec = 10;
    block_time.tv_usec = 0;

    if(select(sk + 1, &pending_data, NULL, NULL, &block_time) > 0){
        /*接收服务端的信息*/
        if((count == recvfrom(sk, data, NTP_PCK_LEN * 8, 0, addr->ai_addr, &data_len)) < 0){
            perror("recvfrom");return 0;
        }

        if(protocol == TIME){
            memcpy(&ret_time->transmit_timestamp, data, 4);return 1;
        }else if(count < NTP_PCK_LEN){
            return 0;
        }

        /*设置接收NTP包的数据结构*/

    }
}
