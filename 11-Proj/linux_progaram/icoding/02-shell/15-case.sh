###################################################################
  # File Name: 15-case.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 02:18:54 PM CST
###################################################################
#!/bin/bash

echo "Is it morning ? Please answer yes or no"
read timeofday

case "$timeofday" in
    yes | Y | Yes | YES )   echo "Good Morning";;
    n* | N* )               echo "Good Afternoon";;
    *)                      echo "Sorry , answer not recognized";;
esac

exit 0
