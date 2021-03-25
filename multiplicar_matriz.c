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
   result_of_matriz = fopen("./resultado/result_matriz.txt", "w");

   
  
   int i=0,j=0,k=0;
   int resposta=0, cont=0, soma=0, temp=0, a=0;
 
   // início da contagem do tempo
   inicio = clock();

   asm volatile("jmp .For1\n\t");  // salto para o label
 
   asm volatile(".Mult:");
   asm volatile(  
                  //"imul       eax, edx\n\t" // faz a multiplicação 
                  "imul %[matrizB],       %[matrizA]\n\t" //  matrizB = matrizA * matrizB;
                  "mov  %[resposta],      %[soma]\n\t" //  resposta = soma;
                  "add  %[resposta],      %[matrizB]\n\t" //  resposta = matrizB + resposta;
                  "mov  %[soma],          %[resposta]\n\t" //  soma = resposta;
                  : [resposta] "=c" (resposta), [soma] "=o" (soma) //recebe o resultado
                  : [matrizA] "a" (matrizA[i][k]) , [matrizB] "b" (matrizB[k][j])//entrada
   );
                  k++;
   asm volatile(  "cmp        %[tam_k], %[tam] \n\t"
                  "jl         .Mult   \n\t"
                  ::[tam_k]"r"(k),[tam]"r"(sizeA));   
                  j++;
                  //printf("\nsoma depois: %d", a);
                  fprintf(result_of_matriz, "%d ", soma);
                  soma=0;

   asm volatile(  "jmp        .For2");
//-----------------------------------------
   asm volatile(".For3:");
 // printf("\n loop3");
   asm volatile(  "cmp        %[tam_k], %[tam] \n\t"
                  "jl         .Mult   \n\t"
                  ::[tam_k]"r"(k),[tam]"r"(sizeA));

//-----------------------------------------
   asm volatile(".For2:");
         //printf("\n loop2");
                   k=0;
   asm volatile(  "cmp        %[tam_j], %[tam] \n\t"
                  "jl         .For3    \n\t"
                  ::[tam_j]"r"(j),[tam]"r"(sizeA));
                  i++;
                  fprintf(result_of_matriz, "%s","\n");
//-----------------------------------------
   asm volatile(".For1:");       // Primero laço do for
         //printf("\n loop");
                   j=0;
   asm volatile(  "cmp        %[tam_i], %[tam] \n\t"
                  "jl         .For2    \n\t"
                  ::[tam_i]"r"(i),[tam]"r"(sizeA));

   //fim da contagem do tempo
   fim = clock();

   // apresenta o resultado em segundos
   printf("\nO temp foi de %.2lf\n",((float)(fim - inicio)/CLOCKS_PER_SEC) ); 

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