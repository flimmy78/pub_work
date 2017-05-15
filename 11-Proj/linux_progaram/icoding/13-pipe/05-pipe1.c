/*******************************************************************
 *   > File Name: 05-pipe1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 15 May 2017 02:11:43 PM CST
 ******************************************************************/
#if (0)
int pipe(int pipefd[2]);
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "123";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    memset(buffer, '\0', sizeof(buffer));
    
    /*create pipe*/
    if(pipe(file_pipes) == 0){
        fork_result = fork();   /*fork new process*/
        if(fork_result == -1){
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }
    }

    if(fork_result == 0){   
        /*the process of child*/
        data_processed = read(file_pipes[0], buffer, BUFSIZ);
        printf("Read %d bytes :%s\n", data_processed, buffer);
        exit(EXIT_SUCCESS);
    }else{                  
        /*the process of parent*/
        data_processed = write(file_pipes[1], some_data, strlen(some_data));
        printf("Wrote %d bytes\n", data_processed);
    }
    
    exit(EXIT_SUCCESS);
}
