#include <stdio.h>
#include <stdlib.h>
#include "mult.h"



void multiplicar(int **matrizA, int **matrizB, int sizeA, FILE *result_of_matriz){
  
    int soma=0, i=0, j=0,k=0, resposta=0;
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
                  k++;     // incremento do terceiro for             
   asm volatile(  "cmp        %[tam_k], %[tam] \n\t"
                  "jl         .Mult   \n\t"
                  ::[tam_k]"r"(k),[tam]"r"(sizeA));   
                  j++;
                  //printf("\nsoma depois: %d", a);
                  fprintf(result_of_matriz, "%d ", soma);
                  soma=0;
   asm volatile(  "jmp        .For2");
   asm volatile(".For3:");
   asm volatile(  "cmp        %[tam_k], %[tam] \n\t"
                  "jl         .Mult   \n\t"
                  ::[tam_k]"r"(k),[tam]"r"(sizeA));

   asm volatile(".For2:");
                   k=0;
   asm volatile(  "cmp        %[tam_j], %[tam] \n\t"
                  "jl         .For3    \n\t"
                  ::[tam_j]"r"(j),[tam]"r"(sizeA));
                  i++;
                  fprintf(result_of_matriz, "%s","\n");

   asm volatile(".For1:");       // Primero laço do for
                   j=0;
   asm volatile(  "cmp        %[tam_i], %[tam] \n\t"
                  "jl         .For2    \n\t"
                  ::[tam_i]"r"(i),[tam]"r"(sizeA));
} 