/*
Descrição:
Chama-se de quadrado mágico um arranjo, na forma de um quadrado, de N x N números inteiros tal que todas as linhas, colunas e diagonais têm a mesma soma.
Por exemplo, o quadrado abaixo
2 7 6
9 5 1
4 3 8
é um quadrado mágico de soma 15, pois todas as linhas (2 + 7 + 6 = 15, 9 + 5 + 1 = 15 e 4 + 3 + 8 = 15), colunas (2 + 9 + 4 = 15, 7 + 5 + 3 = 15 e 6 + 1 + 8 = 15) e diagonais (2 + 5 + 8 = 15 e 6 + 5 + 4 = 15) têm a mesma soma (15).
Escreva um programa que, dado um quadrado, determine se ele é magico ou não e qual a soma dele (caso seja mágico).

Formato de entrada:
A entrada contém um único conjunto de testes. A primeira linha da entrada de cada caso de teste contém um inteiro N (2 <= N <= 10). As N linhas seguintes contêm N inteiros cada, separados por exatamente um espaço em branco. Os inteiros dentro do quadrado são todos maiores que 0 (zero) e menores ou iguais a 1000.

Formato de saída:
Seu programa deve imprimir, na saída padrão, uma única linha com um inteiro representando a soma do quadrado mágico ou -1 caso o quadrado não seja mágico.
*/

/*
	Solucao refatorada em 10/03/2022.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao que cria uma matriz dinamicamente e retorna seu endereco.
*/
int** criarMatriz(int n)
{
    int i;
    int **matriz = (int**) malloc(sizeof(int*)*n);
    
    for (i = 0; i < n; ++i)
    {
        matriz[i] = (int*) malloc(sizeof(int)*n);
    }
    
    return matriz;
}

/*
    Funcao para desalocar a matriz.
*/
void desalocarMatriz(int **matriz, int n)
{
    int i;

    for(i = 0; i < n; ++i)
    {
        free(matriz[i]);
    }
    
    free(matriz);
    matriz = NULL;
}

/*
    Funcao para receber os elementos da matriz.
*/
void preencherMatriz(int **matriz, int n)
{
    int i, j;
    
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

/*
    Funcao que faz a soma das linhas de uma matriz.
    Se a soma de uma linha for diferente da anterior,
    eh retornado -1. 
    Caso ao contrario, eh retornado a soma.
*/
int somaLinhas(int **matriz, int n)
{
    int i, j, soma, temp;
    soma = 0;
    
    for (i = 0; i < n; ++i)
    {
        temp = soma;
        soma = 0;
        
        for (j = 0; j < n; ++j)
        {
            soma += matriz[i][j];
        }
        
        if (i != 0 && temp != soma)
        {
            return -1;
        }
    }
    
    return soma;
}

/*
    Funcao que faz a soma das colunas de uma matriz.
    Se a soma de uma coluna for diferente da anterior,
    eh retornado -1.
    Caso ao contrario, eh retornado a soma.
*/
int somaColunas(int **matriz, int n)
{
    int i, j, soma, temp;
    soma = 0;
    
    for (i = 0; i < n; ++i)
    {
        temp = soma;
        soma = 0;
        
        for (j = 0; j < n; ++j)
        {
            soma += matriz[j][i];
        }
        
        if (i != 0 && temp != soma)
        {
            return -1;
        }
    }
    
    return soma;
}

/*
    Funcao para somar as diagonais de uma matriz.
    Retorna -1 se a soma das diagonais forem diferentes.
    Caso ao contrario, retorna a soma.
*/
int somaDiagonais(int **matriz, int n)
{
    int i, j, soma1, soma2;
    
    soma1 = 0;
    soma2 = 0;
    
    // Diagonal principal
    i = 0;
    j = 0;
    
    while (i < n)
    {
        soma1 += matriz[i][j];
        ++i;
        ++j;
    }
    
    // Diagonal segundaria
    i = 0;
    j = n - 1;
    
    while (i < n)
    {
        soma2 += matriz[i][j];
        ++i;
        --j;
    }
    
    if (soma1 == soma2)
    {
        return soma1;
    }
    else
    {
        return -1;
    }
}

/*
    Funcao que verifica se a matriz resenta um quadrado magico.
    Retorna a soma se for um quadrado magico ou -1 se nao for.
    No fim, apaga a matriz recebida.
*/
int quadradoMagico(int **matriz, int n)
{
    // Variaveis para guardar o retorno das funcoes.
    int linha, coluna, diagonal;
    
    linha = somaLinhas(matriz, n);
    coluna = somaColunas(matriz, n);
    diagonal = somaDiagonais(matriz,n);

    // Liberando memoria
    desalocarMatriz(matriz, n);
    
    // Resultado
    if (linha == coluna && linha == diagonal)
    {
        return linha;
    }
    else
    {
        return -1;
    }
}

int main()
{
    // Tamanho da matriz
    int n;
    
    scanf("%d", &n);
    int** matriz = criarMatriz(n);
    
    // Recebendo os dados
    preencherMatriz(matriz, n);
    
    // Resultado
    printf("%d\n", quadradoMagico(matriz, n));
    
    return 0;
}