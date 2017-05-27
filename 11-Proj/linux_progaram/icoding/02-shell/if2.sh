###################################################################
  # File Name: if2.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 04:39:19 PM CST
###################################################################
#!/bin/bash

if [ -f this_file ]
then
    foo="true"
elif [ -f if1.sh ]
then
    foo="True"
elif [ -f the_other_file ]
then
    foo="False"
fi

if [ "$foo"="True" ]
then
    echo "one of the files exists"
fi
