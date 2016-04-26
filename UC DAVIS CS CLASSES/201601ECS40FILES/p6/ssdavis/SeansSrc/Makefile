FileFind.out: directory.o main.o
	g++ -Wall -ansi  -o FileFind.out directory.o main.o 

directory.o: directory.cpp directory.h list.cpp list.h 
	g++ -Wall -ansi -c directory.cpp

main.o: main.cpp list.h directory.h list.cpp 
	g++ -Wall -ansi  -c main.cpp

clean:
	rm -f FileFind.out directory.o main.o 
