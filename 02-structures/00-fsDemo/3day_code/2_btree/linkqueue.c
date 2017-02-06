#include "linkqueue.h"

void init_linkqueue(link_pqueue *Q)
{
    //申请front和rear的空间
    *Q = (link_pqueue)malloc(sizeof(link_queue));
    if(NULL == *Q){
	perror("malloc");
	exit(1);
    }
    //申请头结点空间，同时将头结点地址给front
    (*Q)->front = (node_pqueue)malloc(sizeof(node_queue));
    if(NULL == (*Q)->front){
	perror("malloc");
	exit(1);
    }
    (*Q)->front->next = NULL;   //给头结点的next指针赋NULL

    (*Q)->rear = (*Q)->front;	//rear也指向头结点
}

bool linkqueue_in(link_pqueue q,datatype data)
{
    node_pqueue new;

    //申请新结点空间
    new = (node_pqueue)malloc(sizeof(node_queue));
    if(NULL == new){
	perror("malloc");
	return false;
    }
    new->data = data;   //将数据存储在新结点中

    //将新结点入对
    new->next = q->rear->next;
    q->rear->next = new;
    q->rear = new;
    return true;
}

bool linkqueue_out(link_pqueue q,datatype* data)
{
    node_pqueue t;
    if(isempty_linkqueue(q)){
	printf("队列已空!");
	return false;
    }

    t = q->front;
    q->front = q->front->next;
    *data = q->front->data;
    free(t);
    return true;
}

bool isempty_linkqueue(link_pqueue q)
{
    if(q->front == q->rear)
	return true;
    else
	return false;
}
#if 0
void show_linkqueue(link_pqueue q)
{
    node_pqueue p;
    for(p = q->front->next; p != NULL; p = p->next)
	printf("%d\t",p->data);
    printf("\n");
}
#endif
