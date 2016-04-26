FileFind.out : main.o directory.o list.o
	g++ -ansi -g -o FileFind.out main.o directory.o list.o

main.o : main.cpp list.h directory.h
	g++ -Wall -ansi -g -c main.cpp

list.o : list.cpp list.h
	g++ -Wall -ansi -g -c list.cpp

directory.o : directory.cpp directory.h list.h list.cpp
	g++ -Wall -ansi -g -c directory.cpp

clean:
	rm -f FileFind.out main.o directory.o list.o
