###################################################################
  # File Name: 00-grep.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 10:45:22 AM CST
###################################################################
#!/bin/bash

for file in *
do 
    if grep -l POSIX $file
    then
#echo $file
        more $file
    fi
done
