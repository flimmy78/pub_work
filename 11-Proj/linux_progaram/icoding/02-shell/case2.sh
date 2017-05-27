###################################################################
  # File Name: case2.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 02:55:23 PM CST
###################################################################
#!/bin/bash

echo "Is it morning ? Please answer yes or no"
read timeofday

case "$timeofday" in
    yes | y | Yes | YES | Y)
        echo "Good Morning"
        echo "Up bright and early this morning"
        ;;
    [nN]*)
        echo "Good Afternoon"
        ;;
    *)
        echo "Sorry, answer not recpgnized"
        echo "Please answer yes or no"
        exit 1
        ;;
esac

exit 0
