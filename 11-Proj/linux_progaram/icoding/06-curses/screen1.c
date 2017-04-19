/*******************************************************************
 *   > File Name: screen1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 19 Apr 2017 02:54:25 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

int main(int argc, char* argv[])
{
    initscr();

    
    int i = 0;
    move(15, 15);
    printw("%s", "Hello world");
    refresh();
    for(i = 0; i < 10; i++){
        flash();
        sleep(1);
    }


    endwin();
    exit(EXIT_SUCCESS);

    return 0;
}
