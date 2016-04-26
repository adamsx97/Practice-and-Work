p8.out : main.o indexpager.o pager.o
	g++ main.o indexpager.o pager.o -o p8.out

main.o : main.cpp indexpager.h pager.h
	g++ -ansi -Wall -g -c main.cpp -o main.o

indexpager.o : indexpager.cpp indexpager.h pager.h
	g++ -ansi -Wall -g -c indexpager.cpp -o indexpager.o

pager.o : pager.cpp pager.h
	g++ -ansi -Wall -g -c pager.cpp -o pager.o

clean:
	rm -f main.o indexpager.o pager.o p8.out
