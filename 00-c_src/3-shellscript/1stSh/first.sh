#!/bin/bash

echo "This is a shell script src file ! \n"
echo 'This is a shell script src file !\n'

your_name="SuSun"
echo $your_name
echo ${your_name}
your_name="Sunshine"
echo $your_name

for skill in Ada Coffe Action Java;do
	echo "I am goot at ${skill} Script"
done

for file in `ls /home/fly`;do
	echo "file : ${file}"
done

myUrl="http://www.w3cschool.cc"
readonly myUrl
myUrl="http://www.runoob.com"
unset myUrl

str='this is a string'
your_name='qinjx'
str="Hello,I know your are \"$your_name\"! \n"
echo $str

your_name="qinjx"
greeting="hello,"$your_name" !"
greeting_1="hello,${your_name} !"
echo $greeting $greeting_1

#获取字符长度
string="abcd"
echo ${#string}

#提取子字符串
string="runoob is a great site"
echo ${string:1:4}
echo ${string:2:15}

#查找子字符串
string="runoob is a great company"
echo `expr index "$string" is `
echo $string
echo `expr index "$string" a`

array_name=(value0 value1 value2 value3)

array_name=(
value0
value1
value2
value3
)

array_name[0]=value0
array_name[1]=value1
array_name[2]=value2
array_name[3]=value3

valuen=${array_name[n]}
echo ${array_name[@]}
