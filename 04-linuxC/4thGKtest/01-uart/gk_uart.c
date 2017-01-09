#include "gk_uart.h"

/*---------------------------------------------------------------------------------
 *@func:配置串口参数，
 *@param(int fd):打开设备，生成的文件描述符；
 *@param(int baud_rate):波特率
 *@param(int data_bit):数据位
 *@param(char parity):奇偶校验位
 *@param(stop_bits):停止位
 *@return :成功，返回0；失败，返回（-1）；
 ---------------------------------------------------------------------------------*/
int set_com_config(int fd, int baud_rate, int data_bit, char parity, int stop_bits)
{
    printf("The fd is %d , baud_rate is %d , date_bit is %d , parity is %c , stop_bits is %d\n",
            fd, baud_rate, data_bit, parity, stop_bits);

    struct termios old_cfg, new_cfg;
    int speed;

    /* 获取原始配置 */
    if(tcgetattr(fd, &old_cfg) != 0)
    {
        perror("tcgetattr");
        return (-1);
    }

    new_cfg = old_cfg;
    cfmakeraw(&new_cfg);
    new_cfg.c_cflag &= ~CSIZE;

    /* 1.配置波特率 */
    switch(baud_rate)
    {
        case 2400:
            {
                speed = B2400;
                printf("Baud_rate 2400 %d\n",speed);
            }
            break;
        case 4800:
            {
                speed = B4800;
                printf("Baud_rate 4800 %d\n",speed);
            }
            break;
        case 9600:
            {
                speed = B9600;
                printf("Baud_rate 9600 %d\n",speed);
            }
            break;
        case 19200:
            {
                speed = B19200;
                printf("Baud_rate 19200 %d\n",speed);
            }
            break;
        case 38400:
            {
                speed = B38400;
                printf("Baud_rate 38400 %d\n",speed);
            }
            break;
        case 115200:
            {
                speed = B115200;
                printf("Baud_rate 115200 %d\n",speed);
            }
            break;
        default:
            {
                speed = B115200;
                printf("Baud_rate 115200 %d\n",speed);
            }
            break;
    }
    cfsetispeed(&new_cfg, speed);   //设置输入波特率
    cfsetospeed(&new_cfg, speed);   //设置输出波特率

    /* 2.配置数据位 */
    switch(data_bit)
    {
        case 7:
            {
                new_cfg.c_cflag |= CS7;
                printf("Data_bit 7\n");
            }
            break;
        case 8:
            {
                new_cfg.c_cflag |= CS8;
                printf("Data_bit 8\n");
            }
            break;
        default:
            {
                new_cfg.c_cflag |= CS8;
                printf("Default data_bit 8\n");
            }
            break;
    }

    /* 3.配置奇偶校验位*/
    switch(parity)
    {
        case 'n':
        case 'N':
            {
                new_cfg.c_cflag &= ~PARENB;
                new_cfg.c_iflag &= ~INPCK;
                printf("Parity : None\n");
            }
            break;
        case 'o':
        case 'O':
            {
                new_cfg.c_cflag |= (PARODD | PARENB);
                new_cfg.c_iflag |= INPCK;
                printf("Parity : Odd\n");
            }
            break;
        case 'e':
        case 'E':
            {
                new_cfg.c_cflag |= PARENB;
                new_cfg.c_cflag &= ~PARODD;
                new_cfg.c_iflag |= INPCK;
                printf("Parity : Even\n");
            }
            break;
        case 's':
        case 'S':
            {
                new_cfg.c_cflag &= ~PARENB;
                new_cfg.c_cflag &= ~CSTOPB;
                printf("Parity : Space\n");
            }
            break;
        default:
            {
                new_cfg.c_cflag &= ~PARENB;
                new_cfg.c_iflag &= ~INPCK;
                printf("Default parity : None\n");
            }
            break;
    }

    /* 4.配置停止位 */
    switch(stop_bits)
    {
        case 1:
            {
                new_cfg.c_cflag &= ~CSTOPB;
                printf("Stop_bits 1\n");
            }
            break;
        case 2:
            {
                new_cfg.c_cflag |= CSTOPB;
                printf("Stop_bits 2\n");
            }
            break;
        default:
            {
                new_cfg.c_cflag &= ~CSTOPB;
                printf("Default stop_bit 1\n");
            }
            break;
    }

    new_cfg.c_cc[VTIME] = 0;    //
    new_cfg.c_cc[VMIN] = 1;     //
    if(tcsetattr(fd, TCSANOW,&new_cfg) != 0)
    {
        perror("tcsetattr");
        return (-1);
    }

    return 0;
}

