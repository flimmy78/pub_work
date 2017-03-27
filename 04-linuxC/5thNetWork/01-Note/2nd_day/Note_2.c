主要内容：
1，并发服务器的实现
2，简单文件传输
3，TCP协议中的三次握手
4，数据帧的理解：
		a，mac头，ip头，tcp头，udp头
		b， wireshark的抓包
5，文件IO模型
		a， 阻塞
		b， 非阻塞
		c， 多路复用select/poll
=============================================
复习：
	tcp编程
			c ----------------------SOCK_STREAM--------------------s
			socket()																 socket();
			                                                                          bind()----------本机ip+port <===struct sockaddr_in
																														|
																														sin_port
																														sin_addr(u32)
																						listen();
			connect()-对方(ip+port)											accept();
			write/send()                                                         read/recv()
				close()                                                              close()
				
	udp编程:
			c ------------------------SOCK_DGRAM--------------s
			socket()																socket()
																					bind();---------本机ip+port
			sendto()                                                           recvfrom()
			close                                                                 close();

服务器代码：
	只能响应一个客户端

	能够处理多个客户端服务器
		1，迭代服务器
		2， 并发服务器
				主进程/线程专门负责接收客户端的连接，创建不同的线程/进程中处理客户端的请求

	
2，简单文件传输
	

3，TCP协议中的三次握手
	面向连接－－－确保对方是否存在
				Ａ-------------------------B
							--->在不
							<---在， 你在不
							--> 我还在


4，数据帧的理解：
		a，mac头，ip头，tcp头，udp头
		b， wireshark的抓包

		数据帧：
			  mac 头  + ip头  + tcp头 +　数据　＋ 尾巴（crc）
			 
		mac头：
				目标mac地址
				源mac地址
				下一个头是什么类型，比如ip头，icmp头，arp头
		
		ip头：
				version：版本
				ＩＨＬ：头部长度
				TOS ：数据包的优先级
				total len:  20字节ip头 +  32字节tcp头(20字节+12option) +　data(26) == 78
				identification： 分组号码(如果有分片，用于表示多个分片是否是同一个组)
				ip flag：表示是否有分片
				fragment offset： 分片在大包中的编号(偏移量)
				ｔｔｌ：　存活时间６４，每次经过一个路由器减１
				protol： ip头后面的是什么头
				校验码
	
		tcp　头：
				源端口
				目标端口
				发送方的数据的序列号
				接收方对之前发送过来的数据的响应
				offset:表示整个头部的大小
				tcp flag：		显示是否sync， fin， ack，reset， push
				window：表示传输数据的最大值，用于流量控制
				校验码
				紧急数据－－带外数据
		

5，文件IO模型：　对文件读取的方式
		a， 阻塞：　对文件（设备）读写的时候，如果没有资源，整个进程就会休眠，让出调度权（节省cpu的资源）
				大部分的文件操作都是阻塞：
					fgets();
					scanf()
					read()/write();
					accept();
		b， 非阻塞: 对文件（设备）读写的时候，如果没有资源，函数立马返回一个错误码(-EAGAIN)
					用的比较少,需要用while()来控制
				
				在文件打开的时候：
					1, fd = open("xxx",  O_RDWR|O_NONBLOCK);

					2, read()/write() ==>非阻塞，有数据就读写，没有数据就立马返回
				文件打开之后：
					1,fd = open("xxx",  O_RDWR);
						fd = socket(AF_INET, SOCK_STREAM, 0);
					2.fcntl( )函数
						int fcntl(int fd, int cmd, long arg);
					  int flag；
					  flag = fcntl(sockfd, F_GETFL, 0);
					  flag |= O_NONBLOCK;
					  fcntl(sockfd, F_SETFL, flag);

		c， 多路复用select/poll
				同时可以监控多个文件上发生的读，写，出错---（帮忙去等，等到数据后可以通知）
				需求：改写服务端
						1，等待客户端的连接
						2，等待客户端的数据
						3，等待服务端标准输入，把数据发送到客户端
				
				  void FD_CLR(int fd, fd_set *set);
			   int  FD_ISSET(int fd, fd_set *set);
			   void FD_SET(int fd, fd_set *set);
			   void FD_ZERO(fd_set *set);
				int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
				参数1：最大的文件描述符+1
				参数2：读集合
				参数３：写集合
				参数4： 出错集合
				参数5： 监控多久，如果等于NULL，一直等
							struct timeval {
							   long    tv_sec;         /* seconds */
							   long    tv_usec;        /* microseconds */
						   };

						   struct timeval time;
						   time.tv_sec = 5;
						   time.tv_sec = 0;

				返回值： 大于0，表示有多少个fd发生了读写出错
						     小于0，表示出错


			
任务：
			1， 完成并发服务器---用线程去实现
			2， 完成文件传输--- 
					基础：
							1，完成最简单的文件传输
							2，定义一个文件信息协议，先传文件的信息，然后在传文件数据
										协议用字符串--自己定义
			3，分析三次和四次握手---通过使用wireshark
						sudo wireshark
						设置抓包的接口--eth0(跨机器)
												否则使用psudo any
						设置抓包的过滤器
									tcp port 9999
						分析各个头部，分析三次握手和四次握手
			4，利用select去实现客户端
					可以用户输入，并把数据发送给服务端
					通过可以接受到服务端的数据