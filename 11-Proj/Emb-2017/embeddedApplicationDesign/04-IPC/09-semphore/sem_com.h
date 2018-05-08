#ifndef __SEM_COM_H__
#define __SEM_COM_H__

int init_sem(int sem_id, int init_value);
int del_sem(int sem_id);
int sem_p(int sem_id);
int sem_v(int sem_id);

#endif
