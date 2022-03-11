/*
Descrição:
Na matemática é comum o uso de matrizes de números. Estas matrizes podem ser utilizadas para vários fins e a álgebra linear fornece a teoria necessária à sua manipulação.
Dada uma matriz 4 X 4, você deve fazer um programa para ler uma constante k, ler a matriz e escrevê-la após ter multiplicado os elementos da diagonal principal pela constante k.

Formato de entrada:
- Um inteiro k
- 16 inteiros, correspondendo aos elementos da matriz.
Primeiro serão fornecidos os elementos da primeira coluna, depois da segunda e assim por diante até a quarta.
A entrada termina quando k for igual a 0

Formato de saída:
Você deverá imprimir a matriz resultante no formato de matriz, onde os elementos da primeira linha aparecerão lado a lado, separados por um espaço (deve haver inclusive um espaço depois do último elemento de cada linha).
Cada linha da matriz será separada por um final de linha, inclusive depois da última.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Matriz quadrada
#define LIN 4
#define COL 4

/*
    Funcao que recebe os elementos de uma matriz quadrada.
*/
void receberMatriz(int m[LIN][COL])
{
    int i, j;
    
    // Rebendo os elementos em colunas
    for (j = 0; j < COL; ++j)
    {
        for (i = 0; i < LIN; ++i)
        {
            scanf("%d", &m[i][j]);
        }
    }
}

/*
    Funcao que percorre a diagonal principal e multiplica os elementos dela por k.
*/
void diagonalP(int array[LIN][COL], int k)
{
    int i, j;
    
    i = 0;
    j = 0;
    
    while (i < LIN)
    {
        array[i][j] *= k;
        ++i;
        ++j;
    }
    
    // Imprimindo a matriz
    for (i = 0; i < LIN; ++i)
    {
        for (j = 0; j < COL; ++j)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int matriz[LIN][COL], k;
    
    // Primeira entrada
    scanf("%d", &k);
    
    while (k != 0)
    {
        // Recebendo os elementos da matriz
        receberMatriz(matriz);
        
        // Multiplicar a diagonal principal por k e imprimir a matriz
        diagonalP(matriz, k);
        
        // Nova entrada do k
        scanf("%d", &k);
    }
    
    return 0;
}