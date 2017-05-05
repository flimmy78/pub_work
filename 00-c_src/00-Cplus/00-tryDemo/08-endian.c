/*******************************************************************
 *   > File Name: 08-endian.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 02 Jan 2017 05:35:59 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool isLittleEndian();
int isLEndian();

int main(void)
{
#if 0
    union{
        char c;
        int i;
    }u;

    u.i = 0x0201;

    if(u.c == 1)
        printf("little-endian\n");
    else if(u.c == 2)
        printf("big-endian \n");
    else
        printf("unknown");
#else
    if(isLittleEndian()){
        printf("little_endian\n");
    }   

#endif

    return 0;
}


bool isLittleEndian(void){
    union{
        char c;
        int i;
    }u;
    u.i = 0x0201;

    if(u.c == 1)
        return true;    /*little_endian*/
    else
        return false;   /*big_endian*/
}

int isLEndian(void){
    union{
        char c;
        int i;
    }u;
    u.i = 0x0201;

    if(u.c == 1)
        return true;    /*little-endian*/
    else if(u.c == 2)
        return false;   /*big-endian*/
    else
        return (-1);    /*unknown error*/
}
