CPU.out : decoder.o main.o  reader.o registers.o instruction.o
	g++ -Wall -ansi -g -o CPU.out decoder.o  main.o reader.o registers.o instruction.o 

decoder.o: decoder.cpp decoder.h registers.h reader.h instruction.h  
	g++ -Wall -ansi -g -c decoder.cpp

main.o: main.cpp registers.h decoder.h  reader.h instruction.h  
	g++ -Wall -ansi -g -c main.cpp

reader.o: reader.cpp reader.h registers.h  
	g++ -Wall -ansi -g -c reader.cpp

registers.o: registers.cpp registers.h  
	g++ -Wall -ansi -g -c registers.cpp

instruction.o: instruction.cpp instruction.h
	g++ -Wall -ansi -g -c instruction.cpp


clean:
	rm -f CPU decoder.o  main.o  reader.o registers.o  
