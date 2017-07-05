###################################################################
  # File Name: 25-break.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 04:18:21 PM CST
###################################################################
#!/bin/bash

rm -rf  fred*
echo >  fred1
echo >  fred2
mkdir   fred3
echo >  fred4

for file in fred*
do 
    if [ -d "$file" ]
    then
        break;
    fi
done

echo first directory starting fred was $file
rm -rf fred*

exit 0
