/*******************************************************************
 *   > File Name: 09-lock2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 25 Apr 2017 09:44:05 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

const char *lock_file = "/tmp/LCK.test2";

int main(int argc, char* argv[])
{
    int file_desc;
    int tries = 10;

    while(tries --){
        /* open the file  */
        file_desc = open(lock_file, O_RDWR | O_CREAT | O_EXCL, 0444);
        if(file_desc == -1){
            printf("%d -- Lock already present\n", getpid());
            sleep(3);
        }else{
            /*临界区*/
            printf("%d -- I have exclusive access\n", getpid());
            sleep(1);
            (void)close(file_desc);     //close the file
            (void)unlink(lock_file);    //unlink the file
            
            /*结束*/
            sleep(2);
        }
    }

    return 0;
}
