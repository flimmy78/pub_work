.PHONY:clean  install

hello:hello.o
	$(CC) hello.o -o ../bin/hello
	@echo "链接"
hello.o:hello.s
	$(CC) -c hello.s -o hello.o
	@echo "汇编"
hello.s:hello.i
	$(CC) -S hello.i -o hello.s
	@echo "编译"
hello.i:hello.c	
	$(CC) -E hello.c -o hello.i
	@echo "预处理"

install:
	cp  hello ../bin

############################################################
#创建静态函数库
#
ar:bill.o fred.o
	ar crv libfoo.a bill.o fred.o
	ranlib libfoo.a
	mv libfoo.a ../lib
bill.o:bill.c
	$(CC) -c bill.c
fred.o:fred.c
	$(CC) -c fred.c

useLib:ar program.o
	$(CC) -o program program.o -L../lib  -lfoo 
program.o:program.c
	$(CC) -c program.c -I../inc

###########################################################
#清除
clean:
	$(RM) *.i *.s *.o ../bin/hello ../lib/libfoo.a
