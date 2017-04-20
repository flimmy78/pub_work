/*******************************************************************
 *   > File Name: color.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 09:55:37 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

int main(int argc, char* argv[])
{
    int i;

    initscr();

    if(! has_colors()){
        endwin();
        fprintf(stderr, "Error- no color support on this terminal\n");
        exit(1);
    }

    if(start_color()!= OK){
        endwin();
        fprintf(stderr, "Error - could not initialize colors\n");
        exit(2);
    }

    clear();
    mvprintw(5, 5, "There are %d COLORS, and %d COLOR_PAIRS available", COLORS, COLOR_PAIRS);
    refresh();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_GREEN);
    init_pair(3, COLOR_GREEN, COLOR_RED);
    init_pair(4, COLOR_YELLOW, COLOR_BLUE);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    init_pair(6, COLOR_MAGENTA, COLOR_BLUE);
    init_pair(7, COLOR_CYAN, COLOR_WHITE);

    for( i = 1; i <= 7; i++){
        attroff(A_BOLD);
        attrset(COLOR_PAIR(i));
        mvprintw(5 + i, 5, "Color pair %d", i);
        attrset(COLOR_PAIR(i) | A_BOLD);
        mvprintw(5 + i, 25, "Bold color pair %d", i);
        refresh();
        sleep(1);
    }
    
    beep();
    for(;;);
    endwin();
    return 0;
}
