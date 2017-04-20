/*******************************************************************
 *   > File Name: ipmode.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 10:56:38 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#define PW_LEN 256  
#define NAME_LEN    256

int main(int argc, char* argv[])
{
    char name[NAME_LEN];
    char password[PW_LEN];
    const char *real_password = "feige";
    int i = 0;

    initscr();

    move(5, 10);
    printw("%s", "Please login :");
    
    move(7, 10);
    printw("%s", "User name:");
    getstr(name);

    move(8, 10);
    printw("%s", "Password :");
    refresh();

    /*----输入密码，不回显，检查----*/
    cbreak();
    noecho();

    memset(password, '\0', sizeof(password));
    while(i < PW_LEN){
        password[i] = getch();
        if(password[i] == '\n')
            break;
        move(8, 20 + i);
        addch('*');
        refresh();
        i++;
    }

    /*启用键盘回显，给出验证结果*/
    echo();
    nocbreak();

    move(11, 10);
    if(strncmp(real_password, password, strlen(real_password)) == 0)
        printw("%s", "Correct");
    else
        printw("%s", "Wrong");
    printw("%s", "password");
    refresh();

    for(;;);
    endwin();
    return 0;
}
