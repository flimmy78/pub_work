###################################################################
  # File Name: elif.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 02:02:11 PM CST
###################################################################
#!/bin/bash

echo "Is is morning ? Please anwser yes or no"
read timeofday

if [ $timeofday = "yes" ]
then
    echo "Good morning"
elif [ $timeofday = "no" ]
then
    echo "Good ofternoon"
else
    echo "Sorry , $timeofday not recognized . Enter yes or no"
    exit 1
fi

exit 0
