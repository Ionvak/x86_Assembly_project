ShadeExceptRing: shade_x86_main.o shade_x86.o
	gcc -m32 -o ShadeExceptRing shade_x86_main.o shade_x86.o

shade_x86_main.o: shade_x86_main.c
	gcc -m32 -c shade_x86_main.c

shade_x86.o: shade_x86.s
	nasm -f elf32 shade_x86.s

clean:	
	rm -f *.o *.lst ShadeExceptRing