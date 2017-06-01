###################################################################
  # File Name: 04-val.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 11:34:30 AM CST
###################################################################
#!/bin/bash

# $1,$2...脚本程序的参数；
# $*
# $@

IFS=''
set foo bar bam
echo "$@"
echo "$*"
unset IFS
echo "$*"
