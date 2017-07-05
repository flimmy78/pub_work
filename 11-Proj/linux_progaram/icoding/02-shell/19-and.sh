###################################################################
  # File Name: 19-and.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 02:49:53 PM CST
###################################################################
#!/bin/bash

touch file_one
rm -rf file_two

#and列表结构，只用前面所有的命令都执行成功的情况下才执行后一条命令；
#&&检查前一条命令的返回值
if [ -f file_one ] && echo "Hello" && [ -f file_two ] && echo "There"
then
    echo "in if"
else
    echo "in else"
fi

exit 0
