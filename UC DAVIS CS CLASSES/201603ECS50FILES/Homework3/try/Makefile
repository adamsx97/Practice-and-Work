sfile = mul.s
exe = mul.out

mul.out: mul.o
	ld -melf_i386 -o $(exe) mul.o
mul.o: $(sfile)
	as --32 --gstabs -o mul.o $(sfile)
	
clean:
	rm -fr $(exe) mul.o
