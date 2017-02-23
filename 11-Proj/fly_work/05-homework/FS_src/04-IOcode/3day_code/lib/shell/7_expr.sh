#! /bin/sh

expr 10 \* 2    #计算10乘2，并将结果打印到屏幕上

sum=`expr 12 + 5 \* 3`    #引用expr的运算结果，赋值给sum
echo $sum

