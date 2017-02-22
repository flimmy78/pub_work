#! /bin/sh
#The statement of  if…then…fi                 (注释语句)
if [  $#  -eq  0 ] || [ $# -gt 1 ]
then        
    echo  "Argument is declared error"        
    exit
fi

if [  -f   $1  ]        # (测试参数是否为文件)
then    
    echo "File  $1  exists"          # (引用变量值)
fi

if [  -d   $1  ]                #                (测试参数是否为目录)
then    
    echo "File  $1 is  a  directory"     #  (引用变量值)
fi
