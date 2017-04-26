/*******************************************************************
 *   > File Name: 06-useupper.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 26 Apr 2017 05:52:17 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *filename;

    if(argc != 2){
        fprintf(stderr, "Usage : useupper file\n");exit(1);
    }
    
    filename = argv[1];
    if(!freopen(filename, "r", stdin)){
        fprintf(stderr, "Could not redirect stdin from file %s\n", filename);exit(2);
    }

    execl("./05-upper", "upper", (char*)0);
    
    perror("could not exec ./upper");
    exit(3);
}
