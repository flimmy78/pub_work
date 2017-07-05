###################################################################
  # File Name: 16-case.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 02:31:50 PM CST
###################################################################
#!/bin/bash

echo "Is it morning ? Please answer yes or no"
read timeofday

case "$timeofday" in
    yes | y | Yes | YES )
        echo "Good morning"
        echo "Up bright and early this morning"
        ;;
    [nN]*)
        echo "Good afternoon"
        ;;
    *)
        echo "Sorry , answer not recognized"
        echo "Please answer yes or no"
        ;;
esac

exit 0
