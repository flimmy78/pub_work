/*******************************************************************
 *   > File Name: 03-popen.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Apr 2017 02:57:41 PM CST
 ******************************************************************/
#if (0)
FILE *popen(const char *command, const char *type);
#endif

#include <stdio.h>

#if (0)
#define COMMOND "cat /etc/passwd"
#else
#define COMMOND "ls -al"
#endif

int main(int argc, char* argv[])
{
    FILE *fp;
    char buffer[80];

    fp = popen(COMMOND, "r");
    fgets(buffer, sizeof(buffer), fp);
    printf("%s", buffer);
    pclose(fp);

    return 0;
}
