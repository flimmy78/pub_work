###################################################################
  # File Name: 23-local.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 03:23:15 PM CST
###################################################################
#!/bin/bash

sample_text="global variable"

foo(){
#使用local声明局部变量
#局部变量在函数仅在函数的作用范围内有效
    local sample_text="local variable"
    echo "Function foo is executing"
    echo $sample_text
}

echo -e "\e[42;31;1mScript starting\e[0m"
echo $sample_text

foo

echo -e "\e[42;31;1mScript ended\e[0m"
echo $sample_text

exit 0
