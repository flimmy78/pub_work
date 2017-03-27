0, setsockopt �����׽���ѡ��
1, �㲥
2���鲥
3�� ��������
4��unix�׽���---����ͨ��
====================================
select�������Ҫͬʱ�Զ���ļ�( �豸)���ж�д
	0,��ʼ��---���λ��
		FD_CLR(&fd_set);
	1,����λ��--�趨����ļ����ļ�
		FD_SET(fd, &fd_set);
		FD_SET(fd, &fd_set);
		FD_SET(fd, &fd_set);
	2, select()һ�����أ���ʾ�ж����������ݣ�
	3,  ����ж����ĸ��ļ�������
			FD_ISSET();�������
					�Ϳ��Ե��ö�д���ݵĺ���
						accept(); <-----select�������������ֵĵ�һ�����֣��ͱ�ʾ������

ʵ�ʻ���һ��: poll
	int poll(struct pollfd *fds, nfds_t nfds, int timeout);
	����1������ļ��������ļ���
	����2����ص��ļ��������ĸ���
	����3����ص�ʱ��: ������ʾ���޵�
	  struct pollfd {
               int   fd;         //��ʾ��Ҫ��ص�fd
               short events;     //ϣ�����fd��ʲô������ д������
									//��POLLIN ,дPOLLOUT�� ����POLLERR
               short revents;   //���,��������ݣ��ں˻��Զ�ȥ�����������������ȥ�ж�
           };
	����ֵ������0����ʾ������
				С��0�� ����
				�����㣺��ʱ
	ʹ�ã�
		struct pollfd pfd[2];

		pfd[0].fd = 0;
		pfd[0].events |= POLLIN;

		pfd[1].fd = fd;
		pfd[1].events |= POLLIN;

		ret = poll(pfd, 2, -1);
			
		������أ�
				if(pfd[1].revents & POLLIN)
				��
				��


�����׽������ԣ�
	int setsockopt(int sockfd,int level,int optname,const void *optval,socklen_t *optlen)
	����1���򿪵ģ������
	�����������׽��ֵĲ�Σ�
				1)SOL_SOCKET:ͨ���׽���ѡ��. �������õ�ַ���ã��㲥
				2)IPPROTO_IP:IPѡ��. ���������鲥�����ý���ǰ�����뵽һ���飬��������
				3)IPPROTO_TCP:TCPѡ��.��
	����������ѡ�����֣�
					����SO_BROADCAST
						SO_REUSEADDR
	����4��ѡ���ֵ
	��������ѡ��ֵ�ĳ���

	ʹ�ã�
		ʹ���ڹر�ͨ�ŵ�ʱ���������һ������û���յ���ʱ�򣬿������£����
		int on = 1;
		setsockopt(fd,  SOL_SOCKET, SO_REUSEADDR,  &on, sizeof(on)); //ֻҪ�ڷ���ˣ�bind֮ǰ����Ҫ�����
		
				

1, �㲥--�����������л�����������
		�㲥��ַ��
				255.255.255.255
				192.168.7.255
		
		a, �㲥��Ҫ��---���ͷ�
			setsockopt();
		b�� ������udp

		int inet_pton(int af, const char *src, void *dst);
		����1����ַ�ǣ��������ǣ�����
				��AF_INET
		����2���ַ�����ʽ��ip��ַ
		����3��ת��֮��ĵ�ַ(32bit)struct in_addr

		ʹ�ã�
			inet_pton(AF_INET, "255.255.255.255",  &peer.sin_addr);


2���鲥: �������������һ���飬��������ֻ���⼸��������յ�����, �鲥��Ҫ�ں˵�֧��
	  a�� ���ڽ��շ���Ҫ���뵽�鲥ip
				setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq,  sizeof(mreq));
	  b�� ���ͷ���Ҫ���͵��鲥ip
	  c�� �鲥ip��
			224.0.0.1 �C 239.255.255.255
		e����Ȼʹ��udp
	

3�� ��������---oob: out of band,���ڷ���һЩ������Ϣ(���ȼ��Ƚϸߵ�)
	���շ�����
		1������ȥ��������
		2��Ҳ���Խ��մ�������
					  �����ź�signal--SIGURG
			SIGURG: ���Ҫ��������ź�
					a,ע���źŴ�����
					b�� �����ź����������̣�SIGURG�Ǹý��̽��գ�
							fcntl(new_fd, F_SETOWN, getpid());

4�����׽��֣�unix socket�����ڱ���ͨ��(ipc����һ��)
		a����̷�ʽʹ����socket��api
		b,  ʵ��ģ�ͺ���ܵ�
				A --- �ļ�----B

				socketpair�����ڸ��ӽ��̣��������������ܵ�
				socket() + bind() +listen + accept+read/write --�����������ܵ�


				������ͨ�Ų�ͬ�ĵط�:
					1,�����׽���
							int  fd = socket(AF_LOCAL, SOCK_STREAM, 0);
					
					2, ��
							struct sockaddr_un  addr;
							 addr.sun_family = AF_LOCAL;
							 strcmp(&addr.sun_path, "/tmp/xxx");

							 bind(fd, (struct sockaddr *)&addr, sizeof(addr));
					
					3, listen
					4, accept





5����������
		struct hostent *gethostbyname(const char *name);

		 struct hostent {//��Ϣ�����壬��¼�˷��ص�����������Ϣ�Ľ��
               char  *h_name;            /* official name of host */
               char **h_aliases;         /* alias list */
               int    h_addrtype;        /* host address type */
               int    h_length;          /* length of address */
               char **h_addr_list;       /* list of addresses */ // ip��ַ���б�
           }
           #define h_addr h_addr_list[0] /* for backward compatibility */
