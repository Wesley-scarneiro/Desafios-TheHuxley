/*
Descrição:
Seu programa deve receber um vetor de N valores inteiros e imprimir na ordem inversa.

Formato de entrada:
Na primeira linha de entrada o programa recebe um valor inteiro N de entrada. A segunda linha contém N inteiros separados por espaço contendo os valores do array.

Formato de saída:
Uma linha contendo os números do vetor em ordem invertida separados por espaços em branco, seguida de um final de linha.
Depois do último número, não deve existir um espaço em branco.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Variaveis
    int n, i;
    
    // Entrada do tamanho do array
    scanf("%d", &n);
    
    // Definindo o array
    int array[n];
    
    // Recebendo os valores
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &array[i]);
    }
    
    // Imprimindo
    for (i = (n-1); i >= 0; --i)
    {
        if (i == 0)
        {
            printf("%d\n", array[i]);
            break;
        }
        
        printf("%d ", array[i]);
    }
    
    return 0;
}