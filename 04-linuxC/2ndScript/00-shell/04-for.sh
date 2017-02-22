###################################################################
  # File Name: 04-for.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Fri 30 Dec 2016 03:28:05 PM CST
###################################################################
#!/bin/bash

for((i=1;i<20;i++))
do
    if((i%3==0))
    then
        echo $i
        continue
    fi
done

