###################################################################
  # File Name: grep.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 10:02:09 AM CST
###################################################################
#!/bin/bash

for file in *
do
    if grep -l POSIX $file
    then
        more $file
    fi
done
