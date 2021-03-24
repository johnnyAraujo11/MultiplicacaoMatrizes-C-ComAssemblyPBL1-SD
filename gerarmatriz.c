#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void  add_values_in_file();
int ramdom_int();

int main(){  
    int set = 1000;  
    FILE *fileA, *fileB;

    // Necessário para que sempre seja gerado um número novo na função rand()
    srand(time(NULL));
    
    //abrir arquivo se existir, não existindo cria-o
    fileA = fopen("./matrizes/matrizA5000.txt", "w");
    fileB = fopen("./matrizes/matrizB5000.txt", "w");
   
    //adicionar a dimesão da matriz na primeira linha do arquivo
    fprintf(fileA,"%d%s",set,"\n");
    fprintf(fileB, "%d%s", set,"\n");
   
       
    add_values_in_file(set, fileA);
    add_values_in_file(set, fileB);

    //fechamento do arquivo
    fclose(fileA);
    fclose(fileB);
    return 0;
}


void add_values_in_file( int set, FILE *file){
    int getRamdom;    
    
    for (int i=0; i < set; i++){
        for (int j=0; j < set; j++){
            //gravar o número no arquivo 
            fprintf(file, "%d ", ramdom_int());
        }
        //adicionar um quebra de linha após um linha da matriz
         fprintf(file, "%s", "\n");
    }
}


int ramdom_int(){
    int result;
    if(rand() % 2 == 0){
        //gerar número positivo
        result = rand() % 100;
    } else{
        //gerar número negativo
        result = rand() % 100 + (-100);
    } 
    return result;
}


