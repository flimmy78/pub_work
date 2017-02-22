#! /bin/sh
# program2   for   tput#
bell=`tput  bel`
s_uline=`tput  smul`
e_uline=`tput  rmul`
tput  clear
tput  cup  10  20
echo  $bell   $s_uline
echo  "Computer  Department"
echo  $e_uline
#功能:  响一声铃后, 在清空的屏幕中央以下划线模式显示字符串"Computer  Department"
