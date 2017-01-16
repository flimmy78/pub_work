#include "dvr_uart.h"
#include "sd_file.h"

int set_com_config(int fd, int baud_rate, int data_bits, char parity, int stop_bits)
{
    struct termios new_cfg, old_cfg;
    int speed;

    if(tcgetattr(fd, &old_cfg) != 0)
    {
        perror("tcgetattr");
        return (-1);
    }
    new_cfg = old_cfg;
    cfmakeraw(&new_cfg);
    new_cfg.c_cflag &= ~CSIZE;

    /* 1.设置波特率 */
    switch(baud_rate)
    {
    case 2400:
    {
        speed = B2400;printf("baud_rate 2400 %d\n", speed);
    }
    break;

    case 4800:
    {
        speed = B4800;printf("baud_rate 4800 %d\n", speed);
    }
    break;
    case 9600:
    {
        speed = B9600;printf("baud_rate 9600 %d\n", speed);
    }
    break;
    case 19200:
    {
        speed = B19200;printf("baud_rate 19200 %d\n", speed);
    }
    break;
    case 38400:
    {
        speed = B38400;printf("baud_rate 38400 %d\n", speed);
    }
    break;
    case 115200:
    {
        speed = B115200;printf("baud_rate 115200 %d\n", speed);
    }
    break;
    default:
        speed = B115200;
        break;
    }
    cfsetispeed(&new_cfg, speed);
    cfsetospeed(&new_cfg, speed);
    printf("speed = %d\n", speed);

    /* 2.设置数据位 */
    switch(data_bits)
    {
    case 7:
    {
        new_cfg.c_cflag |= CS7;printf("data_bits 7\n");
    }
    break;
    case  8:
    {
        new_cfg.c_cflag |= CS8;printf("data_bits 8\n");
    }
    break;

    default:
        new_cfg.c_cflag |= CS8;
        break;
    }

    /* 3. 设置奇偶校验位 */
    switch(parity)
    {
    case 'n':
    case 'N':
    {
        new_cfg.c_cflag &= ~PARENB;
        new_cfg.c_iflag &= ~INPCK;printf("parity: No\n");
    }
    break;
    case 'o':
    case 'O':
    {
        new_cfg.c_cflag |= (PARODD | PARENB);
        new_cfg.c_iflag |= INPCK;printf("parity: Odd\n");
    }
    break;

    case 'e':
    case 'E':
    {
        new_cfg.c_cflag |= PARENB;
        new_cfg.c_cflag &= ~PARODD;
        new_cfg.c_iflag |= INPCK;printf("parity: Even\n");
    }
    break;
    case 's':
    case 'S':
    {
        new_cfg.c_cflag &= ~PARENB;
        new_cfg.c_cflag &= ~CSTOPB;printf("parity: Space\n");
    }
    break;
    default:
        new_cfg.c_cflag &= ~PARENB;
        new_cfg.c_iflag &= ~INPCK;
        break;
    }

    /* 4.设置停止位 */
    switch(stop_bits)
    {
    case 1:
    {
        new_cfg.c_cflag &= ~CSTOPB;printf("stop_bits 1\n");
    }
    break;
    case 2:
    {
        new_cfg.c_cflag |= CSTOPB;printf("stop_bits 2\n");
    }
    default:
        new_cfg.c_cflag &= ~CSTOPB;
        break;
    }

    new_cfg.c_cc[VTIME] = 0;
    new_cfg.c_cc[VMIN] = 1;
    tcflush(fd , TCIFLUSH);
    if((tcsetattr(fd, TCSANOW, &new_cfg)) != 0)
    {
        perror("tcsetattr");
        return (-1);
    }
    return 0;
}

int open_port(int com_port)
{
    int fd;
#if (COM_TYPE == GENERAL)
    char *dev[] = {"/dev/ttySGK0", "/dev/ttySGK1", "/dev/ttySGK2"};
#else
    char *dev[] = {"/dev/ttyUSB0", "/dev/ttyUSB1", "/dev/ttyUSB2"};
#endif

    if((com_port < 0) || (com_port > MAX_COM_NUM))
    {
        return (-1);
    }
    fd = open(dev[com_port -1], O_RDWR|O_NOCTTY|O_NDELAY);
    printf("Open the %s fd is %d\n", dev[com_port - 1], fd);
    if(fd < 0)
    {
        perror("Open serial port");
        return (-1);
    }

    if(fcntl(fd, F_SETFL, 0) < 0)
    {
        perror("fcntl F_SETFL\n");
    }

    if(isatty(fd) == 0)
    {
        perror("This is not a termial device");
    }
    return fd;
}

