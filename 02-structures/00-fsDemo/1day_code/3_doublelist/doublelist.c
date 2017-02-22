#include "doublelist.h"

void init_doublelist(double_pnode *H)
{
    *H = (double_pnode)malloc(sizeof(double_node));
    if(NULL == *H){
	perror("malloc");
	exit(1);
    }
    //让头结点的前后指针指向自己
    (*H)->prev = (*H)->next = *H;
}

void insert_doublelist_next(double_pnode p,double_pnode new)
{
    new->next = p->next;
    p->next->prev = new;
    new->prev = p;
    p->next = new;
}
void insert_doublelist_prev(double_pnode p,double_pnode new)
{
    new->prev = p->prev;
    p->prev->next = new;
    new->next = p;
    p->prev = new;
}

void del_doublelist_next(double_pnode p)
{
    double_pnode q;

    q = p->next;
    p->next = q->next;
    q->next->prev = p;
    free(q);
}
void del_doublelist_prev(double_pnode p)
{
    double_pnode q;

    q = p->prev;
    p->prev = q->prev;
    q->prev->next = p;
    free(q);
}
void del_doublelist_cur(double_pnode p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;
    //free(p);
}

void show_doublelist(double_pnode h)
{
    double_pnode p;
    for(p = h->next; p != h; p = p->next)
	printf("%d\t",p->data);
    printf("\n");
}

void create_doublelist(double_pnode h)
{
    int n,i;
    double_pnode new;

    printf("请输入双向链表数据个数:");
    scanf("%d",&n);
    for(i = 0; i < n ;i++){
	new = (double_pnode)malloc(sizeof(double_node));
	if(NULL == new){
	    perror("malloc");
	    exit(1);
	}
	scanf("%d",&new->data);

	//将new指向的结点插入表尾
	insert_doublelist_prev(h,new);
	show_doublelist(h);
    }
}

void sort_doublelist(double_pnode h)
{
    double_pnode p,q;

    for(p = h->prev; p != h; p = p->prev){
	if(p->data % 2 == 0){  //偶数，将其移动到表尾
	    q = p;
	    p = p->prev;
	    
	    del_doublelist_cur(q);
	    insert_doublelist_prev(h,q);
	    show_doublelist(h);
	}
    }
}
