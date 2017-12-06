
all:midlib
	$(CC) test.c -lmid -o test -L.

midlib:cpplib
	$(CXX) --shared -o libmid.so mid.cpp -lhello
	sudo cp libmid.so /usr/lib

cpplib:
	$(CXX) --shared -o libhello.so hello.cpp
	sudo cp libhello.so /usr/lib

clean:
	$(RM) test libmid.so libhello.so
	sudo rm /usr/lib/libhello.so /usr/lib/libmid.so
