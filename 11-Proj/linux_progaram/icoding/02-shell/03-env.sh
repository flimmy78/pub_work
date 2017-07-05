###################################################################
  # File Name: 03-env.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 11:17:55 AM CST
###################################################################
#!/bin/bash

echo -e '$HOME'=$HOME"\e[30;42;1m家目录\e[0m"
echo -e '$PATH'=$PATH"\e[31;43;4m搜索命令的目录列表\e[0m"
echo -e '$PS1'=$PS1"\e[32;44;1m命令提示符\e[0m"
echo -e '$PS2'=$PS2"\e[30;47;1m二级提示符\e[0m"
echo -e '$IFS'=$IFS"\e[31;4m输入域分隔符\e[0m"
echo -e '$0'=$0"\e[30;42mshell脚本的名字\e[0m"
echo -e '$#'=$#"\e[30;42;1m传递给脚本的参数个数\e[0m"
echo -e '$$'=$$"\e[30;45;1mshell脚本进程号\e[0m"
