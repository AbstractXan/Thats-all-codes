all: phone

phone: main.o direct.o
	g++ main.o Directory.o -o phone
direct.o: Directory.cpp Directory.h
	g++ Directory.cpp -c 
main.o: main.cpp
	g++ main.cpp -c
	

