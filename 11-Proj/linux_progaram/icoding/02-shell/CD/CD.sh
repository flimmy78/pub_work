###################################################################
  # File Name: CD.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Fri 02 Jun 2017 03:52:14 PM CST
###################################################################
#!/bin/bash

# Very simple example shell script for managing a CD collection.
# Copyright (C) 1996-2007 Wiley Publishing Inc.

# This program is free software; you can 

menu_choice=""
current_cd=""
title_file="title.cdb"
tracks_file="tracks.cdb"
temp_file=/tmp/cdb.$$
trap 'rm -f $temp_file' EXIT

get_return(){
    echo -e "Press return \c"
    read x
    return 0
}

get_confirm(){
    
}
