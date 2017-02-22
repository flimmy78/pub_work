#include "dvr_uart.h"

int set_com_config(int fd, int baud_rate, int data_bits, char parity, int stop_bits){
    struct termios new_cfg, old_cfg;
    int speed;

    if(tcgetattr(fd, &old_cfg) != 0){
        perror("tcgetattr ");
        return (-1);
    }
    new_cfg = old_cfg;
    cfmakeraw(&new_cfg);
    new_cfg.c_cflag &= ~CSIZE;

    switch(baud_rate)   /* 1.设置波特率 */{
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
            speed = B115200;printf("default baud_rate 115200 %d\n",speed);
            break;
    }
    cfsetispeed(&new_cfg, speed);
    cfsetospeed(&new_cfg, speed);
    printf("speed = %d\n", speed);

    switch(data_bits)   /* 2.设置数据位 */
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
            new_cfg.c_cflag |= CS8;printf("default data_bits 8\n");
            break;
    }

    switch(parity)  /* 3.设置奇偶校验位 */{
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
            new_cfg.c_iflag &= ~INPCK;printf("default parity: None\n");
            break;
    }

    switch(stop_bits)   /* 4.设置停止位 */{
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
            new_cfg.c_cflag &= ~CSTOPB;printf("default stop_bits 1\n");
            break;
    }

    new_cfg.c_cc[VTIME] = 0;
    new_cfg.c_cc[VMIN] = 1;
    tcflush(fd , TCIFLUSH);
    if((tcsetattr(fd, TCSANOW, &new_cfg)) != 0){
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

    if((com_port < 0) || (com_port > MAX_COM_NUM)){
        return (-1);
    }

    if((fd = open(dev[com_port -1], O_RDWR|O_NOCTTY|O_NDELAY)) < 0){
        perror("Open serial port");
        return fd;
    }
    printf("Open the %s fd is %d\n", dev[com_port - 1], fd);

    if(fcntl(fd, F_SETFL, 0) < 0){
        perror("fcntl F_SETFL\n");
    }

    if(isatty(fd) == 0){
        perror("This is not a termial device");
    }
    return fd;
}

signed int gk_open_com_port(UART_CONFIG uart_config){
    signed int fd = 0;

    if((fd = open_port(uart_config.UartID)) == -1){
        return UART_ERR_OPEN_FAIL;
    }

    if(set_com_config(fd,
                uart_config.BaudRate,
                uart_config.DataBite,
                uart_config.Parity,
                uart_config.StopBite) == -1){
        return UART_ERR_CONFIG_FAIL;
    }

    return fd;
}

int gk_close_com_port(signed int fd){
    if(close(fd) == -1){
        perror("close com port\n");
        return (-1);
    }
    return 0;
}

signed int gk_read_com_port(signed int fd,char *read_buf,int read_size){
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

    if(ret == 0) return 0;/*超时*/
    else if(ret < 0){/*出错*/
        perror("select err\n");
        return -1;
    }else{/*可读*/
        if(FD_ISSET(fd,&rd_fds)){/*找出可读文件*/
            read_real_size = read(fd,read_buf,read_size);
            if(read_real_size < 0){
                return -1;
            }
            return read_real_size;
        }else{
            return 0;
        }
    }
}

signed int gk_write_com_port(signed int fd,char* write_buf,int write_size){
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

    if(ret == 0) return 0;/*超时*/
    else if(ret < 0){/*出错*/
        perror("select err\n");
        return -1;
    }else{/*可写*/
        if(FD_ISSET(fd,&wr_fds)){/*找出可写文件*/
            write_real_size = write(fd,write_buf,write_size);
            if(write_real_size < 0){
                return -1;/*出错返回-1*/
            }
            return write_real_size;/*返回写入的字节数*/
        }else{
            return 0;/*未读到数据，返回0*/
        }
    }

}

int uart_fd_init(void){
    int uart_fd;
    UART_CONFIG uart_cfg = {
        .UartID = UART_2,
        .BaudRate = 115200,
        .DataBite = 8,
        .Parity = 'N',
        .StopBite = 1
    };
    
    uart_fd = gk_open_com_port(uart_cfg);
    if(uart_fd < 0){
        printf("gk_open_port err");
        return (-1);
    }else{
        return (uart_fd);
    }
}

int SetPthreadStackSize(pthread_attr_t *attr, size_t stacksize){
    if((pthread_attr_init(attr)) != 0){/*初始化属性*/
        printf("pthread_attr_init");return (-1);
    }
    if((pthread_attr_setstacksize(attr,stacksize)) != 0){/*设置栈的大小*/
        printf("pthread_attr_setstacksize");return (-2);
    }
    return 0;
}
