###################################################################
  # File Name: env.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 10:43:38 AM CST
###################################################################
#!/bin/bash

echo -e '$HOME'=$HOME"\e[1;31m家目录\e[0m"
echo -e '$PATH'=$PATH"\e[1;42m命令的目录列表\e[0m"
echo -e '$PS1'=$PS1"\e[42;31;4m命令提示符\e[0m"
echo -e '$PS2'=$PS2"\e[;;4m二级提示符\e[0m"
echo -e '$IFS'=$IFS"\e[31;1m输入域分隔符\e[0m"
echo -e '$0'=$0"\e[30;45;1mshell脚本的名字\e[0m"
echo -e '$#'=$#"\e[30;43;1m传递给脚本的参数个数\e[0m"
echo -e '$1'=$1"\e[1;4m脚本程序的第一个参数\e[0m"
echo -e '$$'=$$"\e[30;42;5mshell脚本的进程号\e[0m"

sleep 1

exit 0
