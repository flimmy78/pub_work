/*******************************************************************
 *   > File Name: 01-tmpfile.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 07 Apr 2017 01:27:00 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    while(1){
        FILE* tempfp;
        tempfp = tmpfile();

        if(tempfp)
            printf("Temporary file created\n");
        else{
            printf("Unable to create temporary file\n");
            sleep(10);
            exit(1);
        }
    }

    return 0;
}
