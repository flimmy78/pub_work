###################################################################
  # File Name: varEnv.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 11:50:28 AM CST
###################################################################
#!/bin/bash

IFS=''
set foo bar bam
echo "$@"
echo "$*"
unset IFS
echo "$*"
