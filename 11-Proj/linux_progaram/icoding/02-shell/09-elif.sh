###################################################################
  # File Name: 09-elif.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 01:34:45 PM CST
###################################################################
#!/bin/bash

echo "Is it morning ? Please answer yes or no"
read timeofday

if [ "$timeofday" = "yes" ]
then
    echo "Good morning"
elif [ "$timeofday" = "no" ]
then
    echo "Good afternoon"
else
    echo "Sorry , $timeofday not recognized. Enter yes or no"
    exit 1
fi

exit 0
