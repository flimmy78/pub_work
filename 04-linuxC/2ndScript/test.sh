###################################################################
  # File Name: test.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Fri 17 Mar 2017 06:10:53 PM CST
###################################################################
#!/bin/bash


FILE="test.c"
if [ -f  ${FILE} ]
then
    echo "test.c is exist"
else
    echo "no such file"
    touch ${FILE}
    echo "touch test.c ok "
fi

