###################################################################
  # File Name: while.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 02:28:23 PM CST
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