/*---------------------------------------------------------------------------------
 *@func:打开设备串口设备
 *@param（int com_port）:设备编号
 *@return:成功，返回文件描述符，失败，返回（-1）；
 --------------------------------------------------------------------------------*/ 

int open_port(int com_port)
{
    int fd;
    char *dev[] = {"/dev/ttySGK0", "/dev/ttySGK1", "/dev/ttySGK2"};

    /* 串口序号是否正确 */
    if((com_port < 0) || (com_port > MAX_COM_NUM))
    {
        return (-1);
    }

    /* 打开相应的串口设备 */
    if((fd = open(dev[com_port], O_RDWR | O_NOCTTY | O_NDELAY)) < 0)
    {
        perror("open");
        return (-1);
    }

    /* 改变打开文件的性质 */
    if(fcntl(fd, F_SETFL, 0) < 0)
    {
        perror("fcntl F_SETFL");
    }

    /* 是否为终端文件*/
    if(isatty(fd) == 0)
    {
        perror("The fd is not a tty");
    }

    return fd;
}

/*---------------------------------------------------------------------------------
 *@func：打开串口设备，并配置串口；
 *@param（UART_CONFIG uart_config）:关于串口设备编号及配置信息的结构体；
 *@return：成功，返回设备文件描述符；失败，返回负数，见定义宏
 --------------------------------------------------------------------------------*/
int gk_open_com_port(UART_CONFIG uart_config)
{
    int fd = 0;
    if((fd = open_port(uart_config.UartID)) == -1)
    {
        return UART_ERR_OPEN_FAIL;
    }

    if(set_com_config(fd,
                uart_config.BaudRate,
                uart_config.DataBite,
                uart_config.Parity,
                uart_config.StopBite) == -1)
    {
        return UART_ERR_CONFIG_FAIL;
    }

    return fd;
}

/*---------------------------------------------------------------------------------
 *@func:关闭设备文件
 *@param（int fd）：设备文件描述符；
 *@return：成功，返回0；失败，返回（-1）；
 ---------------------------------------------------------------------------------*/
int gk_close_com_port(int fd)
{
    if(close(fd) == -1)
    {
        perror("close com port");
        return (-1);
    }
    return 0;
}


/*--------------------------------------------------------------------------------
 *@func：从串口中读取数据
 -------------------------------------------------------------------------------*/
signed int gk_read_com_port(signed int fd,char *read_buf,int read_size)
{
    fd_set fds,rd_fds;
    signed int ret = 0;
    struct timeval tv;
    signed int read_real_size = 0;

    FD_ZERO(&fds);
    FD_SET(fd,&fds);

    rd_fds = fds;

    tv.tv_sec = 10;
    tv.tv_usec = 0;
    ret = select(fd+1,&rd_fds,NULL,NULL,&tv);

    if(ret == 0) return 0;  //超时
    else if(ret < 0)        //出错
    {
        perror("select err\n");
        return -1;
    }
    else                    //文件可读
    {
        if(FD_ISSET(fd,&rd_fds))
        {
            read_real_size = read(fd,read_buf,read_size);
            if(read_real_size < 0)
            {
                return -1;
            }
            return read_real_size;
        }
        else
        {
            return 0;
        }
    }
}

/*---------------------------------------------------------------------------------
 *@func：往串口中写数据
 ---------------------------------------------------------------------------------*/
signed int gk_write_com_port(signed int fd,char* write_buf,int write_size)
{
    fd_set fds,wr_fds;
    signed int ret = 0;
    struct timeval tv;
    signed int write_real_size = 0;

    FD_ZERO(&fds);
    FD_SET(fd,&fds);

    wr_fds = fds;
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    ret = select(fd+1,NULL,&wr_fds,NULL,&tv);

    if(ret == 0) return 0;  //超时
    else if(ret < 0)        //出错
    {
        perror("select err\n");
        return -1;
    }
    else                    //有数据写入
    {
        if(FD_ISSET(fd,&wr_fds))
        {
            write_real_size = write(fd,write_buf,write_size);
            if(write_real_size < 0)
            {
                return -1;
            }
            return write_real_size;
        }
        else
        {
            return 0;
        }
    }

}


