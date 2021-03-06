1、代码编译

mkdir sqlite 
tar zxvf sqlite-autoconf-3110000.tar.gz -C sqlite 
cd sqlite/sqlite-autoconf-3110000 
./configure –prefix=/home/andy/test #–prefix用于指定sqlite库文件、头文件和可行性命令的安装路径 
- make #进行编译 
- make install #把sqlite安装到–prefix指定的目录下 
- 顺利执行后，在/home/andy/test 目录下会出现四个文件夹 
- bin #存放sqlite命令文件 
- include #存放sqlite的头文件 
- lib #存放sqlite库文件，包括静态库和动态库 
- share #存放帮助文件等辅助性的文档

2、移植

如果是相同的平台，可以把上述test目录下的四个文件夹拷贝到目标系统中，具体的做法为: 
- 将bin目录下的文件拷贝到 /usr/local/bin 
- 将lib目录下的文件拷贝到 /usr/local/lib 拷贝过程需要特别注意软连接 
- include –> /usr/local/include 
- share –> /usr/local/share

3、编译测试代码

下面代码就是在当前目录创建一个名为test.sq3的数据库文件 

#include <stdio.h> 
#include <sqlite3.h> 
int main(int argc, char *argv[]) 
{ 
    sqlite3 *handle = NULL; 
    int iret = 0; 
    iret = sqlite3_open("test.sq3", &handle); 
    if (iret != SQLITE_OK) 
    { 
        printf("sqlite3_open error, reason = %s\n", sqlite3_errmsg(handle)); 
        return 0; 
    } 
    if(handle != NULL) 
    { 
        (void)sqlite3_close(handle); 
    } 
    return 0; 
} 

gcc -o test test.c -lsqlite3 #默认链接动态库 
gcc -o test test.c -static -lsqlite3 -lpthread -ldl #指定链接动态库

4、链接静态库编译问题

刚开始直接使用gcc -o test test.c -static -lsqlite3 编译报如下错误： 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:21116：对‘pthread_mutex_trylock’未定义的引用 
./lib//libsqlite3.a(sqlite3.o)：在函数‘sqlite3ThreadCreate’中： 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:24506：对‘pthread_create’未定义的引用 
./lib//libsqlite3.a(sqlite3.o)：在函数‘pthreadMutexFree’中： 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:21021：对‘pthread_mutex_destroy’未定义的引用 
./lib//libsqlite3.a(sqlite3.o)：在函数‘pthreadMutexAlloc’中： 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:20977：对‘pthread_mutexattr_init’未定义的引用 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:20978：对‘pthread_mutexattr_settype’未定义的引用 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:20979：对‘pthread_mutex_init’未定义的引用 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:20980：对‘pthread_mutexattr_destroy’未定义的引用 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:20988：对‘pthread_mutex_init’未定义的引用 
./lib//libsqlite3.a(sqlite3.o)：在函数‘sqlite3ThreadJoin’中： 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:24526：对‘pthread_join’未定义的引用 
./lib//libsqlite3.a(sqlite3.o)：在函数‘unixDlError’中： 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:33375：对‘dlerror’未定义的引用 
./lib//libsqlite3.a(sqlite3.o)：在函数‘pthreadMutexLeave’中： 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:21154：对‘pthread_mutex_unlock’未定义的引用 
./lib//libsqlite3.a(sqlite3.o)：在函数‘pthreadMutexEnter’中： 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:21070：对‘pthread_mutex_lock’未定义的引用 
./lib//libsqlite3.a(sqlite3.o)：在函数‘unixDlClose’中： 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:33406：对‘dlclose’未定义的引用 
./lib//libsqlite3.a(sqlite3.o)：在函数‘unixDlSym’中： 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:33402：对‘dlsym’未定义的引用 
./lib//libsqlite3.a(sqlite3.o)：在函数‘unixDlOpen’中：

说明sqlite库中还是通过动态加载的方式引用了pthread库和dl库。 
改为gcc -o test test.c -static -lsqlite3 -lpthread -ldl 编译能成功，但是会有如下报警： 
./lib//libsqlite3.a(sqlite3.o)：在函数‘unixDlOpen’中： 
/home/andy/code/sqlite/sqlite-autoconf-3110000/sqlite3.c:33361: 警告： Using ‘dlopen’ in statically linked applications requires at runtime the shared libraries from the glibc version used for linking 
提示编译环境和运行环境的libc版本必须一直。


[zzx@localhost sqlite-autoconf-3140100]$ ./configure --prefix=/home/zzx/fl2440/3rdparty/sqlite-arm-linux/sqlite-autoconf-3140100/install --host=arm-linux CC=/opt/buildroot-2012.08/arm920t/usr/bin/arm-linux-gcc
注：CC赋值为嵌入式开发环境所使用的交叉编译工具，后面接自己交叉编译器的路径 ，    --host指定软件运行环境为arm-linux，   --prefix指定源码交叉编译后生成文件的路径，我们指向了刚才新建的install文件夹

5.命令安装可执行程序和库文件：（编译安装见Makefile）
    sudo apt-get install sqlite3
    编译sqlite3 C语言程序时出现fatal error：sqlite3.h:No such file or directory,需要安装函数库：
    sudo apt-get install libsqlite3-dev
    当用交叉编译器编译的时候，也会出现找不到sqlite3.h头文件的情况，解决方法是把sqlite3.h这个头文件放到交叉编译工具目录的 include目录下。

