###################################################################
  # File Name: 35-count.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Fri 02 Jun 2017 11:24:29 AM CST
###################################################################
#!/bin/bash

# $((...))扩展，可以完成简单的算术运算
x=0
while [ "$x" -ne 10 ]
do
    echo $x
    x=$(($x+1))
done

exit 0
