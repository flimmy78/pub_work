TCP协议：
	1，属于TCP/IP协议族中一个
	2， 面向连接
	3， 安全，不容易丢包
	4，数据无失序

UDP协议：传输效率相对会高
	1，属于TCP/IP协议族中一个
	2， 面向无连接
	3， 不安全容易丢包
	4， 数据无序

网络传输中的基本概念：
	1，socket
			a， 是一个网络传输的基本接口
			b， 类似于io中open，socket实际打开一个网络设备，返回一个fd
			c，socke分类
					SOCK_STREAM：流式套接字，传输数据的时候是一字节流传输（通过面向连接，tcp）
					SOCK_DGRAM ：数据包套接字，传输的时候以数据报(长度不定）(通过面向非连接，udp)
					SOCK_RAW ：原始套接字,主要是去操作底层的协议(ping的实现， icmp协议)
	
	2，ip：Internet中主机的标识
			1，分四段，常用点分形式
					192.168.7.100
			2, ip分三类--分成两个部分
					网络id  +  机器id
					A类：
							0.0.0.0---127.255.255.255
					B类：
						128.0.0.0-191.255.255.255
					C类：局域网， 网络id（三段）
						192.0.0.0-223.255.255.255


			特殊ip：
				255.255.255.255 全广播地址
				192.168.7.255 广播地址
				
				192.168.7.0： 网络标示符

				255.255.255.0：子网掩码
				192.168.7.1 ：网关
				DNS：域名解析服务


				192.168.7.3 ------------------> 192.168.7.2
									通过掩码得到两者是否是在同一个网络
									如果不是同一网络就需要网关转发出去

									baidu.com ----- ip(123.125.114.144)
									域名					服务器的ip
										|
									解析出ip
										|
										dns202.96.128.86
											 8.8.8.8
											 114.114.114.114
		
		2,端口号：标示一个进程，需要去绑定，实际是一个16bit整数
				1，可以动态分配
				2，可以自定分配---越大越好：9999，10000
		
		3，字节序--大端和小端
				大端：高位先存
				小端：低位先存

				网络中传输的时候永远都是大端
				u_long htonl (u_long hostlong);　//发送数据出去的时候
				u_short htons (u_short short);


				u_long ntohl (u_long hostlong);//接收网络中数据
				u_short ntohs (u_short short);
		
		4， ip转换
				人写代码: 字符串"192.168.7.3"
				机器中：将ｉｐ地址当成二进制－－一个整数
				转换：
						in_addr_t inet_addr(const char *strptr);
						参数1： 字符串
						返回值：３２ｂｉｔ的ｉｐ地址值
	

								
ＡＰＩ：
	１，创建套接字
		　int socket(int domain, int type, int protocol);
			参数：　通信域－－本机／跨机器通信
						AF_UNIX/AF_LOCAL：　本机通信
						AF_INET　：跨机器通信--用的协议族ipv4
			参数2：传输什么类型是数据
					SOCK_STREAM: 传输是字节流---tcp
					SOCK_DGRAM ：传输的是数据报-- udp
					SOCK_RAW ： 传输的是内部协议--icmp

			参数3：具体是哪个协议--0
	
		用法：
			tcp编程：
					socket(AF_INET, SOCK_STREAM, 0);

			udp编程:
					socket(AF_INET, SOCK_DGRAM, 0);

	
		2, bind将进程和端口号和ip地址(当前主机)进行绑定，就可以被别人连接
			 int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
			 参数1：当前的创建的ｓｏｃｋｅｔ
			 参数２：地址和端口的信息
			 参数3：地址和信息的长度

			地址和端口的信息：struct sockaddr *addr　（通用地址）
				实际用：　struct sockaddr_in
				struct sockaddr_in
				  {           
					   u_short sin_family;      // 地址族, AF_INET，2 bytes
					   u_short sin_port;      // 端口，2 bytes, 自己选择，转换成网络端字节序( 大端)htons();
					   struct in_addr sin_addr;  // IPV4地址，4 bytes 	
					   char sin_zero[8];        // 8 bytes unused，作为填充
				  }; 

				struct in_addr
				{
					 in_addr_t  s_addr;            // u32 network address 
				};

				初始化struct sockaddr_in
				struct sockaddr_in  self_addr;
				self_addr.sin_family = AF_INET;
				self_addr.sin_port = htons(9999);
				self_addr.sin_addr.s_addr = inet_addr("192.168.7.5");

				使用： grep -rHn 'struct sockaddr_in'  /usr/include/
				#include <linux/in.h>
				int bind(fd, （const struct sockaddr * ）&self_addr,   sizeof(self_addr));

			3, listen();表示监听，设置在同一时间点，可以同时连接的最大的客户端的个数
				int listen(int sockfd, int backlog);
					参数2：最大的客户端的个数，　５－１０
				
			４，accept()等待客户端的连接，阻塞
				int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
				参数1： 服务端的创建的socket对应的fd
				参数2,3表示客户端的信息，当然也可以不关心对方是谁，就可以填NULL， NULL
				返回值：返回一个新的文件描述符，和客户端进行数据通信的
				最简单的用法：
					int  new_fd = accept(fd, NULL, NULL);
				
			
			客户端：
				int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
				参数2：表示连接到哪个服务器，需要给出信息

	


	地址转换：都是将字符串转换成u32
		1，in_addr_t inet_addr(const char *cp);
			优点： 好用
			缺点：不能转换"255.255.255.255", 
		2， int inet_aton(const char *cp, struct in_addr *inp);
			缺点：只能用在ipv4
			用法：
				struct in_addr addr;
				inet_aton("192.168.7.6", &addr);

		3，int inet_pton(int af, const char *src, void *dst);
			缺点：参数比较多
			可以用在ipv4,和ipv6地址转换


		self.sin_addr.s_addr = htonl(INADDR_ANY); //本机器的所有ip

udp:发送和接收数据：
	 ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,struct sockaddr *src_addr, socklen_t *addrlen);
	  参数5,6表示发送方的信息， 和accept中后面两个参数一样

