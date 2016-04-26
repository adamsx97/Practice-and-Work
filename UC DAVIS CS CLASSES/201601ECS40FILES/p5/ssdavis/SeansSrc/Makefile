CPU.out : data.o decoder.o instruction2.o instruction.o labels.o main.o memory.o registers.o word.o  
	g++ -ansi -Wall -o CPU.out data.o decoder.o instruction2.o instruction.o labels.o main.o memory.o registers.o word.o  

data.o : data.cpp data.h 
	g++ -ansi -Wall -c data.cpp

decoder.o : decoder.cpp decoder.h instruction.h registers.h memory.h data.h 
	g++ -ansi -Wall -c decoder.cpp

instruction2.o : instruction2.cpp instruction2.h 
	g++ -ansi -Wall -c instruction2.cpp

instruction.o : instruction.cpp instruction.h 
	g++ -ansi -Wall -c instruction.cpp

labels.o : labels.cpp labels.h 
	g++ -ansi -Wall -c labels.cpp

main.o : main.cpp registers.h decoder.h instruction.h labels.h memory.h data.h 
	g++ -ansi -Wall -c main.cpp

memory.o : memory.cpp memory.h instruction.h word.h data.h registers.h 
	g++ -ansi -Wall -c memory.cpp

registers.o : registers.cpp registers.h data.h 
	g++ -ansi -Wall -c registers.cpp

word.o : word.cpp word.h 
	g++ -ansi -Wall -c word.cpp

clean : 
	rm -f CPU.out data.o  decoder.o  instruction2.o  instruction.o  labels.o  main.o  memory.o  registers.o  word.o   
