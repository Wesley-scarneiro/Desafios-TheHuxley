/*
Descrição:
Fazer um programa para ler uma string e calcular seu tamanho (número de caracteres). Exemplo: Seja a string "o rato", então seu tamanho é 6.

Formato de entrada:
Uma string com no mínimo 1 caracter e no máximo 500.

Formato de saída:
Um inteiro indicando a quantidade de caracteres da string.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Dimensao da String
#define MAX 500

int main() 
{
    // Variaveis
    int i, cont;
    
    // + '\0'
    char frase[MAX+1];
    
    // Entrada
    fgets(frase, (MAX+1), stdin);
    
    cont = 0;
    
    for (i = 0; frase[i] != '\0'; ++i)
    {
        // '\n' eh o ENTER que sera desconsiderado
        if (frase[i] != '\n')
        {
            ++cont;
        }
    }
    
    printf("%d\n", cont);
    
    return 0;
}