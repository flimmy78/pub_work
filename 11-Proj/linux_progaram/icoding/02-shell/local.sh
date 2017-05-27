###################################################################
  # File Name: local.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 05:41:28 PM CST
###################################################################
#!/bin/bash

#全局变量
sample_text="global varible"

foo(){
    #局部变量:覆盖全局变量，仅限函数内
    local sample_text="local varible"
    echo "Function foo is executing"
    echo $sample_text
}

echo -e "\e[1;31;4mscript starting\e[0m"
echo $sample_text

foo

echo -e "\e[1;31;4mscript ended\e[0m"
echo $sample_text

exit 0
