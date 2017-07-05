###################################################################
  # File Name: 21-get.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Thu 01 Jun 2017 03:10:49 PM CST
###################################################################
#!/bin/bash

get_confirm && {
    grep -v "$cdcatnum" $tracks_file > $temp_file
    cat $temp_file > $tracks_file
    echo
    add_reord_tracks
}
