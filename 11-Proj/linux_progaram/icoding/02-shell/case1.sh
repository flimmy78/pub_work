###################################################################
  # File Name: case1.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 02:48:50 PM CST
###################################################################
#!/bin/bash

echo "Is it morning ? Please answer yes or no"
read timeofday

case "$timeofday" in
    yes | y | Yes | YES )   echo "Good Morning";;
    #n* | N* )               echo "Good afternoon";;
    no | n | No | NO | N)   echo "Good afternoon";;
    *)                      echo "Sorry, answer not recognized";;
esac

exit 0
