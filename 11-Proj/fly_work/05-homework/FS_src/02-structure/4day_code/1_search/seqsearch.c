#include "seqlist.h"

int seqsearch(seq_plist l,int key);
int main(void)
{
    seq_plist l;
    int key,ret;
    char ch;

    init_seqlist(&l);
    create_seqlist(l);
    show_seqlist(l);
    while(1){
	printf("请输入要查找的记录的关键字:");
	scanf("%d",&key);
	ret = seqsearch(l,key);
	if(ret != -1){   //查找成功
	    printf("查找成功，要查找的记录的下标为%d\n",ret);
	    printf("%d\t%s\t%f\n",l->data[ret].sno,l->data[ret].name,l->data[ret].score);
	}else{	//查找失败
	    printf("查找失败，关键字为%d的记录不存在!\n",key);
	}
	printf("是否继续查找(Y/y)？");
	while(getchar() != '\n');   //清空缓冲区
	scanf("%c",&ch);
	if(ch != 'Y' && ch != 'y')
	    break;
    }	
    return 0;
}

int seqsearch(seq_plist l,int key)
{
    int i;

    for(i = l->last; i >= 0; i--)
	if(key == l->data[i].sno)
	    return i;
    return -1;
}
