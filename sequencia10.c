/*
Descrição:
Faça um programa que leia uma sequência de 10 números e informe o total de ocorrências do último número lido.

Formato de entrada:
O programa receberá uma sequência de 10 números inteiros.

Formato de saída:
O numero X apareceu N vezes.
Onde X é o último número lido e N foi o número de vezes que esse número apareceu. A saída deve ser seguida de um final de linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao que conta quantas vezes um determinado elemento se encontra em uma sequencia de numeros.
    Imprime o resultado.
*/
void contarElemento(int array[], int tamanho, int elemento)
{
    int i, contador;
    
    contador = 0;
    
    for (i = 0; i < tamanho; ++i)
    {
        if (array[i] == elemento)
        {
            ++contador;
        }
    }
    
    // Saida
    printf("O numero %d apareceu %d vezes\n", elemento, contador);
}

int main() 
{
    // Entrada
    int array[10], i;
    
    // Enquanto nao for dada as 10 entradas
    for (i = 0; i < 10; ++i)
    {
        scanf("%d", &array[i]);
    }
    
    // Chamar funcao para contar quantas vezes array[9] aparece
    contarElemento(array, 10, array[9]);
    
    return 0;
}