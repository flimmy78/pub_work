#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define STR_QUIT "quit"
#define SHM_SIZE 2048

#undef BUFSIZ
#define BUFSIZ SHM_SIZE

#include "sem_com.h"
#define SHM_PROJ_ID 'a'
#define SEMW_PROJ_ID 'w'
#define SEMR_PROJ_ID 'r'
int main(void)
{

  /*1.获取共享内存和信号量 */
    int shm_id = -1, sem_w = -1, sem_r= -1;
    char *pMem = NULL;

     shm_id = shmget(ftok(".", SHM_PROJ_ID), SHM_SIZE, IPC_CREAT|0666); /* 创建共享内存*/
     sem_w = semget (ftok (".", SEMW_PROJ_ID), 1, 0666 | IPC_CREAT);    
     sem_r = semget (ftok (".", SEMR_PROJ_ID), 1, 0666 | IPC_CREAT);  
   
     if(shm_id < 0 || sem_w < 0|| sem_r < 0) {
        if(shm_id < 0) perror("shmget");
        if(sem_w < 0 || sem_r < 0 ) perror("semget");
        exit(1);
     }  
     /* 调用init_sem,把信号量sem_w 初始化成1（表示起始时共享内存可写）， 
         sem_r 初始化成0(表示起始时共享内存不可读) */
     init_sem(sem_w, 1);
     init_sem(sem_r, 0);

     /* 2.映射共享内存到用户空间*/
     if((pMem = (char *)shmat(shm_id, NULL, 0)) == (void *)-1) {
	perror("shmat");
        exit(1);
     }

     /* 3. 写共享内存 */
     printf("The share memory is prepared OK!\n");
     char buf[BUFSIZ];
     bzero(pMem, SHM_SIZE);
     while(1) {
     	//从标准键盘上获取用户的输入，然后写入共享内存
	printf("pls input the string:\n");
	bzero(buf, BUFSIZ);
	if( fgets(buf, BUFSIZ -1, stdin) == NULL) {
		continue;
	}
        sem_p(sem_w, 0, 1);  //P sem_w操作
        //...操作资源
	strncpy(pMem, buf, strlen(buf));
	if( !strncasecmp(pMem, STR_QUIT, strlen(STR_QUIT)) ) { //如果用户输入了忽略大小写的quit，则退出
		sem_v(sem_r, 0, 1);  //V sem_r操作
		break;	
	}
        sem_v(sem_r, 0, 1);  //Vsem_r操作
     }	     

     /*4.撤销映射 */
     shmdt((void *)pMem);

     /* 5. 删除共享内存*/
     //shmctl(shm_id, IPC_RMID, NULL);	
    
    return 0;
}
