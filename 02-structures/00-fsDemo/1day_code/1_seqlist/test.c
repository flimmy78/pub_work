/*
   1、用顺序表存储一些正整数，输入正整数表示插入数据（比如输入3表示插入3），输入负整数表示删除数据（比如输入-2表示删除2），输入字符表示退出程序。插入和删除的过程中保持该表递增有序。
 */
#include "seqlist.h"

//搭框架
int main(void)
{
    seq_plist l;
    datatype data;
    int ret;

    init_seqlist(&l);  //初始化空顺序表
    while(1){
	printf("请输入整数:");
	ret = scanf("%d",&data);
	if(ret != 1){  //输入为字符，退出程序
	    exit(0);
	}else if(data > 0){  //输入为正整数，插入到顺序表
	    insert_seqlist(l,data);  //将data插入到l指向顺序表
	    show_seqlist(l);	    //打印顺序表中的数据
	}else{		//输入为负整数，将对应的正整数从顺序表删除
	    del_seqlist(l,-data);  //如果存在删除顺序表中的-data
	    show_seqlist(l);   
	}
    }

    return 0;
}
