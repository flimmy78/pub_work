###################################################################
# File Name: 02-memcache.sh
# Author: fly
# Mail: XXXXXXXX@icode.com
# Created Time: Fri 30 Dec 2016 11:32:52 AM CST
###################################################################
#!/bin/bash

#通过传入ip 以及端口，发送指令获得返回数据
#copyright chengmo qq:8292669

#函数往往放到最上面
function sendmsg()
{
    msg=$1;
    echo  "$1">&8;
    getout;
}
#向socket通道发送指令，并且调用获得返回参数

function getout()
{   
    #read 命令 -u 从打开文件描述符 8 读取数据，-d读取数据忽略掉:\r换行符 
    while read -u 8 -d $'\r' name; 
    do 
        if [ "${name}" == "END"  -o "${name}" == "ERROR" ];then
            break;
        fi;
        echo $name;
    done
}
#由于：memcached每次通讯完毕，会返回：END或者ERROR(出错），通过判断是否是"END"觉得读取是不是结束，否则循环不会停止

if [ $# -lt 2 ];then
    echo "usage:$0 host port [command]";
    exit 1;
fi;

[[ $# -gt 2 ]]&&command=$3;

#设置默认值 如果command为定义则为：stats
command="${command=stats}";
host="$1";
port="$2";



exec 8<>/dev/tcp/${host}/${port};
#打开通向通道是8

if [ "$?" != "0" ];then
    echo "open $host  $port fail!";
    exit 1;
fi

sendmsg "$command";
#发送指定命令


sendmsg "quit";
#发送退出通向命令


exec 8<&-;
exec 8>&-;
#关闭socket通道

exit 0;

