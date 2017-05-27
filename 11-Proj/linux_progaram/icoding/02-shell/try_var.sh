###################################################################
  # File Name: try_var.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Sat 27 May 2017 11:57:56 AM CST
###################################################################
#!/bin/bash

salutation="HELLO"
echo -e "\e[41;33;1m$salutation\e[0m"
echo -e "\e[42;30;1mThe program\e[0m $0 \e[42;30;1mis now running\e[0m"
echo -e "\e[4mThe second parameter was\e[0m $2"
echo -e "\e[4mThe first parameter was\e[0m $1"
echo -e "\e[4mThe parameter list was\e[0m $*"
echo -e "\e[4mThs user's home directory is\e[0m $HOME"

echo -e "\e[42;30;4mPlease\e[0m \e[45;30;4menter\e[0m \e[46;30;4ma\e[0m \e[47;30;4mnew\e[0m \e[44;30;4mgreeting\e[0m"
read salutation

echo -e "\e[41;33;1m$salutation\e[0m"
echo "The script is now complete"
exit 0
