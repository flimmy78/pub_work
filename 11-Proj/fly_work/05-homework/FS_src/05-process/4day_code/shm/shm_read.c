#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define STR_QUIT "quit"
#define SHM_SIZE 2048
int main(void)
{

  /*1.获取共享内存 */
  //第一种方式  key_t key = 0x11223344;
  //第二种方式：
     int shm_id = -1;
     char *pMem = NULL;

    if((shm_id = shmget(ftok(".", 'a'), SHM_SIZE, IPC_CREAT|0666)) < 0) {
    	perror("shmget");
        exit(1);
     }

     /* 2.映射共享内存到用户空间*/
     if((pMem = (char *)shmat(shm_id, NULL, 0)) == (void *)-1) {
	perror("shmat");
    exit(1);
     }

     /* 3. 读写共享内存 */
     printf("The read share memory process is prepared OK!\n");
     while(1) {
	if(pMem[0] != 0) { //如果共享内存第一个字节不为空，则读出来 	     
     	  //从共享内存读出数据
	   printf("Reader: %s\n", pMem);
	
	  if( !strncasecmp(pMem, STR_QUIT, strlen(STR_QUIT)) ) { //如果用户输入了忽略大小写的quit，则退出
		break;	
	}
	bzero(pMem, SHM_SIZE);  
	}
       // sleep(1);
     }	     

     /*4.撤销映射 */
     shmdt((void *)pMem);

     /* 5. 删除共享内存*/
     //...可能存在BUG，FIXME!!!!!     
    // shmctl(shm_id, IPC_RMID, NULL);	
    
    return 0;
}
