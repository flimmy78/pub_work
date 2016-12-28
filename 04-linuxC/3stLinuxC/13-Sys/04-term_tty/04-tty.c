/*******************************************************************
 *   > File Name: 04-tty.c
 *   > Author: fly
 *   > Mail: 1234578@qq.com
 *   > Create Time: Wed 28 Dec 2016 09:19:28 AM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <termios.h>

#define COM_NUM_T 2

int get_com_attr(int com_fd);


int main(int argc, char **argv)
{
    char ttyNamePath[20] = "/dev/ttySGK";
    int COM_NUM = -1;

    /*判断命令行参数，获得设备路径*/
    if(argc != 2)
    {
        printf("Usage : %s ttyNUM\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        COM_NUM =*((char *) argv[1]) - 48;

        if(COM_NUM >= 0 && COM_NUM <= COM_NUM_T)
        {
            printf("ttyNamePath : %s\n",strcat(ttyNamePath, argv[1]));
        }
        else
        {
            printf("NO such device , except COM0/1/2 \n");
            return -1;
        }
    }

    int com_fd;
    /*打开串口*/
    printf("%s\t",ttyNamePath);
    com_fd = open(ttyNamePath,O_RDWR);
    if(com_fd == -1)
    {
        perror("open");
        exit(1);
    }
    else
    {
    
        if(isatty(com_fd))
        {
            printf("is a tty .\n");
            //printf("ttyname %s .\n",ttyname(com_fd));
        }
        else
        {
            printf("is not a tty .\n");
        }

        get_com_attr(com_fd);
    }

    if((write(com_fd, "\n\t\tWrite some data to com\n\n", 27)) != 27)
    {
        perror("write");
        return -1;
    }
    else
    {
        write(1,"Send data succeed .\n",24);
    }

#if(0)
    /*从串口中读取数据*/
    while(COM_NUM == 0)
    {
        char Read_BUF[128];
        int ret = -1;

        memset(Read_BUF, 0, 128);
        ret =read(com_fd, Read_BUF, 128);
        if(ret == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("%s",Read_BUF);
        }
    }
#endif

    close(com_fd);

    return 0;
}

/*获取串口属性*/
int get_com_attr(int com_fd)
{
    int ret;
    unsigned int Ispeed, Ospeed;
    struct termios com_cfg;

    ret = tcgetattr(com_fd,&com_cfg);
    if(ret == -1)
    {
        perror("tcgetattr");
        return (-1);
    }

#if 1
    printf("Input mode flags : %d\n"
            "Output mode flags : %d\n"
            "Control mode flags : %d\n"
            "Local mode flags : %d\n"
            "Line discipline : %c\n"
            "Control character : %s\n",
            com_cfg.c_iflag,
            com_cfg.c_oflag,
            com_cfg.c_cflag,
            com_cfg.c_lflag,
            com_cfg.c_line,
            com_cfg.c_cc
            );
#else
    printf("Input mode flags : %d\n\
            Output mode flags : %d\n\
            Control mode flags : %d\n\
            Local mode flags : %d\n\
            Line discipline : %c\n\
            Control characters : %s\n\
            Input speed : %d\n\
            Output speed : %d\n",
            com_cfg.c_iflag,
            com_cfg.c_oflag,
            com_cfg.c_cflag,
            com_cfg.c_lflag,
            com_cfg.c_line,
            com_cfg.c_cc,
            com_cfg.c_ispeed,
            com_cfg.c_ospeed);
#endif
    Ispeed = cfgetispeed(&com_cfg);
    Ospeed = cfgetospeed(&com_cfg);
    printf("Input speed : %d\n"
            "Output speed : %d\n",
            com_cfg.c_ispeed,
            com_cfg.c_ospeed);

    return 0;
}
