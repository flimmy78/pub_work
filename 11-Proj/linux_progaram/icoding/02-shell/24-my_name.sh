###################################################################
  # File Name: 24-my_name.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 04:01:51 PM CST
###################################################################
#!/bin/bash

yes_or_no(){
    echo "Is your name $* ?"
    while true
    do
        echo -n "Enter yes or no :"
        read x
        case "$x" in
            y | yes )   return 0;;
            n | no  )   return 1;;
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
