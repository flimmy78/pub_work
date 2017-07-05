###################################################################
  # File Name: 37-match.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Fri 02 Jun 2017 11:33:57 AM CST
###################################################################
#!/bin/bash

echo -e "\e[31m\${param:-default} 如果param为空，把它设置为default的值\e[0m"
unset foo
echo ${foo:-bar}

foo=fud
echo ${foo:-bar}

echo -e "\e[31m\${#param} 给出param的长度\e[0m"
echo ${#foo}

foo=/usr/bin/X11/startx
echo -e "\e[31m\${param#word} 从param的头部开始删除与word匹配的最小部分，然后返回剩余部分\e[0m"
echo "foo=$foo"
echo "word=*/"
echo ${foo#*/}
echo -e "\e[31m\${param#word} 从param的头部开始删除与word匹配的最大部分，然后返回剩余部分\e[0m"
echo ${foo##*/}

bar=/usr/local/etc/local/networks
echo -e "\e[31m\${param#word} 从param的尾部开始删除与word匹配的最小部分，然后返回剩余部分\e[0m"
echo "bar=$bar"
echo "word=local*"
echo ${bar%local*}
echo -e "\e[31m\${param#word} 从param的尾部开始删除与word匹配的最长部分，然后返回剩余部分\e[0m"
echo ${bar%%local*}

exit 0
