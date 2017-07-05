###################################################################
  # File Name: 41-gdialog.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Fri 02 Jun 2017 02:38:42 PM CST
###################################################################
#!/bin/bash

# Ask some question and colletc the answer
# gdialog 和 dialog两个命令有着相同的参数

#------------------------------------------------------------------
# 欢迎画面
gdialog --title "Questionnaire"  --msgbox "Welcome to my simple survey" 9 18

#------------------------------------------------------------------
# 一个简单的yes/no对话框来询问用户是否继续操作
gdialog --title "Confirm" --yesno "Are you willing to take part ?" 9 18

#------------------------------------------------------------------
# 环境变量$?来检查用户是否选择了yes
if [ $? != 0 ]
then
    gdialog --infobox "Thank you anyway" 5 20
    sleep 2
    gdialog --clear
    exit 0
fi

#------------------------------------------------------------------
gdialog --title "Questionnaire" --inputbox "Please enter your name" 9 30 2 > _1.txt
Q_NAME=$(cat _1.txt)

gdialog --menu "$Q_NAME, what music do you like best ?" 15 30 4 1 "Classical" 2 "Jazz" 3 "Country" 4 "other" 2 > _1.txt
Q_MUSIC=$(cat _1.txt )

if [ "$Q_MUSIC" = "1" ]
then
    gdialog --title "Likes Classical" --msgbox "Good choice!" 12 25
else
    gdialog --title "Doesn't like Classical" --msgbox "Shame" 12 25
fi

sleep 2
gdialog --clear
exit 0
