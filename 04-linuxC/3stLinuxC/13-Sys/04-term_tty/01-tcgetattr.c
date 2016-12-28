/*******************************************************************
 *   > File Name: 04-tcgetattr.c
 *   > Author: fly
 *   > Mail: 1234578@qq.com
 *   > Create Time: Wed 28 Dec 2016 01:49:05 PM CST
 ******************************************************************/

#include <stdio.h>

/*---------------------------------------------------------------*/
#if (0)
typedef unsigned char   cc_t;    
typedef unsigned int    speed_t; 
typedef unsigned int    tcflag_t; 

#define NCCS 19
struct termios {
    tcflag_t c_iflag;       /* input mode flags :输入参数 */
    tcflag_t c_oflag;       /* output mode flags ：输出参数*/
    tcflag_t c_cflag;       /* control mode flags ：控制参数*/
    tcflag_t c_lflag;       /* local mode flags ：本地模式参数*/
    cc_t c_line;            /* line discipline :线控制*/
    cc_t c_cc[NCCS];        /* control characters ：控制字符*/
}; 


#include <termios.h>
#include <unistd.h>

int tcgetattr(int fd, struct termios *termios_p);

int tcsetattr(int fd, int optional_actions,
        const struct termios *termios_p);

int tcsendbreak(int fd, int duration);

int tcdrain(int fd);

int tcflush(int fd, int queue_selector);

int tcflow(int fd, int action);

void cfmakeraw(struct termios *termios_p);

speed_t cfgetispeed(const struct termios *termios_p);

speed_t cfgetospeed(const struct termios *termios_p);

int cfsetispeed(struct termios *termios_p, speed_t speed);

int cfsetospeed(struct termios *termios_p, speed_t speed);

int cfsetspeed(struct termios *termios_p, speed_t speed);

#endif
/*---------------------------------------------------------------*/

int main(void)
{
    return 0;
}

void  get_com_attr(void)
{
    int ret ;
    struct termios com_cfg;


}
