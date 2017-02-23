#include "linkqueue.h"

int main(void)
{
    link_pqueue q;
    datatype data,t;
    int ret;

    init_linkqueue(&q);
    while(1){
	printf("请输入整数:");
	ret = scanf("%d",&data);
	if(ret == 1){  //输入为整数，入队
	    linkqueue_in(q,data);
	    show_linkqueue(q);
	}else{
	    if(linkqueue_out(q,&t))
		printf("out is %d\n",t);
	    show_linkqueue(q);
	    while(getchar()!='\n');   //清空缓冲区
	}
    }

    return 0;
}
