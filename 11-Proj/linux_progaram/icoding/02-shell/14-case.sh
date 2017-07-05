###################################################################
  # File Name: 14-case.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 02:12:30 PM CST
###################################################################
#!/bin/bash

echo "Is it morning ? Please answer yes or no"
read timeofday

case "$timeofday" in
    yes ) echo "Good Morning";;
    no  ) echo "Good Afternoon";;
    y   ) echo "Good Morning";;
    n   ) echo "Good Afternoon";;
    *   ) echo "sorry, answer not recognized";;
esac

exit 0
