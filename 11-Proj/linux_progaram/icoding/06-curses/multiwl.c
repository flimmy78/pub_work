/*******************************************************************
 *   > File Name: multiwl.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 19 Apr 2017 04:05:51 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{   
    WINDOW *new_window_ptr;
    WINDOW *popup_window_ptr;

    int x_loop;
    int y_loop;
    char a_letter = 'a';

    initscr();
    
    move(5, 5);
    printw("%s" , "Testing multiple windows");
    refresh();

    for( y_loop = 0; y_loop < LINES - 1; y_loop ++){
        for(x_loop = 0; x_loop < COLS - 1; x_loop ++){
            mvwaddch(stdscr, y_loop, x_loop, a_letter);
            a_letter ++;
            if(a_letter > 'z')
                a_letter = 'a';
        }
    }

    refresh();
    sleep(2);

    new_window_ptr = newwin(10 ,20 ,5 ,5);

    return 0;
}
