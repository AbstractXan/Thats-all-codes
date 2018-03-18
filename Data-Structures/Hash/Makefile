CFLAGS = -g -DDEBUG
CC = g++

all: hash

hash: mainhash.o hash.o
	$(CC) $(CFLAGS) mainhash.o hash.o -o nameht
	
mainhash.o : mainhash.cpp
	$(CC) $(CFLAGS) -c mainhash.cpp
	
hash.o : hash.cpp hash.h
	$(CC) $(CFLAGS) -c hash.cpp
	
clean:
	rm -f *.o nameht
