# MultiplicacaoMatrizes-C-ComAssemblyPBL1-SD


## Informações
Esse código consiste em utilizar assembly inline para executar a multiplicação de matriz e apresenta o tempo em segundos no final da execução.

Há nessa pasta os arquivos para rodar esse código:
    mult.c  (aqui contém o código em C com a multiplicação de matrizes)
    mult.h  (Cabeçalho ou rótulo de uma função para que possamos buscar ao usao o #Include no arquivo main)
    multiplicar_matriz.c (aqui é onde iniciamos a matriz e a leitura dos arquivos)

# Para ultilizar esse código:
    1- Ter o gcc instalado, se linux utilize: sudo apt-get install gcc
    2- Makefile para facilitar a script de execução, visto que é gerado o código objeto de cada arquivo .c
       e linkando-os no final para gerar o executavel(esse mesmo nome é gerado)

## Passo para executar:
    1° Ter as pastas matrizes(onde estão as matrizes de entrada) e resultado(o resultado das multiplicação),
    gere a pasta se não tiver como comando "make pasta"

    2° Gerar as matrizes com extensão txt dentro do arquivo matrizes do arquivo, "gerarmatriz.c" e execute o
       comando "make matrizarq". 
       Caso queira criar outras matrizes de outros tamanho é necessário usar o comando "make deletarMatriz" ou deletar manualmente, editar o código gerarmatriz.c na variável "set" e por o seu número. Recompilar o código
       usando o primeiro comando.

    3° Verifique se o dentro do arquivo multiplicar_matriz.c o nome do arquivo de abertura é igual ao arquivo
        que está na pasta matrizes.

    4° execute os comando "make all" que ele irá gera o arquivo binário com o nome "executavel"

    5° digite o comando "make rodar" que irá executar o binário. 

## Depois da execução:
    O código era executar e quando acabar mostrar o tempo em segundos que levou para rodar o código da multiplicação
    Quando maior a matriz mais tempo irá levar
