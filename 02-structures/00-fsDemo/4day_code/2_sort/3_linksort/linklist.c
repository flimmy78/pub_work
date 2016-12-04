#include "linklist.h"

void init_linklist(list_pnode *H)
{
    *H = (list_pnode)malloc(sizeof(list_node));
    if(NULL == *H){
	perror("malloc");
	exit(1);
    }
    (*H)->next = NULL;
}

void insert_linklist(list_pnode p,list_pnode new)
{
    new->next = p->next;
    p->next = new;
}

void del_linklist(list_pnode p)
{
    list_pnode q;

    if(p->next != NULL){
	q = p->next;
	p->next = q->next;
	free(q);
    }
}

void create_linklist(list_pnode h)
{
    int n,i;
    list_pnode new,p;

    printf("请输入创建链表的结点个数:");
    scanf("%d",&n);
    for(i = 0,p = h; i < n; i++){
	new = (list_pnode)malloc(sizeof(list_node));
	if(NULL == new){
	    perror("malloc");
	    exit(1);
	}
	scanf("%d",&new->data);
	//将new指向的新结点查入到表尾p
	insert_linklist(p,new);
	p = p->next;
	show_linklist(h);
    }
}
void show_linklist(list_pnode h)
{
    list_pnode p;

    for(p = h->next; p != NULL; p = p->next)
	printf("%d\t",p->data);
    printf("\n");
}
