/*******************************************************************
 *   > File Name: rand.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 23 Apr 2017 04:48:05 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int j, r, nloops;
    unsigned int seed;

    if(argc != 3){
        fprintf(stderr, "Usage :%s <seed> <nloops>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    seed = atoi(argv[1]);
    nloops = atoi(argv[2]);

    srand(seed);
    for(j = 0; j < nloops; j++){
        r = rand();
        printf("%d\n", r);
    }
    
    exit(EXIT_SUCCESS);
}
