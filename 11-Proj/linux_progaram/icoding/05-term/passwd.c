/*******************************************************************
 *   > File Name: passwd.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 19 Apr 2017 12:00:26 PM CST
 ******************************************************************/

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>

#define PASSWORD_LEN    8

int main(int argc, char* argv[])
{
    struct termios initialsettings, newrsettings;
    char password[ PASSWORD_LEN + 1 ];
    
    /*获取标准输入的当前设置*/
    tcgetattr(fileno(stdin), &initialsettings);
    newrsettings = initialsettings;
    /*禁止回显，关闭ECHO标志*/
    newrsettings.c_lflag &= ~ECHO;

    printf("Enter passwd :");
    if(tcsetattr(fileno(stdin), TCSAFLUSH, &newrsettings) != 0){
        fprintf(stderr, "Could not set attributes\n");
    }else{
        fgets(password, PASSWORD_LEN , stdin);
        tcsetattr(fileno(stdin), TCSANOW, &initialsettings);
        fprintf(stdout, "\nYou entered %s", password);
    }

    return 0;
}
