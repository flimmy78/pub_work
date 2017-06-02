###################################################################
  # File Name: 31-shift.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Fri 02 Jun 2017 09:15:49 AM CST
###################################################################
#!/bin/bash

#!/bin/sh

#shift命令把所有的参数变量左移一个位置;
# $*、$@、$#等其他变量也将根据参数变量的新安排做相应的变动;
while [ "$1" != "" ] 
    do
        echo "$1"
        shift
    done

    exit 0
