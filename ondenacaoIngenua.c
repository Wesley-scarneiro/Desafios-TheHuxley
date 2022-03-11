/*
Descrição:
Dado um conjunto de n valores inteiros, ordene-os em ordem crescente.

Formato de entrada:
Um inteiro n indicando quantos números serão fornecidos, seguidos de n inteiros separados por um final de linha

Formato de saída:
A sequência de n números ordenada em ordem crescente, obedecendo ao seguinte formato:
[numero][numero][numero][numero]
Onde depois do último número existe um final de linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao para ordenar um array.
    A funcao comeca buscando o menor valor e o guarda em array[0].
    Depois eh buscado o segundo menor valor para ser guardado em array[1] 
    e assim sucessivamente ate o array[tamanho-1].
    Em outras palavras, o algoritmo representado eh equivalente ao Selection Sort.
*/
void ordenarArray(int array[], int tamanho)
{
    int i, j,  maior;
    
    for (i = 0; i < (tamanho - 1); ++i)
    {
        // O segundo for busca o menor valor
        for (j = i + 1; j < tamanho; ++j)
        {
            if (array[i] > array[j])
            {
                maior = array[i];
                array[i] = array[j];    // Guardando o menor
                array[j] = maior;       // Guardando o maior
            }
        }
    }
}

/*
    Funcao para imprimir o array.
*/
void imprimirArray(int array[], int tamanho)
{
    int i;
    
    for (i = 0; i < tamanho; ++i)
    {
        // recebendo os numeros
        printf("[%d]", array[i]);
    }
    
    printf("\n");
}

int main() 
{
    // 'n' eh a quantidade de numeros fornecidos
    int n, i;
    
    // Entrada
    scanf("%d", &n);
    
    // Array para guardar os numeros que serao fornecidos
    int array[n];
    
    for (i = 0; i < n; ++i)
    {
        // recebendo os numeros
        scanf("%d", &array[i]);
    }
    
    // Chamar funcao para imprimir o array ordenado
    ordenarArray(array, n);
    
    // imprimindo array
    imprimirArray(array, n);
    
    return 0;
}