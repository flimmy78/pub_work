6.1-OSI模型和TCP/IP模型
OSI参考模型：
应用层；
表示层；
会话层；
传输层；
网络层；
数据链路层；
物理层；
TCP/IP参考模型：
应用层;:把封装好的数据提交给传输层或是从传输层接收数据并处理。
传输层;:负责实现应用程序之间的通信服务（端到端通讯）。
网络层;:负责在主机之间的通讯中选择数据包的传输路径，及路由。
    负责处理传入的数据包，检验其有效性，使用路由算法来决定应该对数据包进行本地处理还是应该转发。
网络接口层;:(Network Interface Layer)将二进制流转换成数据帧（网络传输的基本单元），
    并进行数据帧的发送和接收。

6.1.2-TCP/IP模型特点
1.TCP/IP模型边界特性；
2.IP层特性；
3.TCP/IP的可靠性特性；

6.1.3-TCP和UDP

6.2-网络基础编程
6.2.1-套接字概述
1.套接字定义；
2.套接字类型；
（1）、流式套接字（SOCK_STREAM）；
（2）、数据报套接字（SOCK_DGRAM）；
（3）、原始套接字（SOCK_RAW）；

6.2.2-IP地址
1.IP地址的作用--->标识网络中的一台主机；
2.IP地址格式转换（十进制点分形式&32位二进制形式）
#include <arpa/inet.h>
int inet_addr(const char *strptr);
//@param(strptr):要转换的IP地址字符串
//@return：成功，32位二进制IP地址（网络字节序）；出错，返回-1；
int inet_pton(int family, const char *src, void *dst);
//@param(family):AF_INET:IPv4协议；AF_INET6：IPv6协议；
//@param（src）：要转换后的IP地址字符串；
//@param（dst):存放转换后的地址的缓冲区；
//@return：成功，返回0；出错，返回-1；
char *inet_ntop(int family, void *src, char *dst, size_t len);
//@param(family):AF_INET:IPv4协议；AF_INET6:IPv6协议；
//@param(src):要转换的二进制IP地址；
//@param（dst）：存放十进制地址字符串的缓冲区；
//@param（len）：缓冲区的长度；
//@return：成功，返回dst；出错，返回NULL；
3.地址结构相关处理
（1）结构体介绍：
struct sockaddr{
    unsigned short sa_family;   /*地址族*/
    char sa_data[14];           /*14字节的协议介绍*/
};

struct sockaddr_in{
    short int sin_family;       /*地址族*/
    unsigned short int sin_port;/*端口号*/
    struct in_addr sin_addr;    /*IP地址*/
    unsigned char sin_zero[8];  /*填充0以保持与struct sockaddr同样大小*/
};
以上类型大小相同，通常用sockaddr_in来保存某个网络地址，
在使用时强转成sockaddr类型的指针；
sa_family:AF_INET:IPv4协议；AF_INET6：IPv6协议；AF_LOCAL：UNIX域协议；
    AF_LINK：链路地址协议；AF_KEY：密匙套接字；

6.2.3--端口：
    （1）端口（号）是一个无符号短整型，取值范围从0到65535；
    （2）端口号是系统的一种资源，0到1023一般被系统程序使用；
    （3）TCP端口号UDP端口号独立，互不影响；
    （4）如果说IP地址可以表示网络中的一台主机；那么端口号可以用来代表主机内部的某个套接字。
    创建套接字后，需要绑定IP和端口，双方才能实现端到端通讯。

6.2.4--字节序：（Host Byte Order， HBO）
    可能发送方和接收方的端序差异，统一规定：数据以高位字节优先顺序在网络上传输。
#include <netinet/in.h>
uint16_t htons(uint16_t hostshort);
uint32_t htonl(uint32_t hostlong);
uint16_t ntohs(uint16_t netshort);
uint32_t ntohl(uint32_t netlong);

6.2.5-TCP编程
    （1）socket（）
    （2）bind（）
    （3）listen（）
    （4）accept（）
    （5）connect（）
    （6）send和recv（）
    （7）sendto（）和recvfrom（）
    服务器端                    客户端
    socket                      socket----
      |                           |      |
    bind                          |    bind
      |                           |      |
    listen                        |      |
      |                           |      |
    accept <--------------------connect<-|
      |                           |
    recv/recvfrom <-------------send/sendto
      |                           |
    send/sendto   <-------------recv/recvfrom
      |                           |
    close                       close


    
    




