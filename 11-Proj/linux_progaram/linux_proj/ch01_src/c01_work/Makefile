
TOP	:=/home/fly/Public/linux_progaram/linux_proj/ch01/c01_work

hello:
	$(CC) -o hello $(TOP)/src/hello.c
	mv hello $(TOP)/bin

hello:hello.o
	$(CC) hello.o -o hello
hello.o:hello.s
	$(CC) -c hello.s -o hello.o
hello.s:hello.i
	$(CC) -S hello.i -o hello.s
hello.i:hello.c
	$(CC) -E hello.c -o hello.i

#-C的作用是阻止编译器创建一个完整的程序
obj:
	$(CC) -c $(TOP)/src/bill.c $(TOP)/src/fred.c

clean:
	$(RM) $(TOP)/bin/hello bill.o fred.o
