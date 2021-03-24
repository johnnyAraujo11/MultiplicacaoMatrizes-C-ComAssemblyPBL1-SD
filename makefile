all: exe

pasta:
	mkdir matrizes resultado

exe:
	gcc -m32 -o exe multiplicar_matriz.c -masm=intel
	
	
clean:
	rm -rf *.o *.s *~ exe
