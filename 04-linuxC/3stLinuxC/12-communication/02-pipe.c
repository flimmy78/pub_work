/*******************************************************************
 *   > File Name: 02-pipe.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Apr 2017 02:42:29 PM CST
 ******************************************************************/
#if (0)
int pipe(int pipefd[2]);
//@FUNC:create a pipe , no name;
#endif

#include <stdio.h>
/*INC for pipe*/
#include <unistd.h>

int main(int argc, char* argv[])
{
    int filedes[2];
    char buffer[80];

    pipe(filedes);

    if(fork() > 0){
        char s[] = "Hello!\n";
        write(filedes[1], s, sizeof(s));/*write to pipe*/
    }else{
        read(filedes[0], buffer, 80);   /*read from pipe*/
        printf("%s",buffer);
    }

    return 0;
}
