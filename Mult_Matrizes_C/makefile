all: gerar

rodar:
	./executavel

gerar:
	gcc multiplicar_matriz.c -o executavel
	
	
clean:
	rm -rf *.o *~ executavel

pasta:
	mkdir matarizes resultado

matrizarq: mat
	./matriz

mat: matrizarq
	gcc gerarmatriz.c -o matriz