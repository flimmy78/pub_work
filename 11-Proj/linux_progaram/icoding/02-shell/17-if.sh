###################################################################
  # File Name: 17-if.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 02:37:51 PM CST
###################################################################
#!/bin/bash

if [ -f this_file ]
then
    if [ -f that_file ]
    then
        if [ -f the_other_file ]
        then
            echo "All files present , and correct"
        fi
    fi
else
    echo "file  NOT exist"
fi

