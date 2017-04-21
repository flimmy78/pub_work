7.1.1-套接字超时检测
    套接字的常用选项及相关说明
    选项名称        说明        数据类型
    LEVEL:SOL_SOCKET
    SO_BROADCAST        允许发送广播数据        int
    SO_DEBUG            允许调试                int
    SO_DONTROUTE        不查找路由              int
    SO_ERROR            获得套接字错误          int
    SO_KEEPALIVE        保持连接                int
    SO_LINGER           延迟关闭连接            struct linger
    SO_OOBINLINE        带外数据放入正常数据流  int
    SO_RCVBUF           接收缓冲区大小          int
    SO_SNDBUF           发送缓冲区大小          int
    SO_RCVTIMEO         接收超时                struct timeval
    SO_SNDTIMEO         发送超时                struct timeval
    SO_REUSERADDR       允许重用本地地址和端口  int
    SO_TYPE             获取套接字类型          int
    
    LEVEL:IPPROTO_IP
    IP_HDRINCL          在数据包中包含IP首部    int
    IP_OPTIONS          IP首部选项              int
    IP_TOS              服务类型                int
    IP_TTL              生存时间                int

    LEVEL:IPPROTO_TCP
    TCP_MAXSEG          TCP最大数据段的大小     int
    TCP_NODELAY         不使用Nagle算法         int

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>

int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);


