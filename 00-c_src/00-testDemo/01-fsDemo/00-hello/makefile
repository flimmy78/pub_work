
ALL:Hello

Hello:
	@echo "1.预处理"
	gcc -E 00-hello.c -o hello.i
	@echo "2.编译"
	gcc -S hello.i -o hello.s
	@echo "3.汇编"
	gcc -c hello.s -o hello.o
	@echo "4.链接"
	gcc hello.o -o hello

clean:
	rm -rf hello hello.* a.out
