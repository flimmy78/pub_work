TCPЭ�飺
	1������TCP/IPЭ������һ��
	2�� ��������
	3�� ��ȫ�������׶���
	4��������ʧ��

UDPЭ�飺����Ч����Ի��
	1������TCP/IPЭ������һ��
	2�� ����������
	3�� ����ȫ���׶���
	4�� ��������

���紫���еĻ������
	1��socket
			a�� ��һ�����紫��Ļ����ӿ�
			b�� ������io��open��socketʵ�ʴ�һ�������豸������һ��fd
			c��socke����
					SOCK_STREAM����ʽ�׽��֣��������ݵ�ʱ����һ�ֽ������䣨ͨ���������ӣ�tcp��
					SOCK_DGRAM �����ݰ��׽��֣������ʱ�������ݱ�(���Ȳ�����(ͨ����������ӣ�udp)
					SOCK_RAW ��ԭʼ�׽���,��Ҫ��ȥ�����ײ��Э��(ping��ʵ�֣� icmpЭ��)
	
	2��ip��Internet�������ı�ʶ
			1�����ĶΣ����õ����ʽ
					192.168.7.100
			2, ip������--�ֳ���������
					����id  +  ����id
					A�ࣺ
							0.0.0.0---127.255.255.255
					B�ࣺ
						128.0.0.0-191.255.255.255
					C�ࣺ�������� ����id�����Σ�
						192.0.0.0-223.255.255.255


			����ip��
				255.255.255.255 ȫ�㲥��ַ
				192.168.7.255 �㲥��ַ
				
				192.168.7.0�� �����ʾ��

				255.255.255.0����������
				192.168.7.1 ������
				DNS��������������


				192.168.7.3 ------------------> 192.168.7.2
									ͨ������õ������Ƿ�����ͬһ������
									�������ͬһ�������Ҫ����ת����ȥ

									baidu.com ----- ip(123.125.114.144)
									����					��������ip
										|
									������ip
										|
										dns202.96.128.86
											 8.8.8.8
											 114.114.114.114
		
		2,�˿ںţ���ʾһ�����̣���Ҫȥ�󶨣�ʵ����һ��16bit����
				1�����Զ�̬����
				2�������Զ�����---Խ��Խ�ã�9999��10000
		
		3���ֽ���--��˺�С��
				��ˣ���λ�ȴ�
				С�ˣ���λ�ȴ�

				�����д����ʱ����Զ���Ǵ��
				u_long htonl (u_long hostlong);��//�������ݳ�ȥ��ʱ��
				u_short htons (u_short short);


				u_long ntohl (u_long hostlong);//��������������
				u_short ntohs (u_short short);
		
		4�� ipת��
				��д����: �ַ���"192.168.7.3"
				�����У�������ַ���ɶ����ƣ���һ������
				ת����
						in_addr_t inet_addr(const char *strptr);
						����1�� �ַ���
						����ֵ�����������ģ���ֵַ
	

								
���Уɣ�
	���������׽���
		��int socket(int domain, int type, int protocol);
			��������ͨ���򣭣������������ͨ��
						AF_UNIX/AF_LOCAL��������ͨ��
						AF_INET���������ͨ��--�õ�Э����ipv4
			����2������ʲô����������
					SOCK_STREAM: �������ֽ���---tcp
					SOCK_DGRAM ������������ݱ�-- udp
					SOCK_RAW �� ��������ڲ�Э��--icmp

			����3���������ĸ�Э��--0
	
		�÷���
			tcp��̣�
					socket(AF_INET, SOCK_STREAM, 0);

			udp���:
					socket(AF_INET, SOCK_DGRAM, 0);

	
		2, bind�����̺Ͷ˿ںź�ip��ַ(��ǰ����)���а󶨣��Ϳ��Ա���������
			 int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
			 ����1����ǰ�Ĵ����ģ������
			 ����������ַ�Ͷ˿ڵ���Ϣ
			 ����3����ַ����Ϣ�ĳ���

			��ַ�Ͷ˿ڵ���Ϣ��struct sockaddr *addr����ͨ�õ�ַ��
				ʵ���ã���struct sockaddr_in
				struct sockaddr_in
				  {           
					   u_short sin_family;      // ��ַ��, AF_INET��2 bytes
					   u_short sin_port;      // �˿ڣ�2 bytes, �Լ�ѡ��ת����������ֽ���( ���)htons();
					   struct in_addr sin_addr;  // IPV4��ַ��4 bytes 	
					   char sin_zero[8];        // 8 bytes unused����Ϊ���
				  }; 

				struct in_addr
				{
					 in_addr_t  s_addr;            // u32 network address 
				};

				��ʼ��struct sockaddr_in
				struct sockaddr_in  self_addr;
				self_addr.sin_family = AF_INET;
				self_addr.sin_port = htons(9999);
				self_addr.sin_addr.s_addr = inet_addr("192.168.7.5");

				ʹ�ã� grep -rHn 'struct sockaddr_in'  /usr/include/
				#include <linux/in.h>
				int bind(fd, ��const struct sockaddr * ��&self_addr,   sizeof(self_addr));

			3, listen();��ʾ������������ͬһʱ��㣬����ͬʱ���ӵ����Ŀͻ��˵ĸ���
				int listen(int sockfd, int backlog);
					����2�����Ŀͻ��˵ĸ���������������
				
			����accept()�ȴ��ͻ��˵����ӣ�����
				int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
				����1�� ����˵Ĵ�����socket��Ӧ��fd
				����2,3��ʾ�ͻ��˵���Ϣ����ȻҲ���Բ����ĶԷ���˭���Ϳ�����NULL�� NULL
				����ֵ������һ���µ��ļ����������Ϳͻ��˽�������ͨ�ŵ�
				��򵥵��÷���
					int  new_fd = accept(fd, NULL, NULL);
				
			
			�ͻ��ˣ�
				int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
				����2����ʾ���ӵ��ĸ�����������Ҫ������Ϣ

	


	��ַת�������ǽ��ַ���ת����u32
		1��in_addr_t inet_addr(const char *cp);
			�ŵ㣺 ����
			ȱ�㣺����ת��"255.255.255.255", 
		2�� int inet_aton(const char *cp, struct in_addr *inp);
			ȱ�㣺ֻ������ipv4
			�÷���
				struct in_addr addr;
				inet_aton("192.168.7.6", &addr);

		3��int inet_pton(int af, const char *src, void *dst);
			ȱ�㣺�����Ƚ϶�
			��������ipv4,��ipv6��ַת��


		self.sin_addr.s_addr = htonl(INADDR_ANY); //������������ip

udp:���ͺͽ������ݣ�
	 ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,struct sockaddr *src_addr, socklen_t *addrlen);
	  ����5,6��ʾ���ͷ�����Ϣ�� ��accept�к�����������һ��

