#include "sem_com.h"

/** 
  * function: init_sem
  * params: 
        semid: the semphore identification
        init_value: the semphore initilization value.
  * return:
        returns -1 with errno indicating the error.
        Otherwise the system call returns a nonnegative value depending on cmd  
        
*/

int init_sem(int semid, int init_value)
{
    union semun semun;
    semun.val = init_value; 
    return semctl(semid, 0, SETVAL, semun);
}

/** 
  * function: del_sem
  * params: 
        semid: the semphore identification
  * return: null
*/
int del_sem(int semid)
{
    union semun semun;
    return semctl(semid, 0, IPC_RMID,semun); 
}

/**
    *func: sem_p
    funcation: execute the P operation to the semphore semid
    *params:
        semid: the semphore identification
	sem_num: the no. of semphore
	nsops: the operating number of semphore  
    *return:  If successful  return 0; otherwise they return -1 with errno indicating the error.
  */
int sem_p(int semid, short sem_num, unsigned nsops)
{
    struct sembuf semb;
      semb.sem_num = sem_num;
      semb.sem_op = -1;
      semb.sem_flg = SEM_UNDO; 
    return semop(semid, &semb, nsops); 
}

/**
    *func: sem_try_p
    funcation: execute the P operation to the semphore semid
    *params:
        semid: the semphore identification
        sem_num: the no. of semphore
        nsops: the operating number of semphore  
    *return:  If successful  return 0; otherwise they return -1 with errno indicating the error.
  */
int sem_try_p(int semid, short sem_num, unsigned nsops)
{
    struct sembuf semb;
      semb.sem_num = sem_num;
      semb.sem_op = -1;
      semb.sem_flg = IPC_NOWAIT|SEM_UNDO;
    return semop(semid, &semb, nsops);
}

/**
    *func: sem_v
    funcation: execute the V operation to the semphore semid
    *params:
        semid: the semphore identification
        sem_num: the no. of semphore
        nsops: the operating number of semphore  
    *return:  If successful  return 0; otherwise they return -1 with errno indicating the error.
  */
int sem_v(int semid, short sem_num, unsigned nsops)
{
    struct sembuf semb;
      semb.sem_num = sem_num;
      semb.sem_op = 1;
      semb.sem_flg = SEM_UNDO;
    return semop(semid, &semb, nsops);
}


