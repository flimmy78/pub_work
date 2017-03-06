###################################################################
  # File Name: 05-profile.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Mon 06 Mar 2017 04:54:04 PM CST
###################################################################
#!/bin/bash

if [ -d testdir ]; then
    for i in testdir/*.sh; do
        if [ -r $i ]; then
            . $i
        fi
    done
    unset i
fi

