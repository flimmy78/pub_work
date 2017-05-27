###################################################################
  # File Name: test.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 01:38:25 PM CST
###################################################################
#!/bin/bash

#测试是否是一个文件
if [ -f /bin/bash ]
then
    echo "file /bin/bash exists"
fi

#测试是否是一个目录
if [ -d /bin/bash ]
then
    echo "/bin/bash is a directory"
else
    echo "/bin/bash is NOT a directory"
fi
#-------------------------------------
if test -f /bin/bash
then
    echo -e "\e[31;1mfile /bin/bash exists\e[0m"
fi

if test -d /bin/bash
then
    echo -e "\e[31;1m/bin/bash is a directory\e[0m"
else
    echo -e "\e[31;1m/bin/bash is NOT a directory\e[0m"
fi
