/*******************************************************************
 *   > File Name: 02-execlp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 11 May 2017 01:46:34 PM CST
 ******************************************************************/
#if (0)
#include <unistd.h>

extern char **environ;

int execl(const char *path, const char *arg, ...);
int execlp(const char *file, const char *arg, ...);
int execle(const char *path, const char *arg,
        ..., char * const envp[]);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[],
        char *const envp[]);

char *const ps_argv[] = {"ps", "ax", 0};
char *const ps_wnvp[] = {"PATH=/bin/:/usr/bin", "TERM=console", 0};

execl("/bin/ps", "ps", "ax", 0);
execlp("ps", "ps", "ax", 0);
execle("/bin/ps", "ps", "ax", 0, ps_envp);

execv("/bin/ps", ps_argv);
execvp("ps", ps_argv);
execve("/bin/ps", ps_argv, ps_envp);

#endif

#include <stdio.h>
#include <unistd.h>
//#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("Runing ps with execlp\n");
    //execlp("ps", "ps", "ax", 0);
    execlp("ps", "ps", "ax", NULL);
    printf("Done.\n");

    return 0;
}
