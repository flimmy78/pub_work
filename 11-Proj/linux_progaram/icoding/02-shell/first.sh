###################################################################
  # File Name: first.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 10:08:43 AM CST
###################################################################
#!/bin/bash

#first
#This file looks through all the files in the current
#directory for the string POSIX, and then prints the names of
#those files to the standard output.

for file in *
do
    if grep -q POSIX $file
    then
        echo $file
    fi
done

exit 0
