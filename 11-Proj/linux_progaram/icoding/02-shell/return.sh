###################################################################
  # File Name: return.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 05:55:00 PM CST
###################################################################
#!/bin/bash

yes_or_no(){
    echo "Is your name $* ?"
    while true
    do
        echo -n "Enter yes or no: "
        read x
        case "$x" in
            y | yes )   return 0;;
            n | no )    return 1;;
            *)          echo "Answer yes or no";;
        esac
    done
}

echo "Original parameters are $*"

if yes_or_no "$1"
then
    echo "Hi $1, nice name"
else
    echo "Never mind"
fi

exit 0
