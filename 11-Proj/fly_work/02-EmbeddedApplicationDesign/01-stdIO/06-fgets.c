/*******************************************************************
 *   > File Name: 06-fgets.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 14 Jan 2017 11:43:06 AM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

int file_line_count(const char* path);

int main(int argc, char *argv[])
{
#if 0
    int line = 0;
    char buf[128];
    FILE* fp;

    if(argc < 2)
    {
        printf("Usage : %s <file> \n",argv[0]);
        return (-1);
    }
    if((fp = fopen(argv[1], "r")) == NULL)
    {
        perror("Fail to open\n");
        return (-1);
    }
    while(fgets(buf,128,fp) != NULL)
    {
        if(buf[strlen(buf) - 1] == '\n')
            line++;
    }
    printf("The line of %s is %d\n",argv[1],line);
#endif
    int ret;
    if(argc < 2)
    {
        printf("Usage : %s <filename>\n",argv[0]);
        return (-1);
    }

    ret = file_line_count(argv[1]);
    printf("Line = %d\n",ret);

    return 0;
}

int file_line_count(const char *path)
{
    int line = 0;
    char buf[128];
    FILE* fp;

    if(path == NULL)
    {
        printf("%s\n",strerror(6));
        return (-1);
    }

    if((fp = fopen(path,"r")) == NULL)
    {
        perror("Fail to fopen");
        return (-1);
    }

    while(fgets(buf,128,fp) != NULL)
    {
        if(buf[strlen(buf) - 1] == '\n')
            line++;
    }
    return line;
}
