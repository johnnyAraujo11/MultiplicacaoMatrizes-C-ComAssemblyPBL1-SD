all: gerar

rodar: executavel
	./executavel

# processo de linkar os arquivos objetos para gerar o executavel
gerar: multiplicar_matriz.o mult.o
	gcc -m32 -o executavel multiplicar_matriz.o mult.o -masm=intel

# gerando arquivo objeto do código
multiplicar_matriz.o: multiplicar_matriz.c mult.c
	gcc -m32 -c -o multiplicar_matriz.o multiplicar_matriz.c -masm=intel

mult.o: mult.h mult.c
	gcc -m32 -c -o mult.o mult.c -masm=intel

assembly:
	gcc -m32 -S multiplicar_matriz.c  -o multiplicar_matriz.s -masm=intel
	gcc -m32 -S mult.c -o mult.s -masm=intel

clean:
	rm -rf *.o *.s *~ executavel























#all: exe

#pasta:
#	mkdir matrizes resultado

#exe:
#	gcc -m32 -o exe multiplicar_matriz.c -masm=intel