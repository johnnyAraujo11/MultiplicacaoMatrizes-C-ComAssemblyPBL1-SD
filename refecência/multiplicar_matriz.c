#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int **alocar_Matriz(int tamanho);
void desalocar_Matriz(int **matriz, int tamanho);

int main(){
   
   // Tamanho da matriz
   int sizeA, sizeB;
  
   // Abrindo arquivo para leitura
   FILE *fileA, *fileB, *result_of_matriz; 
   clock_t inicio, fim; 
  

   fileA = fopen("./matrizes/matrizA100.txt", "r");
   fileB = fopen("./matrizes/matrizB100.txt", "r");
   

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
   result_of_matriz = fopen("./resultado/result_matriz100.txt", "w");

   // início da contagem do tempo
   inicio = clock();
   int soma=0 , resposta;
      for(int i=0;i<sizeA;i++){
	      for(int j=0;j<sizeA;j++){
		      for(int k=0;k<sizeA;k++){
			      resposta = matrizA[i][k] * matrizB[k][j];
			   soma +=resposta;
		   }
         fprintf(result_of_matriz, "%d ", soma);
		   soma =0;
	   }
      fprintf(result_of_matriz, "%s","\n");
   
}
   //fim da contagem do tempo
   fim = clock();

   // apresenta o resultado em segundos
   printf("\nO temp foi de %.7lf\n",((float)(fim - inicio)/CLOCKS_PER_SEC) ); 

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