###################################################################
  # File Name: 27-continue.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 04:36:13 PM CST
###################################################################
#!/bin/bash

rm -rf fred*
echo > fred1
echo > fred2
mkdir fred3
echo > fred4

for file in fred*
do
    if [ -d "$file" ]
    then
        echo "Skipping directory $file"
        continue
    fi
    echo file is $file
done

rm -rf fred*

exit 0
