check_user( )      #查找已登录的指定用户
{       
    user=`who  |  grep  $1 | wc -l`        
    if [ $user -gt 0 ]        
    then               
	return  1       #找到指定用户        
    else               
	return  0       #未找到指定用户        
    fi
}

while  true         # MAIN, Main, main:   program  begin  here
do	    
    echo  "Input username: "	    
    read   uname	
    check_user  $uname       # 调用函数, 并传递参数uname	    
    if [ $? -eq 1 ]                 # $?为函数返回值	    
    then    
	echo  "user  $uname  online"	
    else	
	echo  "user  $uname  offline"	    
    fi
done
