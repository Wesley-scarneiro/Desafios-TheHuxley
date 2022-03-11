/*
Descrição:
Leia uma sequência de 101 números inteiros , verifique se o último número está presente nos 100 primeiros números e imprima as posições do array em que ele está presente.

Formato de entrada:
Uma sequência de 101 números inteiros

Formato de saída:
Uma sequência de inteiros separados por um final de linha, onde cada inteiro representa a posição do array em que foi encontrado o último número lido.
Se o último número não for encontrado nos 100 números anteriores não imprima nada
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TAM 101

/*
    Funcao para verificar se o elemento na posicao 100 aparece nas outras 99 posicao.
*/
void procurarUltimo(int array[])
{
    int i;
    
    for (i = 0; i < 100; ++i)
    {
        if (array[100] == array[i])
        {
            printf("%d\n", i);
        }
    }
}

int main() 
{
    // Variaveis
    int array[TAM], i;
    
    // Entrada dos 101 numeros
    for (i = 0; i < TAM; ++i)
    {
        scanf("%d", &array[i]);
    }
    
    // Chamar funcao
    procurarUltimo(array);
    
    return 0;
}