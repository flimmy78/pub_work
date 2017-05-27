###################################################################
  # File Name: case.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 02:38:51 PM CST
###################################################################
#!/bin/bash

echo "Is it morning ? Please answer yes or no"
read timeofday

case "$timeofday" in
    yes) echo "Good Morning";;
    no) echo "Good afternoon";;
    y) echo "Good Morning";;
    n) echo "Good afternoon";;
    *) echo "Sorry, answer not recognized";;
esac

exit 0
