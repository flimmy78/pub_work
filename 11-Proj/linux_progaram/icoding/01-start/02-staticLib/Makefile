all:obj
	gcc -o program *.o

# -c选项的作用：阻止编译器创建一个完整的程序
obj:
	gcc -c *.c

# ar:创建归档文件
lib:obj
	ar crv libfoo.a bill.o fred.o
	ranlib libfoo.a 
	@echo  "\t#为函数库生成内容表"

program:lib
	gcc -o program program.o -L. -lfoo

#-L. 告诉编译器在当前目录（.）中查找函数库；
#-lfoo 告诉编译器使用名为libfoo.a的函数库

clean:
	$(RM) *.o program .*.*.sw? *.a

.PHONY:clean program lib obj all



