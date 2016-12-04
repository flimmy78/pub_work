#include "hash.h"

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
