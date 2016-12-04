

int SetPthreadStackSize(pthread_attr_t *attr, int stacksize)
{
	if(pthread_attr_init(attr) != 0)	/*初始化线程属性*/
	{
		fprintf(stderr,"Pthread_attr_init err \n");
		return (-1);
	}

	if(pthread_attr_setstacksize(attr, stacksize) != 0)	/*设置线程栈的大小*/
	{
		fprintf(stderr,"Pthread_attr_setstacksize err \n");
		return (-1);
	}

	return 0;	/*成功设置线程栈的大小，返回0*/
}

static void *app_CgiServicePthread(void *param);
void CGI_startPthreadService(void)
{
	pthread_t cgi_tid;		/* 定义一个线程标识符 */
	pthread_attr_t attr;	/* 定义一个线程属性 */

	SetPthreadSatckSize(&attr,250000);	/* 设置线程栈的大小为0.25M*/
	if(pthread_create(&cgi_tid, &attr,app_CgiServicePthread,NULL) != 0)	/*创建线程，运行线程函数 */
	{
		perror("Pthread_create:app_CgiServiecePthread ");	
	}
}

int cgi_read_fifo(int fd,cgi_msg_t *p_fifo_msg, int time_out_sec)
{
	struct timeval timeout;
	timeout.tv_sec = time_out_sec;	/* second */
	timeout.tv_usec = 0;			/* microsecond */

	cgi_msg_t cgi_msg;				/* 定义一个数据包 */
	memset(&cgi_msg, 0,sizeof(cgi_msg_t));/*数据包存储空间全部填充0*/

	fd_set fds;			/*定义一个文件句柄集合*/
	FD_ZERO(&fds);		/*清空文件句柄集合*/
	FD_SET(fd,&fds);	/*将文件句柄添加到集合里*/

	switch(select(fd + 1, &fds, NULL, NULL, &timeout))
	{
		case 0:			/* 超时 */
			{
				printf("Time out \n");
				return (-1);
			}
		case (-1):		/* 出错 */
			{
				printf("Select err \n");
				return (-1);
			}
		default:		/* 有数据可读 */
			{
				if(FD_ISSET(fd, &fds))		/* fd可读 */
				{
					if(read(fd , &cgi_msg,sizeof(cgi_msg_t)) <= 0) /* 将数据读到cgi_msg  */
					{
						fprintf(stderr,"Server read cmd err \n");
						return (-1);
					}
					*p_fifo_msg = cgi_msg;		/* 将数据cgi_msg放在p_fifo_msg所指向的内存 */
				}
			}
	}

	return 0;
}
