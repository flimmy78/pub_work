###################################################################
  # File Name: 20-or.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 02:55:15 PM CST
###################################################################
#!/bin/bash

rm -f file_one

# OR列表结构:执行一系列命令，直到有一条命令成功为止
if [ -f file_one ] || echo "Hello" || echo "there"
then
    echo "in if" 
else
    echo "in else"
fi

exit 0
