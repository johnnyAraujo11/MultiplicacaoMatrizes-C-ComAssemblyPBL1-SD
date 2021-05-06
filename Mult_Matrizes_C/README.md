# MultiplicacaoMatrizes-C-ComAssemblyPBL1-SD

## Código apenas em linguagem C
    Esse codigo executa e faz a multiplicação de matrizes e apresenta o tempo em segundos.

## Passo para executar:

    1° Ter as pastas matrizes(onde estão as matrizes de entrada) e resultado(o resultado das multiplicação),
    gere a pasta se não tiver com comando "make pasta"

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
    Quando maior a matriz maior o tempo irá levar.
