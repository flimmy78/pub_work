/*******************************************************************
 *   > File Name: 04-getenv.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Mar 2017 04:36:19 PM CST
 ******************************************************************/
#if (0)
char *getenv(const char *name);
#endif

#include <stdio.h>
//#include <string.h>

int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 2){
        printf("\n\t\tUsage : %s <envname>\n\n", argv[0]);return (-1);
    }

    //char buf[128];
   // memset(buf, 0, 128);
    char *buf;

    if((buf = (char*)getenv(argv[1])) == NULL){
        printf("getenv %s err\n",argv[1]);return (-1);
    }else{
        printf("%s = %s\n",argv[1],buf);
    }

    return 0;
}
