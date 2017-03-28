/*******************************************************************
 *   > File Name: 20-gettablesize.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 28 Mar 2017 04:18:40 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int i;
    
    for(i = 0; i < getdtablesize(); i++){
        printf("i = %d\n",i);
    }

    return 0;
}
