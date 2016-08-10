MemRunner.out : MemMan.o MemCheck.o MemRunner.o mynew.o QuadraticProbing2.o QuadraticProbing.o   
	g++ -ansi -Wall -o MemRunner.out MemCheck.o MemMan.o MemRunner.o mynew.o QuadraticProbing2.o QuadraticProbing.o   

MemMan.o : MemMan.cpp MemMan.h mynew.h MemCheck.h SplayTree.h SplayTree.cpp 
	g++ -ansi -Wall -c MemMan.cpp

MemRunner.o : MemRunner.cpp CPUTimer.h MemMan.h mynew.h  
	g++ -ansi -Wall -c MemRunner.cpp

mynew.o : mynew.cpp mynew.h 
	g++ -ansi -Wall -c mynew.cpp

QuadraticProbing2.o : QuadraticProbing2.cpp QuadraticProbing2.h addressInfo.h 
	g++ -ansi -Wall -c QuadraticProbing2.cpp

QuadraticProbing.o : QuadraticProbing.cpp QuadraticProbing.h addressInfo.h 
	g++ -ansi -Wall -c QuadraticProbing.cpp

clean : 
	rm -f MemRunner.out MemMan.o  MemRunner.o  mynew.o  QuadraticProbing2.o  QuadraticProbing.o  SplayTree.o   
