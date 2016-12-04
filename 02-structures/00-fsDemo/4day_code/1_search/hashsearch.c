#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

#define N 11
typedef int datatype;
typedef struct hashtable{
    datatype *hp;   //指向hash表空间的指针
    int length;	    //hash表的空间长度
}hash_table,*hash_tp;
int p;

void init_hash(hash_tp *H,int m);
int show(hash_tp h);
hash_tp hash(int a[]);
int hashsearch(hash_tp h,int key);
int main(void)
{
    int key,ret;
    int a[N] = {23,34,14,38,46,16,68,15,7,31,26};
    char ch;
    hash_tp h;
    //建立hash表
    h = hash(a);
#if 1
    while(1){
	printf("请输入要查找的记录的关键字:");
	scanf("%d",&key);
	ret = hashsearch(h,key);
	if(ret != -1){   //查找成功
	    printf("查找成功，要查找的记录的下标为%d\n",ret);
	}else{	//查找失败
	    printf("查找失败，关键字为%d的记录不存在!\n",key);
	}
	printf("是否继续查找(Y/y)？");
	while(getchar() != '\n');   //清空缓冲区
	scanf("%c",&ch);
	if(ch != 'Y' && ch != 'y')
	    break;
    }	
#endif
    return 0;
}
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
	//3.选取hash函数,建立hash表
	hash_val = a[i] % p; 
	//4.产生冲突时，线性探查法处理冲突
	while(h->hp[hash_val] != -1)
	    hash_val = (hash_val + 1) % h->length;
	h->hp[hash_val] = a[i];
	show(h);
	sleep(1);
    }
    return h;
}
int hashsearch(hash_tp h,int key)
{
    int hash_val;
    int flag = 0;

    hash_val = key % p;   //hash函数计算出记录地址;

    while(h->hp[hash_val] != key){   //当有冲突时，该while语句才会执行
	    hash_val = (hash_val + 1) % h->length;
	    flag++;
	    if(flag > h->length)
		return -1;
    }
    return hash_val;
}
int show(hash_tp h)
{
    int i;
    for(i = 0; i < h->length; i++)
	printf("hp[%02d]:%d\n",i,h->hp[i]);
    printf("****************************\n");
}
