.PHONY:clean

testlib:
	$(CC) -c -o src/testlib.o src/testlib.c

staticlib:testlib
	ar crs lib/libtest.a src/testlib.o
	ranlib lib/libtest.a

main:staticlib
	$(CC) -o bin/main src/main.c -Llib/ -ltest  -Iinc/

install:	

clean:
	$(RM) src/testlib.o lib/libtest.a bin/main
