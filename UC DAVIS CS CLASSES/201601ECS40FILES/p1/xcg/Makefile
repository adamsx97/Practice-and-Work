CPU.out: main.o decoder.o reader.o registers.o
	g++ -o CPU.out -g -Wall main.o decoder.o registers.o reader.o
main.o: main.c decoder.h registers.h reader.h instruction.h main.h
	g++ -c main.c -Wall -ansi -g -o main.o
decoder.o: decoder.c decoder.h instruction.h main.h registers.h
	g++ -c decoder.c -Wall -ansi -g -o decoder.o
registers.o: registers.c registers.h main.h instruction.h
	g++ -c registers.c -Wall -ansi -g -o registers.o
reader.o: reader.c main.h reader.h instruction.h registers.h
	g++ -c reader.c -Wall -ansi -g -o reader.o
clean:
	rm CPU.out main.o decoder.o registers.o reader.o

