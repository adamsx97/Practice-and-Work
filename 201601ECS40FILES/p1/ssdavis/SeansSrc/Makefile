CPU.out : decoder.o main.o  reader.o registers.o 
	g++ -Wall -ansi -o CPU.out decoder.o  main.o reader.o registers.o  

decoder.o: decoder.c decoder.h registers.h reader.h instruction.h main.h 
	g++ -Wall -ansi -c decoder.c

main.o: main.c registers.h decoder.h  reader.h instruction.h main.h 
	g++ -Wall -ansi -c main.c

reader.o: reader.c reader.h registers.h main.h 
	g++ -Wall -ansi -c reader.c

registers.o: registers.c registers.h main.h 
	g++ -Wall -ansi -c registers.c


clean:
	rm -f CPU.out decoder.o  main.o  reader.o registers.o  
