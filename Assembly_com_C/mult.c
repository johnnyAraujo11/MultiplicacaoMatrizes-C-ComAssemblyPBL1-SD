#include <stdio.h>
#include <stdlib.h>
#include "mult.h"



void multiplicar(int **matrizA, int **matrizB, int sizeA, FILE *result_of_matriz){
  
    int soma=0, i=0, j=0,k=0, resposta=0;
   asm volatile("jmp .For1\n\t");  // salto para o label .For1
 
   asm volatile(".Mult:"); 
   asm volatile(  
                  //"imul      eax, edx\n\t" // faz a multiplicação 
                  "imul %[matrizB],       %[matrizA]\n\t"   //  matrizB = matrizA * matrizB;
                  "mov  %[resposta],      %[soma]\n\t"      //  resposta = soma;
                  "add  %[resposta],      %[matrizB]\n\t"   //  resposta = matrizB + resposta;
                  "mov  %[soma],          %[resposta]\n\t"  //  soma = resposta;
                  : [resposta] "=c" (resposta), [soma] "=o" (soma) //recebe o resultado
                  : [matrizA] "a" (matrizA[i][k]) , [matrizB] "b" (matrizB[k][j])//entrada
   );
                  k++;                                       // incremento do terceiro for o mais interno              
   asm volatile(  "cmp        %[tam_k], %[tam] \n\t"         //Compara a condição de saida k com o tamanho da matriz
                  "jl         .Mult   \n\t"                  // Pulo condicional salta quando o valor comparado acime é menor(k <sizeA)
                  ::[tam_k]"r"(k),[tam]"r"(sizeA));   
                  j++;                                       // incrementa o j condição de saída do segundo for
                  
                  fprintf(result_of_matriz, "%d ", soma);    // Escreve no arquivo o resulta soma da multiplicação   
                  soma=0;                                    // zera soma para que possa ser usada para a próxima sequência de soma
   asm volatile(  "jmp        .For2");                       // Pula para o .For2
   asm volatile(".For3:");                                   // Label. Pode ser chamada em outra parte do código
   asm volatile(  "cmp        %[tam_k], %[tam] \n\t"         // Compara o k com sizeA para saber se chegou ao limite da matriz
                  "jl         .Mult   \n\t"                  // Pula para a label que faz a multiplicação 
                  ::[tam_k]"r"(k),[tam]"r"(sizeA));

   asm volatile(".For2:");                                   // Label. Pode ser chamada em outra parte do código
                   k=0;                                      // Zera para percorrer a matriz novamente
   asm volatile(  "cmp        %[tam_j], %[tam] \n\t"         // Compara o j com sizeA para saber se chegou ao limite da matriz
                  "jl         .For3    \n\t"                 // Pula para label .For3
                  ::[tam_j]"r"(j),[tam]"r"(sizeA));
                  i++;                                       // Incrementa a variável do primeiro for(.For1)
                  fprintf(result_of_matriz, "%s","\n");      // Quebra de linha dentro do arquivo, indicando o número de colunas 

   asm volatile(".For1:");                                  // Primero laço do for há um salto na linha 10 para essa label
                   j=0;                                     // Zera o j do segundo for 
   asm volatile(  "cmp        %[tam_i], %[tam] \n\t"        // Compara o i com sizeA para saber se chegou ao limite da matriz
                  "jl         .For2    \n\t"                // Enquanto i menor que sizeA pula para o .For2
                  ::[tam_i]"r"(i),[tam]"r"(sizeA));
} 