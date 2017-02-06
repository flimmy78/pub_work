#ifndef  __SEQQUEUE_h__
#define  __SEQQUEUE_h__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"

typedef  btree_pnode datatype;
typedef struct nodequeue{	    
    datatype data;  //存储队列数据的结点
    struct nodequeue *next;
}node_queue,*node_pqueue;

typedef struct linkqueue{		//将front指针和rear指针封装
    node_pqueue front,rear;
}link_queue,*link_pqueue;

extern void init_linkqueue(link_pqueue *Q);
extern bool linkqueue_in(link_pqueue q,datatype data);
extern bool linkqueue_out(link_pqueue q,datatype* data);
extern bool isempty_linkqueue(link_pqueue q);
//extern void show_linkqueue(link_pqueue q);
#endif
