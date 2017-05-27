###################################################################
  # File Name: and.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 04:43:59 PM CST
###################################################################
#!/bin/bash

touch file_one
rm -f file_two

#AND命令列表：只有在前面所有的命令都执行成功的情况下才执行后一条语句。
if [ -f file_one ] && echo "hello" && [ -f file_two ] && echo "there"
then
    echo "in if"
else
    echo "in else"
fi

rm -f file_one

exit 0
