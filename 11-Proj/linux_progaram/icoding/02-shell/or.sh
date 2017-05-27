###################################################################
  # File Name: or.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 04:51:26 PM CST
###################################################################
#!/bin/bash

rm -f file_one

#OR列表：执行一系列命令直到有一条命令成功为止，其后的命令将不再被执行
if [ -f file_one ] || echo "HELLO" || echo "There"
then
    echo "in if"
else
    echo "in else"
fi

#语句块
##get_confirm && {
##    grep -v "$tracks_file > $temp_file"
##    cat $tem_file > $tracks_file
##    echo
##    add_record_tracks
##}

exit 0
