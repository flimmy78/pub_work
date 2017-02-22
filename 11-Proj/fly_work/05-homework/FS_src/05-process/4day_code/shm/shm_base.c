#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{

  /*1.获取共享内存 */
  //第一种方式  key_t key = 0x11223344;
  //第二种方式：
     int shm_id = -1;
     char *pMem = NULL;
     
     printf("Before shmget()\n");
     system("ipcs -m");

     if((shm_id = shmget(ftok(".", 'a'), 2048, IPC_CREAT|0666)) < 0) {
    perror("shmget");
    exit(1);
     }

     printf("After shmget()\n");
     system("ipcs -m");

     /* 2.映射共享内存到用户空间*/
     if((pMem = (char *)shmat(shm_id, NULL, 0)) == (void *)-1) {
	perror("shmat");
    exit(1);
     }
     printf("after shmat()\n");
     system("ipcs -m");

     /* 3. 读写共享内存 */
     //...
     printf("The share memory is prepared OK!\n");
     
     /*4.撤销映射 */
     shmdt((void *)pMem);
     
     printf("after shmdt()\n");
     system("ipcs -m");


     /* 5. 删除共享内存*/
     shmctl(shm_id, IPC_RMID, NULL);	

     printf("after shmctl() delete the shm\n");
     system("ipcs -m");     
    
    return 0;
}
