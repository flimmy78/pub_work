###################################################################
  # File Name: 26-cmd.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 04:33:36 PM CST
###################################################################
#!/bin/bash

rm -f fred
if [ -f fred ]
then
    :
else
    echo file fred did not exist
fi

exit 0
