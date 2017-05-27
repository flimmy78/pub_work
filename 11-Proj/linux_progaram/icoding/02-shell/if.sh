###################################################################
  # File Name: if.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 01:48:38 PM CST
###################################################################
#!/bin/bash

echo "It is morning ? Please answer yes or no"
read timeofday

if [ $timeofday = "yes" ]
then
    echo "Good morning"
else
    echo "Good afternoon"
fi

exit 0
