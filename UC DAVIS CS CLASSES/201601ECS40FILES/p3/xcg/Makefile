CPU.out: main.o decoder.o reader.o registers.o instruction.o
	g++ -o CPU.out -g -Wall main.o decoder.o registers.o reader.o instruction.o

main.o: main.cpp decoder.h registers.h reader.h instruction.h
	g++ -c main.cpp -Wall -ansi -g -o main.o

decoder.o: decoder.cpp decoder.h instruction.h registers.h
	g++ -c decoder.cpp -Wall -ansi -g -o decoder.o

registers.o: registers.cpp registers.h instruction.h
	g++ -c registers.cpp -Wall -ansi -g -o registers.o

reader.o: reader.cpp reader.h instruction.h registers.h
	g++ -c reader.cpp -Wall -ansi -g -o reader.o

instruction.o: instruction.cpp instruction.h
	g++ -c instruction.cpp -Wall -ansi -g -o instruction.o

clean:
	rm CPU.out main.o decoder.o registers.o reader.o instruction.o