###################################################################
  # File Name: 18-if.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 02:44:30 PM CST
###################################################################
#!/bin/bash

if [ -f this_file ]
then
    foo="true"
elif [ -f that_file ]
then
    foo="true"
elif [ -f the_other_file ]
then
    foo="true"
else
    foo="false"
fi

if [ "$foo"="True" ]
then
    echo "One of the files exists"
fi
