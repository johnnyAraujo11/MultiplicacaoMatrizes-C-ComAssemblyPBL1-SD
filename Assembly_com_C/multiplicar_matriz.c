#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "mult.h"

int **alocar_Matriz(int tamanho);   
void desalocar_Matriz(int **matriz, int tamanho);

int main(){
   
   // Tamanho da matriz
   int sizeA, sizeB;
  
   // Abrindo arquivo para leitura
   FILE *fileA, *fileB, *result_of_matriz; 
   clock_t inicio, fim; 
  
   //Abre as matrizes para leitura
   fileA = fopen("./matrizes/matrizA1000.txt", "r");
   fileB = fopen("./matrizes/matrizB1000.txt", "r");
   
   if(fileA == NULL || fileB == NULL){
      printf("Não foi possível abrir o arquivo");
      return 3;
   }
   // Ler o primeiro número do arquivo que é refente ao tamanho da matriz
   fscanf(fileA, "%d",&sizeA);
   fscanf(fileB, "%d",&sizeB);

   
   int **matrizA, **matrizB;
   // aloca a matriz dinamicamente 
   matrizA = alocar_Matriz(sizeA);
   matrizB = alocar_Matriz(sizeB);

      // Buscar os elementos do arquivo e adicionar nas matrizes
      for(int i=0; i<sizeA;i++){
         for(int j=0; j<sizeA;j++){
            fscanf(fileA, "%d", &matrizA[i][j]);
            fscanf(fileB,"%d", &matrizB[i][j]);
         }
      }
   
   fclose(fileA);
   fclose(fileB);

  //abrir o arquivo para escrita e escrever o resultado da multiplicaçãod

   result_of_matriz = fopen("./resultado/result_matriz.txt", "w");

  
   int i=0,j=0,k=0;
   int resposta=0, cont=0, soma=0, temp=0, a=0;
 
   // início da contagem do tempo
   inicio = clock();

   multiplicar(matrizA, matrizB,sizeA, result_of_matriz);

   //fim da contagem do tempo
   fim = clock();

   // apresenta o resultado em segundos
   printf("\nO temp foi de %.7lf\n",((float)(fim - inicio)/CLOCKS_PER_SEC) ); 

   printf("\ncontador: %d", cont);

   // liberar o espaço de memória
   desalocar_Matriz(matrizA, sizeA);
   desalocar_Matriz(matrizB, sizeB);

   printf("\n");
   return 0;
   
}


int **alocar_Matriz(int tamanho){
   
   int **matriz;
   matriz = (int **)malloc(tamanho * sizeof(int *));
   if(matriz == NULL){
      printf("\nMemória insuficiente\n");
   }
   
   for(int i=0; i < tamanho; i++){
   
      matriz[i] = (int *)malloc(tamanho * sizeof(int));
      if(matriz[i] == NULL){
         printf("\nMemória insuficiente\n");
      }
   }
   
   return  matriz;
}

void desalocar_Matriz(int **matriz, int tamanho){
   for(int i ; i< tamanho; i++){
      free(matriz[i]);
   }
   free(matriz);
}
