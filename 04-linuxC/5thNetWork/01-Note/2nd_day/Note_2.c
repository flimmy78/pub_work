��Ҫ���ݣ�
1��������������ʵ��
2�����ļ�����
3��TCPЭ���е���������
4������֡����⣺
		a��macͷ��ipͷ��tcpͷ��udpͷ
		b�� wireshark��ץ��
5���ļ�IOģ��
		a�� ����
		b�� ������
		c�� ��·����select/poll
=============================================
��ϰ��
	tcp���
			c ----------------------SOCK_STREAM--------------------s
			socket()																 socket();
			                                                                          bind()----------����ip+port <===struct sockaddr_in
																														|
																														sin_port
																														sin_addr(u32)
																						listen();
			connect()-�Է�(ip+port)											accept();
			write/send()                                                         read/recv()
				close()                                                              close()
				
	udp���:
			c ------------------------SOCK_DGRAM--------------s
			socket()																socket()
																					bind();---------����ip+port
			sendto()                                                           recvfrom()
			close                                                                 close();

���������룺
	ֻ����Ӧһ���ͻ���

	�ܹ��������ͻ��˷�����
		1������������
		2�� ����������
				������/�߳�ר�Ÿ�����տͻ��˵����ӣ�������ͬ���߳�/�����д���ͻ��˵�����

	
2�����ļ�����
	

3��TCPЭ���е���������
	�������ӣ�����ȷ���Է��Ƿ����
				��-------------------------B
							--->�ڲ�
							<---�ڣ� ���ڲ�
							--> �һ���


4������֡����⣺
		a��macͷ��ipͷ��tcpͷ��udpͷ
		b�� wireshark��ץ��

		����֡��
			  mac ͷ  + ipͷ  + tcpͷ +�����ݡ��� β�ͣ�crc��
			 
		macͷ��
				Ŀ��mac��ַ
				Դmac��ַ
				��һ��ͷ��ʲô���ͣ�����ipͷ��icmpͷ��arpͷ
		
		ipͷ��
				version���汾
				�ɣȣ̣�ͷ������
				TOS �����ݰ������ȼ�
				total len:  20�ֽ�ipͷ +  32�ֽ�tcpͷ(20�ֽ�+12option) +��data(26) == 78
				identification�� �������(����з�Ƭ�����ڱ�ʾ�����Ƭ�Ƿ���ͬһ����)
				ip flag����ʾ�Ƿ��з�Ƭ
				fragment offset�� ��Ƭ�ڴ���еı��(ƫ����)
				�����죺�����ʱ�䣶����ÿ�ξ���һ��·��������
				protol�� ipͷ�������ʲôͷ
				У����
	
		tcp��ͷ��
				Դ�˿�
				Ŀ��˿�
				���ͷ������ݵ����к�
				���շ���֮ǰ���͹��������ݵ���Ӧ
				offset:��ʾ����ͷ���Ĵ�С
				tcp flag��		��ʾ�Ƿ�sync�� fin�� ack��reset�� push
				window����ʾ�������ݵ����ֵ��������������
				У����
				�������ݣ�����������
		

5���ļ�IOģ�ͣ������ļ���ȡ�ķ�ʽ
		a�� �����������ļ����豸����д��ʱ�����û����Դ���������̾ͻ����ߣ��ó�����Ȩ����ʡcpu����Դ��
				�󲿷ֵ��ļ���������������
					fgets();
					scanf()
					read()/write();
					accept();
		b�� ������: ���ļ����豸����д��ʱ�����û����Դ������������һ��������(-EAGAIN)
					�õıȽ���,��Ҫ��while()������
				
				���ļ��򿪵�ʱ��
					1, fd = open("xxx",  O_RDWR|O_NONBLOCK);

					2, read()/write() ==>�������������ݾͶ�д��û�����ݾ�������
				�ļ���֮��
					1,fd = open("xxx",  O_RDWR);
						fd = socket(AF_INET, SOCK_STREAM, 0);
					2.fcntl( )����
						int fcntl(int fd, int cmd, long arg);
					  int flag��
					  flag = fcntl(sockfd, F_GETFL, 0);
					  flag |= O_NONBLOCK;
					  fcntl(sockfd, F_SETFL, flag);

		c�� ��·����select/poll
				ͬʱ���Լ�ض���ļ��Ϸ����Ķ���д������---����æȥ�ȣ��ȵ����ݺ����֪ͨ��
				���󣺸�д�����
						1���ȴ��ͻ��˵�����
						2���ȴ��ͻ��˵�����
						3���ȴ�����˱�׼���룬�����ݷ��͵��ͻ���
				
				  void FD_CLR(int fd, fd_set *set);
			   int  FD_ISSET(int fd, fd_set *set);
			   void FD_SET(int fd, fd_set *set);
			   void FD_ZERO(fd_set *set);
				int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
				����1�������ļ�������+1
				����2��������
				��������д����
				����4�� ������
				����5�� ��ض�ã��������NULL��һֱ��
							struct timeval {
							   long    tv_sec;         /* seconds */
							   long    tv_usec;        /* microseconds */
						   };

						   struct timeval time;
						   time.tv_sec = 5;
						   time.tv_sec = 0;

				����ֵ�� ����0����ʾ�ж��ٸ�fd�����˶�д����
						     С��0����ʾ����


			
����
			1�� ��ɲ���������---���߳�ȥʵ��
			2�� ����ļ�����--- 
					������
							1�������򵥵��ļ�����
							2������һ���ļ���ϢЭ�飬�ȴ��ļ�����Ϣ��Ȼ���ڴ��ļ�����
										Э�����ַ���--�Լ�����
			3���������κ��Ĵ�����---ͨ��ʹ��wireshark
						sudo wireshark
						����ץ���Ľӿ�--eth0(�����)
												����ʹ��psudo any
						����ץ���Ĺ�����
									tcp port 9999
						��������ͷ���������������ֺ��Ĵ�����
			4������selectȥʵ�ֿͻ���
					�����û����룬�������ݷ��͸������
					ͨ�����Խ��ܵ�����˵�����