/*******************************************************************
 *   > File Name: 08-lock2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 09 May 2017 10:11:32 AM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

const char *lock_file = "/tmp/LCK.test2";

int main(int argc, char* argv[])
{
    int file_desc;
    int tries = 10;

    while(tries --){
        file_desc = open(lock_file, O_RDWR|O_CREAT|O_EXCL, 0444);
        if(file_desc == -1){/*error*/
            printf("%d - Lock already present\n", getpid());
            sleep(3);
        }else{/*open ok*/
            printf("%d - I have exclusive access\n", getpid());
            sleep(1);
            (void)close(file_desc);
            (void)unlink(lock_file);
            sleep(2);
        }
    }

    exit(EXIT_SUCCESS);
}
