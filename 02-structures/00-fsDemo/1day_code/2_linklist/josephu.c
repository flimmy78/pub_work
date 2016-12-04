/*
 3、用单向循环链表实现“数n出局”游戏（Josephu问题）。首先建立一个包含若干整数的单向循环链表，然后从第一个节点开始数，把数到3的那个节点删除，接着下一个节点开始数，数到3继续删除，以此类推，打印出最后剩余的那个节点。
 */

#include "linklist.h"

void init_josephu(list_pnode *H);
extern void create_josephu(list_pnode h);
extern void show_josephu(list_pnode h);
void josephu(list_pnode h,int n);
int main(void)
{
    list_pnode h;
    
    init_josephu(&h);
    create_josephu(h);
    josephu(h,4);
    return 0;
}

void init_josephu(list_pnode *H)
{
    *H = (list_pnode)malloc(sizeof(list_pnode));
    if(NULL == *H){
	perror("malloc");
	exit(1);
    }
    (*H)->next = *H;
}

void create_josephu(list_pnode h)
{
    int i,n;
    list_pnode new,p = h;

    printf("请输入科学家人数:");
    scanf("%d",&n);
    for(i = 0; i < n; i++){
	if(i == 0)
	    scanf("%d",&p->data);
	else{
	    new = (list_pnode)malloc(sizeof(list_pnode));
	    if(NULL == new){
		perror("malloc");
		exit(1);
	    }
	    scanf("%d",&new->data);
	    insert_linklist(p,new);
	    p = p->next;
	}
	show_josephu(h);
    }
}

void show_josephu(list_pnode h)
{
    list_pnode  p;

    for(p = h; p->next != h; p = p->next)
	printf("%d\t",p->data);
    printf("%d\n",p->data);
}

void josephu(list_pnode h,int n)
{
    int i;
    list_pnode p = h,q;
    while(p != p->next){
	//寻找要删除的结点的前一个结点的指针
	for(i = 0; i < n-2; i++)
	    p = p->next;
	q = p->next;
	p->next = q->next;

	p = q->next;
	printf("%d\t",q->data);
	free(q);
    }
    printf("\n最后剩余的结点为:%d\n",p->data);
}

