/*******************************************************************
 *   > File Name: 08-borrowBooks.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Jan 20 17:31:36 2018
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a,b,c ,count = 0;

    printf("There are different methods for XM to distribute books to 3 readers :\n");

    for(a=1; a<=5; a++){
        for(b=1; b<=5; b++){
            for(c = 1; a!=b && c<=5; c++){
                if(c != a && c!=b){
                    printf(count%8? "%2d:%d,%d,%d" : "%2d:%d,%d,%d\n", (++count), a,b,c);
                }
            }
        }
    }

    return 0;
}
