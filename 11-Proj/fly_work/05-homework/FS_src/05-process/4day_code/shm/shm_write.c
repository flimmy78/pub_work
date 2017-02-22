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
     printf("The share memory is prepared OK!\n");
     char buf[BUFSIZ];
     bzero(pMem, SHM_SIZE);
     while(1) {
     	//从标准键盘上获取用户的输入并加上FLAG，然后写入共享内存
	printf("pls input the string:\n");
	bzero(buf, BUFSIZ);
	if( fgets(buf, BUFSIZ -1, stdin) == NULL) {
		continue;
	}

	strncpy(pMem, buf, strlen(buf));
	if( !strncasecmp(pMem, STR_QUIT, strlen(STR_QUIT)) ) { //如果用户输入了忽略大小写的quit，则退出
		break;	
	}
     }	     

     /*4.撤销映射 */
     shmdt((void *)pMem);

     /* 5. 删除共享内存*/
     shmctl(shm_id, IPC_RMID, NULL);	
    
    return 0;
}
