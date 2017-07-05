###################################################################
  # File Name: 12-while.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 02:00:56 PM CST
###################################################################
#!/bin/bash

echo "Enter password"
read trythis

while [ "$trythis" != "secret" ]
do
    echo "Sorry , try again"
    read trythis
done

exit 0

