/*******************************************************************
 *   > File Name: 98-hang.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Mar 2017 03:00:29 PM CST
 ******************************************************************/

#include <stdio.h>

inline void hang(void);

int main(int argc, char* argv[])
{
    hang();
    return 0;
}

inline void hang(void){
    puts("### ERROR ### Please RESET the board ###\n");
    for (;;)
        ;
}
