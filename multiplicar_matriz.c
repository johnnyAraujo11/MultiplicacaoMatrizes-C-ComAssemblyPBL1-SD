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
   float time;

   fileA = fopen("./matrizes/matrizA1000.txt", "r");
   fileB = fopen("./matrizes/matrizB1000.txt", "r");
   

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
  //abrir o arquivo para escrita
   result_of_matriz = fopen("./resultado/result_matriz.txt", "w");

   //pode ignorar esse cod aqui é so para lembrar de uma coisa
   /*
     
      for(int i=0;i<sizeA;i++){
	      for(int j=0;j<sizeA;j++){
		      for(int k=0;k<sizeA;k++){
			      __asm__(
				      "imul eax, edx\n\t" //faz a multiplicação do conteúdo de eax e edx e armazena em eax
	  			      : "=a" (resp) // eax armazena o resultado da multiplicação
				      : "r" (matrizA[i][k]) , "r" (matrizB[k][j]) 
			      );
              // asm volatile("mov %[aux] , [%[maa]]":[aux]"+r"(tt): [maa]"r"(&matrizA[k][i]));
              printf("\n i:%d j: %d k: %d", i,j,k);
              // printf("\nres: %d", resp);
			   soma +=resp;
		   }
         fprintf(result_of_matriz, "%d ", soma);
		   soma =0;
	   }
      fprintf(result_of_matriz, "%s","\n");
   
      }
 */
   
  
   int i=0,j=0,k=0;
   printf("\nsizea: %d", sizeA);
   int resposta=0, cont=0, soma=0, temp=0, a=0;
 


   inicio = clock();
  

   asm volatile("jmp .For1\n\t");
 
   asm volatile(".Mult:");
              // printf("\ni: %d j: %d k: %d", i,j,k );
                //Código da multiplicacao aquio
   asm volatile(  "imul       %[mA], %[mB]\n\t"
                  "add        %[acumular], %[resu] "
                  :"=r"(resposta), "=a" (soma)
                  :[mA]"r"(matrizA[i][k]), [mB]"r"(matrizB[k][j]), [acumular]"r"(soma), [resu]"r"(resposta));
                  a+=soma;
                  k++;

   asm volatile(  "cmp        %[tam_k], %[tam] \n\t"
                  "jl         .Mult   \n\t"
                  ::[tam_k]"r"(k),[tam]"r"(sizeA));   
                  j++;
                  //printf("\nsoma depois: %d", a);
                  fprintf(result_of_matriz, "%d ", a);
                  a=0;

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
   asm volatile(".For1:");
         //printf("\n loop");
                   j=0;
   asm volatile(  "cmp        %[tam_i], %[tam] \n\t"
                  "jl         .For2    \n\t"
                  ::[tam_i]"r"(i),[tam]"r"(sizeA));

   asm volatile("sair:");

 
 fim = clock();


   printf("\nO temp foi de %lu\n",((fim - inicio)/CLOCKS_PER_SEC) ); // resultado em segundos

   printf("\ncontador: %d", cont);


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