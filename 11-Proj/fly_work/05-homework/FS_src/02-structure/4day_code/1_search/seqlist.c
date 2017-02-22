#include "seqlist.h"

#if 0
seq_plist init_seqlist(void)
{
    seq_plist l;
    //1.申请顺序表空间
    l = (seq_plist)malloc(sizeof(seq_list));
    if(NULL == l){
	perror("malloc");   //打印出函数调用出错的信息
	exit(1);
    }
    //2.对顺序表初始化
    l->last = -1;
    return l;
}
#else
void init_seqlist(seq_plist *L)
{
    //1.申请顺序表空间
    *L = (seq_plist)malloc(sizeof(seq_list));
    if(NULL == *L){
	perror("malloc");   //打印出函数调用出错的信息
	exit(1);
    }
    //2.对顺序表初始化
    (*L)->last = -1;
}
#endif

bool insert_seqlist(seq_plist l,datatype data)
{
    int i,j;

    if(isfull_seqlist(l)){
	printf("顺序表已满!\n");
	return false;
    }
    //1.确定插入data的位置
	for(i = 0; i <= l->last; i++)
	    if(data.sno < l->data[i].sno)
		break;
    //2.移动数据
	for(j = l->last; j >= i; j--)
	    l->data[j+1].sno = l->data[j].sno;
    //3。插入
	l->data[i] = data;
    //4.last加1
	l->last++;
	return true;
}

bool del_seqlist(seq_plist l,datatype data)
{
    int i,j;

    if(isempty_seqlist(l)){
	printf("顺序表已空!\n");
	return false;
    }
    //1.判断是否存在，如果存在确定data的位置
    for(i = 0; i <= l->last; i++)
	if(data.sno == l->data[i].sno)
	    break;
    if(i > l->last){    //data不存在
	printf("学号为%d的记录不存在!\n",data.sno);
	return false;
    }
    //2.移动数据
    for(j = i; j < l->last; j++)
	l->data[j] = l->data[j+1];
    //4.last减1
	l->last--;
	return true;
}

bool isfull_seqlist(seq_plist l)
{
    if(l->last == SIZE-1)
	return true;
    else
	return false;
}
bool isempty_seqlist(seq_plist l)
{
    if(l->last == -1)
	return true;
    else
	return false;
}

void show_seqlist(seq_plist l)
{
    int i;
    for(i = 0; i <= l->last; i++)
	printf("%d\t%s\t%f\n",l->data[i].sno,l->data[i].name,l->data[i].score);
}

void create_seqlist(seq_plist l)
{
    int n,i;
    datatype new;
    printf("请输入记录个数:");
    scanf("%d",&n);
    for(i = 0; i < n; i++){
	scanf("%d%s%f",&new.sno,new.name,&new.score);
	insert_seqlist(l,new);
    }
}
