

all:libhello
	g++ test.cpp -o test -lhello -L.

libhello:
	gcc --shared -o libhello.so hello.c
	#生成的库需要放到/usr/lib下

clean:
	$(RM) test libhello.so
