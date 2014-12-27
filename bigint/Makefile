all: bigint.so copy link

bigint.so: bigint.o
	g++ -shared -Wl,-soname,libbigint.so.1 -o libbigint.so.1.0.0 bigint.o

bigint.o:
	g++ -Wall -fPIC -c bigint.cpp

copy:
	cp -f bigint.h ../libtest/
	cp -f libbigint.so.1.0.0 /usr/lib

link:
	ln -s /usr/lib/libbigint.so.1.0.0 /usr/lib/libbigint.so.1
	ln -s /usr/lib/libbigint.so.1.0.0 /usr/lib/libbigint.so

clean:
	rm -f libbigint.so.1.0.0 bigint.o ../libtest/bigint.h 
	rm -f /usr/lib/libbigint.so.1.0.0 /usr/lib/libbigint.so.1 /usr/lib/libbigint.so
