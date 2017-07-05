###################################################################
  # File Name: 32-trap.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Fri 02 Jun 2017 10:06:19 AM CST
###################################################################
#!/bin/bash

# trap:第一个参数是接收到指定信号时将要采取的行动；
#   第二个参数是要处理的信号名；
trap 'rm -f /tmp/my_tmp_file_$$' INT
echo creating file /tmp/my_tmp_file_$$
date > /tmp/my_tmp_file_$$

echo "press interrupt (CTRL-C) to interrupt ..."
while [ -f /tmp/my_tmp_file_$$ ]
do
    echo File exists
    sleep 1
done

echo The file no longer exists

#恢复信号的默认设置
trap INT
echo creating file /tmp/my_tmp_file_$$
date > /tmp/my_tmp_file_$$

echo "Press interrupt (control-C) to interrupt ..."
while [ -f /tmp/my_tmp_file_$$ ]
do
    echo File exists
    sleep 1
done

echo we never get here

exit 0
