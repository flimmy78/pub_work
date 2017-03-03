/*******************************************************************
 *   > File Name: 08-getenv.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 03 Mar 2017 10:21:27 AM CST
 ******************************************************************/
#if (0)
char *getenv(const char *name);
#endif

#include <stdio.h>
/*inc for getenv*/
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *type;
    char *name;

    if(argc < 2){
        printf("More usage: %s <envname>\t",argv[0]);
        name = "PATH";puts("Default envname for get: PATH\n");
    }else{
        name = argv[1];
    }

    if((type = getenv(name)) != NULL){
        printf("%s :%s\n",name,type);
    }else{
        printf("No such environment\n");
    }

    return 0;
}
