#include "doublelist.h"

void init_doublelist(double_pnode *H)
{
    *H = (double_pnode)malloc(sizeof(double_node));
    if(NULL == *H){
	perror("malloc");
	exit(1);
    }
    //让头结点的前后指针指向自己
    INIT_LIST_HEAD(&(*H)->list);
}

void show_doublelist(double_pnode h)
{
    double_pnode p;
    list_for_each_entry(p,&h->list,list)
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
	list_add_tail(&new->list,&h->list);
	show_doublelist(h);
    }
}

void sort_doublelist(double_pnode h)
{
    double_pnode p,q;

    for(p = list_entry(h->list.prev,double_node,list); p != h; p = list_entry(p->list.prev,double_node,list)){
	if(p->data % 2 == 0){  //偶数，将其移动到表尾
	    q = p;
	    p = list_entry(p->list.prev,double_node,list);

	    //将q指向的结点插入到表尾
	    list_move_tail(&q->list,&h->list);
	    show_doublelist(h);
	}
    }
}
