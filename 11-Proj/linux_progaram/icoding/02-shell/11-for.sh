###################################################################
  # File Name: 11-for.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 01:56:43 PM CST
###################################################################
#!/bin/bash

for file in $(ls 0*.sh)
do
    echo $file
done

exit 0