signed int gk_open_com_port(UART_CONFIG uart_config)
{
    signed int fd = 0;

    if((fd = open_port(uart_config.UartID)) == -1)
    {
        return UART_ERR_OPEN_FAIL;
    }

    if(set_com_config(fd,uart_config.BaudRate,uart_config.DataBite,uart_config.Parity,uart_config.StopBite) == -1)
    {
        return UART_ERR_CONFIG_FAIL;
    }

    return fd;
}

int gk_close_com_port(signed int fd)
{
    if(close(fd) == -1)
    {
        perror("close com port\n");
        return (-1);
    }
    return 0;
}

signed int gk_read_com_port(signed int fd,char *read_buf,int read_size)
{
    fd_set fds,rd_fds;
    signed int ret = 0;
    struct timeval tv;
    signed int read_real_size = 0;

    FD_ZERO(&fds);
    FD_SET(fd,&fds);

    rd_fds = fds;
    //wr_fds = fds;
    tv.tv_sec = Wtime;
    tv.tv_usec = 0;
    ret = select(fd+1,&rd_fds,NULL,NULL,&tv);

    if(ret == 0) return 0;
    else if(ret < 0)
    {
        perror("select err\n");
        return -1;
    }
    else
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

signed int gk_write_com_port(signed int fd,char* write_buf,int write_size)
{
    fd_set fds,wr_fds;
    signed int ret = 0;
    struct timeval tv;
    signed int write_real_size = 0;

    FD_ZERO(&fds);
    FD_SET(fd,&fds);

    //rd_fds = fds;
    wr_fds = fds;
    tv.tv_sec = Wtime;
    tv.tv_usec = 0;
    ret = select(fd+1,NULL,&wr_fds,NULL,&tv);

    if(ret == 0) return 0;
    else if(ret < 0)
    {
        perror("select err\n");
        return -1;
    }
    else
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



#ifdef DEBUG_TEST
int main(int argc, char* argv[])
{
    /* 1.打开配置串口，返回设备文件描述符 */
    int uart_fd;
    UART_CONFIG uart_cfg = {
        .UartID = UART_2,
        .BaudRate = 115200,
        .DataBite = 8,
        .Parity = 'N',
        .StopBite = 1
    };  //初始化参数

    uart_fd = gk_open_com_port(uart_cfg);   //打开配置设备
    if(uart_fd < 0)
    {
        printf("gk_open_com_port err\n");
        return(-1);
    }
    else
    {
        printf("gk_open_com_port OK\n");
    }

    /* 2.新建文件，返回文件描述符  */
    char path_str[49];
    int sd_fd;
    //sd_fd = open_sd_file(SD_DATA_DEFAULT_FILE);
    get_file_path(path_str,49);
    sd_fd = open_sd_file(path_str);

    /* 3.向串口写数据 */
    int ret = gk_write_com_port(uart_fd,"<1234567890ABCD~!@#$%^&*()_+WXYZ>\n", 34);
    if(ret != 34)
    {
        printf("Write err\n");
    }
    else
    {
        printf("write data ok\n");
    }

    /* 4.从串口中读数据，并存储*/
    unsigned int count_read = 0,count_write = 0;
    while(1)
    {
        char RBUF[BUFSIZ];

        memset(RBUF,0,BUFSIZ);
        int real_read_size = 0;
        real_read_size = gk_read_com_port(uart_fd, RBUF,BUFSIZ);
        if(real_read_size < 0)
        {
            printf("%s (%d) [%s] read uart port err\n",__FILE__,__LINE__,__func__);
        }
        else if(real_read_size > 0)
        {
            count_read++;
            printf("\n----------Receive UART_data %d\n",count_read);
            while(count_read == UINT_MAX)
            {
                count_read = 0;
            }
        }
#ifdef PRINTF_UART
        int i = 0;
        for(i = 0; i < real_read_size; i++)
        {
            printf(" 0x%02X",RBUF[i]);
        }
#endif
        ret = write(sd_fd,RBUF,real_read_size);
        if(ret != real_read_size)
        {
            perror("write RBUF to stdout err");
        }
        else if(ret > 0)
        {
            count_write++;
            printf("\n++++++++++Write to SD_FILE  %d\n",count_write);
            while(count_write == UINT_MAX)
            {
                count_write = 0;
            }    
        }

        fsync(sd_fd);
        fflush(NULL);
        //printf("\n");
    }

    gk_close_com_port(uart_fd); //关闭设备
    close(sd_fd);
    
    
    return 0;
}
#endif
