#include "hash.h"

int main(void)
{
    int key;
    struct node *ret;
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
	if(ret != NULL){   //查找成功
	    printf("查找成功:%d\n",ret->data);
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

struct node *hashsearch(hash_tp h,int key)
{
    int hash_val;
    struct node *t;

    hash_val = key % p;   //hash函数计算出记录地址;
    for(t = h->hp[hash_val];t != NULL;t =t->next)
	if(t->data == key)
	    return t;
    return NULL;
}
