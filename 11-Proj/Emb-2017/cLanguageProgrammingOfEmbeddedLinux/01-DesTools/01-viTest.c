/*******************************************************************
 *   > File Name: 01-viTest.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 27 Sep 2017 10:57:59 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    return 0;
}

#if (0)
#if(vi的剪切/修改/复制)
nx
ncb
ncw
c$
ndd
s
S
r 待修改字符
R
nyb
nyw
y$
nyy
p
u
#endif

#if (vi中光标移动的指令)
0
$
Ctrl+d
Ctrl+f
h
l
k
j
H
gg
M
L
b
w
e
^
n-
n+
nG
:n
#endif

#if (vi的查找与替换指令)
/<要查找的字符>
?<要查找的字符>
:rang s/string1/string2/gc

%:表示所有行；
.:表示当前行；
$:表示最末行；
:10,20s/str1/str2/
:2,$-5/str1/str2/g
:s/str1/str2/
:s/str1/str2/g
:1,$ s/str1/str2/g
:%s/str1/str2/g
#endif

#if (vi的文件操作指令)
:q
:q!
:w
#endif
#endif

