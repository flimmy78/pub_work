/*******************************************************************
 *   > File Name: 04-ioctl.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 02 Mar 2017 11:32:08 AM CST
 ******************************************************************/
#if (0)
int ioctl(int d, int request, ...);
#endif

#include <stdio.h>
/*inlcude file for ioctl*/
#include <sys/ioctl.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    int retval;
    
    /*假设打开键盘灯，依设备所支持的操作不同*/
    if((retval = ioctl(tty_fd, KDSETLED, LED_NUM|LED_CAP|LED_SCR)) != 0){
        perror("ioctl err");return errno;
    }

    return 0;
}
