#include "linklist.h"


void linksort(list_pnode);
int main(void)
{
    list_pnode h;
    init_linklist(&h);
    create_linklist(h);
    show_linklist(h);
    linksort(h);
    return 0;
}

void linksort(list_pnode h)
{
    list_pnode p,q,t1,t2;

    p = h->next;
    h->next = NULL;
    while(p!=NULL){
	q = p;
	p = p->next;
	//将q指向的结点插入到h指向的链表中
	for(t1 = h,t2=h->next;t2 != NULL && q->data > t2->data;){
	    t1 = t2;
	    t2 = t2->next;
	}
	t1->next = q;
	q->next = t2;
	show_linklist(h);
    }
}
