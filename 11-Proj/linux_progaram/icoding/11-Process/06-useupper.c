/*******************************************************************
 *   > File Name: 06-use05-upper.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 11 May 2017 04:00:24 PM CST
 ******************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *filename;

    if(argc != 2){
        fprintf(stderr, "Usage : 06-useupper file\n");exit(1);
    }

    filename = argv[1];
    
    /*open the path of filename and associates the stream pointed to by stream with it . 
     *The original stream is closed.
     *change the file associated with a standard text stream(stderr, stdin, or stdout)
     * */
    if(!freopen(filename, "r", stdin)){
        fprintf(stderr, "Could not redirect stdin from file %s\n", filename);exit(2);
    }
    
    //int execl(const char *path, const char *arg, ....);
    execl("./05-upper", "05-upper", NULL);

    perror("Could not exec  ./05-upper");

    exit(3);
}
