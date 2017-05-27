###################################################################
  # File Name: val.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 10:40:33 AM CST
###################################################################
#!/bin/bash

myval="Hi there"

echo $myval
echo "$myval"
echo '$myval'
echo \$myval

echo Enter some text
read myval

echo '$myval' now equals $myval
exit 0
