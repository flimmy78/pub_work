#!/bin/bash

:<<!
######查看操作######
#只查看文件第5行
sed -n '5p' test.txt
#只查看文件第3到第5行
sed -n '3,5p' test.txt
#打印第五行到最后一行
sed -n '5,$p' test.txt
!

if false;then
######删除操作######
#删除文件的第3行，然后将内容输出，不是直接操作文件
sed '3 d' test.txt
#删除文件第三行到第五行
sed '3,5 d' test.txt
#删除文件第三行到最后一行
sed '3,$ d'
fi

:<<!
######添加操作######
#在第二行后面添加一行，内容word
sed '2a word' test.txt
#在第三行前面添加一行，内容为word
sed '3i word' test.txt
!

if false;then
echo "Have a good time"
fi

if false;then
######查找操作######
#只输出root关键字的行
sed -n '/root/p' test.txt
#将含有root的行删除，然后输出，加上-i可以操作源文件
sed '/root/d' test.txt
fi

:<<任意字符
######替换操作######
#将文件中的root替换成new，每行只替换一次
sed 's/root/new/' test.txt
#将每行的所有root全部替换成new g替换多次
sed 's/root/new/g' test.txt
#只替换第3行到第4行的root为new
sed '3,4s/root/new/g' test.txt
任意字符


