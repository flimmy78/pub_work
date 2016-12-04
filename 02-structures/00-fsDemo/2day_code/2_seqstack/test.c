#include "seqstack.h"


int main(void)
{
    seq_pstack s;
    int data,m;
    datatype tmp;

    init_seqstack(&s);   //初始化空栈
    printf("请输入十进制数:");
    scanf("%d",&data);
    if(data < 0)
	m = -data;
    else
	m = data;
    while(m){
	seqstack_push(s,m % 8);
	m /= 8;
    }
    
    if(data >= 0)
	printf("十进制数：%d 转换成八进制数为:0",data);
    else
	printf("十进制数：%d 转换成八进制数为:-0",data);
    while(!isempty_seqstack(s)){
	seqstack_pop(s,&tmp);
	printf("%d",tmp);
    }
    printf("\n");
    return 0;
}
