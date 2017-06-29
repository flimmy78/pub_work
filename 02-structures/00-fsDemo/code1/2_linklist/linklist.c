#include "linklist.h"

/*初始化*/
void init_linklist(list_pnode *H)
{
    *H = (list_pnode)malloc(sizeof(list_node));
    if(NULL == *H){
        perror("malloc");
        exit(1);
    }
    (*H)->next = NULL;
}

/*插入*/
void insert_linklist(list_pnode p,list_pnode new)
{
    new->next = p->next;
    p->next = new;
}

/*删除*/
void del_linklist(list_pnode p)
{
    list_pnode q;

    if(p->next != NULL){
        q = p->next;
        p->next = q->next;
        free(q);
    }
}

/*创建*/
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

/*打印*/
void show_linklist(list_pnode h)
{
    list_pnode p;

    for(p = h->next; p != NULL; p = p->next)
        printf("%d\t",p->data);
    printf("\n");
}

/*插入*/
void sort_linklist(list_pnode h)
{
    list_pnode p,q;

    p = h->next;
    h->next = NULL;

    while(p != NULL){
        q = p;
        p =  p->next;

        //将q指向的结点插入到头结点后面
        insert_linklist(h,q);
        show_linklist(h);
    }
}
