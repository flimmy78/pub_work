###################################################################
  # File Name: until.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 02:32:39 PM CST
###################################################################
#!/bin/bash

until who | grep "$1" > /dev/null
do
    sleep 60
done

# now ring the bell and announce the expected user .

echo -e '\e'
echo "**** $1 has just logged in ****"

exit 0
