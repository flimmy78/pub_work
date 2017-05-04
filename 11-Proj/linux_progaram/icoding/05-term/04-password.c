/*******************************************************************
 *   > File Name: 04-password.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 04 May 2017 02:16:33 PM CST
 ******************************************************************/
#if (0)
int tcgetattr(int fd, struct termios *termios_p);
int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
#endif

#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

#define PASSWORD_LEN 8

int main()
{
    struct termios initialrsettings, newrsettings;
    char password[PASSWORD_LEN + 1];
    
    /*获取标准的当前设置*/
    tcgetattr(fileno(stdin), &initialrsettings);
    newrsettings = initialrsettings;
    newrsettings.c_lflag &= ~ECHO;

    printf("Enter password :");
    if((tcsetattr(fileno(stdin), TCSAFLUSH, &newrsettings)) != 0){
        fprintf(stderr, "Could not set attributes\n");
    }else{
        fgets(password, PASSWORD_LEN, stdin);
        tcsetattr(fileno(stdin), TCSANOW, &initialrsettings);
        fprintf(stdout, "\nYou entered :%s", password);
    }
    
    exit(0);
}
