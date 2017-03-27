0, setsockopt 设置套接字选项
1, 广播
2，组播
3， 带外数据
4，unix套接字---本机通信
====================================
select：如果需要同时对多个文件( 设备)进行读写
	0,初始化---清空位表
		FD_CLR(&fd_set);
	1,设置位表--设定监控哪几个文件
		FD_SET(fd, &fd_set);
		FD_SET(fd, &fd_set);
		FD_SET(fd, &fd_set);
	2, select()一旦返回，表示有动静（有数据）
	3,  多次判断是哪个文件有数据
			FD_ISSET();如果成立
					就可以调用读写数据的函数
						accept(); <-----select发现有三次握手的第一次握手，就表示有数据

实际还有一种: poll
	int poll(struct pollfd *fds, nfds_t nfds, int timeout);
	参数1：多个文件描述符的集合
	参数2：监控的文件描述符的个数
	参数3：监控的时间: 负数表示无限等
	  struct pollfd {
               int   fd;         //表示你要监控的fd
               short events;     //希望监控fd的什么：读， 写，出错
									//读POLLIN ,写POLLOUT， 出错POLLERR
               short revents;   //结果,如果有数据，内核会自动去设置这个变量，用于去判断
           };
	返回值：大于0，表示有数据
				小于0： 出错
				等于零：超时
	使用：
		struct pollfd pfd[2];

		pfd[0].fd = 0;
		pfd[0].events |= POLLIN;

		pfd[1].fd = fd;
		pfd[1].events |= POLLIN;

		ret = poll(pfd, 2, -1);
			
		如果返回：
				if(pfd[1].revents & POLLIN)
				｛
				｝


设置套接字属性：
	int setsockopt(int sockfd,int level,int optname,const void *optval,socklen_t *optlen)
	参数1：打开的ｓｏｃｋｅｔ
	参数２：　套接字的层次：
				1)SOL_SOCKET:通用套接字选项. －－设置地址重用，广播
				2)IPPROTO_IP:IP选项. －－加入组播，设置将当前ｉｐ加入到一个组，　ｔｔｌ
				3)IPPROTO_TCP:TCP选项.　
	参数３：　选项名字：
					比如SO_BROADCAST
						SO_REUSEADDR
	参数4：选项的值
	参数５，选项值的长度

	使用：
		使能在关闭通信的时候，允许最后一个ａｃｋ没有收到的时候，可以重新ｂｉｎｄ
		int on = 1;
		setsockopt(fd,  SOL_SOCKET, SO_REUSEADDR,  &on, sizeof(on)); //只要在服务端，bind之前建议要用这个
		
				

1, 广播--向网络中所有机器发送数据
		广播地址：
				255.255.255.255
				192.168.7.255
		
		a, 广播需要打开---发送方
			setsockopt();
		b， 发送用udp

		int inet_pton(int af, const char *src, void *dst);
		参数1：地址是ｉｐｖ４还是ｉｐｖ６
				　AF_INET
		参数2：字符串形式的ip地址
		参数3：转换之后的地址(32bit)struct in_addr

		使用：
			inet_pton(AF_INET, "255.255.255.255",  &peer.sin_addr);


2，组播: 将几个机器组成一个组，发送数据只有这几个组可以收到数据, 组播需要内核的支持
	  a， 对于接收方需要加入到组播ip
				setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq,  sizeof(mreq));
	  b， 发送方需要发送到组播ip
	  c， 组播ip：
			224.0.0.1 – 239.255.255.255
		e，依然使用udp
	

3， 带外数据---oob: out of band,用于发送一些控制信息(优先级比较高的)
	接收方法；
		1，正常去接收数据
		2，也可以接收带外数据
					  利用信号signal--SIGURG
			SIGURG: 如果要接收这个信号
					a,注册信号处理方法
					b， 设置信号是属主进程（SIGURG是该进程接收）
							fcntl(new_fd, F_SETOWN, getpid());

4，域套接字：unix socket，用于本地通信(ipc另外一种)
		a，编程方式使用了socket的api
		b,  实现模型很像管道
				A --- 文件----B

				socketpair：用于父子进程－－类似于无名管道
				socket() + bind() +listen + accept+read/write --类似于有名管道


				与跨机器通信不同的地方:
					1,创建套接字
							int  fd = socket(AF_LOCAL, SOCK_STREAM, 0);
					
					2, 绑定
							struct sockaddr_un  addr;
							 addr.sun_family = AF_LOCAL;
							 strcmp(&addr.sun_path, "/tmp/xxx");

							 bind(fd, (struct sockaddr *)&addr, sizeof(addr));
					
					3, listen
					4, accept





5，域名解析
		struct hostent *gethostbyname(const char *name);

		 struct hostent {//信息的载体，记录了返回的描述主机信息的结果
               char  *h_name;            /* official name of host */
               char **h_aliases;         /* alias list */
               int    h_addrtype;        /* host address type */
               int    h_length;          /* length of address */
               char **h_addr_list;       /* list of addresses */ // ip地址的列表
           }
           #define h_addr h_addr_list[0] /* for backward compatibility */
