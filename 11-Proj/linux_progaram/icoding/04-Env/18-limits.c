/*******************************************************************
 *   > File Name: 18-limits.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 07 Apr 2017 10:07:24 AM CST
 ******************************************************************/
#if (0)
#include <sys/time.h>
#include <sys/resource.h>

/*获得进程的相关资源信息。如：用户开销时间，系统开销时间，接收的信号量等等;*/
int getrusage(int who, struct rusage *usage);
struct rusage {
    struct timeval ru_utime; /* user CPU time used */
    struct timeval ru_stime; /* system CPU time used */
    long   ru_maxrss;        /* maximum resident set size */
    long   ru_ixrss;         /* integral shared memory size */
    long   ru_idrss;         /* integral unshared data size */
    long   ru_isrss;         /* integral unshared stack size */
    long   ru_minflt;        /* page reclaims (soft page faults) */
    long   ru_majflt;        /* page faults (hard page faults) */
    long   ru_nswap;         /* swaps */
    long   ru_inblock;       /* block input operations */
    long   ru_oublock;       /* block output operations */
    long   ru_msgsnd;        /* IPC messages sent */
    long   ru_msgrcv;        /* IPC messages received */
    long   ru_nsignals;      /* signals received */
    long   ru_nvcsw;         /* voluntary context switches */
    long   ru_nivcsw;        /* involuntary context switches */
};
/*可用来取得进程、进程组和用户的进程执行优先权。*/
int getpriority(int which, int who);
int getrlimit(int resource, struct rlimit *rlim);
struct rlimit {
    rlim_t rlim_cur;  /* Soft limit */
    rlim_t rlim_max;  /* Hard limit (ceiling for rlim_cur) */
};

#endif

#include <stdio.h>
#include <limits.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

void work(){
    FILE *f;
    int i;
    double x = 4.5;

    f = tmpfile();
    /* loop 10 000 */
    for(i = 0; i< 10000; i++){
        fprintf(f,"Do some output\n");
        if(ferror(f)){
            fprintf(stderr, "Error writing to temporary file\n");exit(1);
        }
        /* loop 1000 000 */
        for(i = 0; i < 1000000; i++){
            x = log(x*x + 3.21);
        }
    }
    printf("Loop over!\n");
}

int main(int argc, char* argv[])
{
    /*printf("NAME_MAX = %d\n",NAME_MAX);
      printf("CHAR_BIT = %d\n",CHAR_BIT);
      printf("CHAR_MAX = %d\n",CHAR_MAX);
      printf("INT_MAX = %d\n",INT_MAX);*/

    //int priority;
    //priority = getpriority(PRIO_PROCESS, getpid());
    //printf("%d\n",priority);
    struct rusage r_usage;
    struct rlimit r_limit;
    int priority;

    work();
    getrusage(RUSAGE_SELF, &r_usage);
    printf("CPU usage: User = %ld.%06ld, System = %ld.%06ld\n",\
            r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec,\
            r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);
    
    /*Get the priority of process*/
    priority = getpriority(PRIO_PROCESS, getpid());
    printf("Current priority = %d\n", priority);

    /*Get the file size limits*/
    getrlimit(RLIMIT_FSIZE, &r_limit);
    printf("Current FSIZE limit :soft = %ld, hard = %ld\n",\
            r_limit.rlim_cur, r_limit.rlim_max);
 
    /*Set the file size limits*/   
    r_limit.rlim_cur = 1024;
    r_limit.rlim_max = 2048;
    printf("Setting a 1K file size limit\n");
    if((setrlimit(RLIMIT_FSIZE, &r_limit)) != 0){
        printf("Setrlimit err\n");
    }

    work();

    return 0;
}
