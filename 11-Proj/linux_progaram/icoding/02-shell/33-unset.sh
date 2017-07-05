###################################################################
  # File Name: 33-unset.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Fri 02 Jun 2017 10:28:15 AM CST
###################################################################
#!/bin/bash

# unset命令的作用是从环境中删除变量或函数
foo="Hello World"
echo $foo

unset foo
echo -e "\e[31mAfter unset\e[0m"
echo $foo
