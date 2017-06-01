###################################################################
  # File Name: 01-first.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 10:54:25 AM CST
###################################################################
#!/bin/bash

#first
#This file looks throught all the files in the current
#directory for the string POSIX, and then prints the name of
#those files to the standard output.

for file in *
do 
    if grep -q POSIX $file
    then
        echo $file
    fi
done

exit 0
