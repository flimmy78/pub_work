

obj:
	gcc -c bill.c fred.c
	ls *.o

program:obj
	gcc -c program.c
	gcc -o program program.o bill.o

ar:obj
	ar crv libfoo.a bill.o fred.o
	#为函数库生成一个内容表
	ranlib libfoo.a

program_WithFUNCLib:ar
	gcc -c program.c
	gcc -o program_WithFUNCLib program.o libfoo.a

program_WithFUNCLib_:ar
	gcc -c program.c
	gcc -o program_WithFUNCLib_ program.o -L. -lfoo

clean:
	$(RM) a.out *.o program program_WithFUNCLib program_WithFUNCLib_
