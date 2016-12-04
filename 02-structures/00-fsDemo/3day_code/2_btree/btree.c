#include "btree.h"
#include "linkqueue.h"
#include "seqstack.h"
#if 1
btree_pnode create_btree(void)
{
    btree_pnode t;
    datatype_bt ch;

    scanf("%c",&ch);  //从键盘获得数据
    if(ch == '#'){    //该结点不存在
	t = NULL;
    }else{  //该结点存在，申请空间存储数据
	//创建根结点
	t = (btree_pnode)malloc(sizeof(btree_node));
	if(NULL == t){
	    perror("malloc");
	    exit(1);
	}
	t->data = ch;	//将数据存储在空间中
	
	//创建跟结点的左子树
	t->lchild = create_btree();
	//创建跟结点的右子树
	t->rchild = create_btree();
    }
    return t;
}
#else
void create_btree(btree_pnode *T)
{
    datatype_bt ch;

    scanf("%c",&ch);  //从键盘获得数据
    if(ch == '#'){    //该结点不存在
	*T = NULL;
    }else{  //该结点存在，申请空间存储数据
	//创建根结点
	*T = (btree_pnode)malloc(sizeof(btree_node));
	if(NULL == *T){
	    perror("malloc");
	    exit(1);
	}
	(*T)->data = ch;	//将数据存储在空间中
	
	//创建跟结点的左子树
	create_btree(&(*T)->lchild);
	//创建跟结点的右子树
	create_btree(&(*T)->rchild);
    }

}
#endif

//先序遍历二叉树
void pre_order(btree_pnode t)
{
    if(t != NULL){
	printf("%c",t->data);  //访问根结点
	pre_order(t->lchild);    //先序遍历左子树
	pre_order(t->rchild);    //先序遍历右子树
    }
}
//先序非递归遍历
void pre_order_un(btree_pnode t)
{
    seq_pstack s;

    init_seqstack(&s);  //初始化顺序栈
    while(t != NULL || !isempty_seqstack(s)){
	while(t != NULL){
	    printf("%c",t->data);
	    if(t->rchild != NULL)
		seqstack_push(s,t->rchild);
	    t = t->lchild;
	}
	if(!isempty_seqstack(s))
	    seqstack_pop(s,&t);
    }
}
//中序遍历二叉树
void mid_order(btree_pnode t)
{
    if(t != NULL){
	mid_order(t->lchild);    //中序遍历左子树
	printf("%c",t->data);  //访问根结点
	mid_order(t->rchild);    //中序遍历右子树
    }
}
//后序遍历二叉树
void post_order(btree_pnode t)
{
    if(t != NULL){
	post_order(t->lchild);    //后序遍历左子树
	post_order(t->rchild);    //后序遍历右子树
	printf("%c",t->data);  //访问根结点
    }
}
//按层遍历
void level_order(btree_pnode t)
{
    link_pqueue q;

    init_linkqueue(&q);   //初始化链式队列
    
    while(t != NULL){
	printf("%c",t->data);
	if(t->lchild != NULL)
	    linkqueue_in(q,t->lchild);
	if(t->rchild != NULL)
	    linkqueue_in(q,t->rchild);
	if(isempty_linkqueue(q))
	    break;
	else
	    linkqueue_out(q,&t);
    }
    
}

void travel(char *str,void (*p)(btree_pnode ),btree_pnode t)
{
    printf("%s",str);
    p(t);
    printf("\n");
}

