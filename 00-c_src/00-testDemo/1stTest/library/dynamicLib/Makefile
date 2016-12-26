.PHONY:clean
.IGNORE:clean


testlib:
	gcc  -o src/testlib.o -fPIC -Wall -c src/testlib.c

libtest:testlib
	gcc -shared -fPIC -o lib/libtest.so src/testlib.o

main:libtest
	$(CC) -o bin/main src/main.c -Llib/ -ltest -Iinc/

install:
	sudo cp lib/libtest.so /lib

clean:
	$(RM) src/testlib.o lib/libtest.so bin/main
	sudo rm /lib/libtest.so

#装载动态库
#1.将动态库放入系统库路径下sudo cp libtest.so /lib
#
#2.将动态库的路径加入到库的配置文件/etc/ld.so.conf.d/libc.conf
#	使之生效，执行：sudo ldconfig
#
#3.将动态库的路径加入到环境变量中
#执行：export LD_LIBRARY_PATH = 动态库的路径
#
