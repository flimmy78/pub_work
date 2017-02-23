#include "hash.h"
void init_hash(hash_tp *H,int m)
{
    int i;
    *H = (hash_tp)malloc(sizeof(hash_table));
    if(NULL == *H){
	perror("malloc");
	exit(1);
    }
    (*H)->length = m;
    (*H)->hp = (datatype*)malloc((*H)->length*sizeof(datatype));
    if(NULL == (*H)->hp){
	perror("malloc");
	exit(1);
    }
    for(i = 0; i < (*H)->length; i++)
	(*H)->hp[i] = -1;

}

int fun(int m)
{
    int i,j;

    for(i = m; i > 1; i--){
	for(j = 2; j < i; j++)
	    if(i % j == 0)
		break;
	if(j == i)
	    break;
    }
    return i;
}

hash_tp hash(int a[])
{
    hash_tp h;
    int hash_val;
    int m,i;
    //1.确定hash表的空间大小
    m = (int)ceil(N/0.75);
    //2.申请hash表空间
    init_hash(&h,m);
    //3.确定不大与hash表长的最大质数p
    p = fun(m);
    for(i = 0 ; i < N; i++){
	//4.选取hash函数,建立hash表
	hash_val = a[i] % p; 
	//5.产生冲突时，线性探查法处理冲突
	while(h->hp[hash_val] != -1)
	    hash_val = (hash_val + 1) % h->length;
	h->hp[hash_val] = a[i];
	show(h,hash_val);
	sleep(1);
    }
    return h;
}
void show(hash_tp h,int hash_val)
{
    int i;
    for(i = 0; i < h->length; i++){
	if(i == hash_val)
	    printf("hp[%02d]:<-----%d\n",i,h->hp[i]);
	else
	    printf("hp[%02d]:%d\n",i,h->hp[i]);
    }
    printf("****************************\n");
}
