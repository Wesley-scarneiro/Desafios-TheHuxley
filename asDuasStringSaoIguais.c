/*
Descrição:
Leia duas strings e imprima "IGUAIS" caso elas sejam iguais e "DIFERENTES" caso sejam diferentes.

Formato de entrada:
Você receberá duas linhas, cada uma contendo uma string com no máximo 50 caracteres.

Formato de saída:
Você deve imprimir uma linha contendo a string "IGUAIS" ou "DIFERENTES".
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Tamanho das strings
#define T 50

/*
    Funcao que verifica se duas stings dadas sao iguais.
    Basta que um unico caractere diferente seja encontrado para
    que as strings sejam diferentes. Caso ao contrario, serao iguais.
*/
int verificar(char p1[T], char p2[T])
{
    int i;
    
    for (i = 0; p1[i] != '\0' || p2[i] != '\0'; ++i)
    {
        if(p1[i] != p2[i])
        {
            return 0;
        }
    }
    
    return 1;
}

int main() 
{
    // Variaveis
    char p1[T], p2[T];
    int resultado;
    
    // Entradas
    scanf("%s\n%s", p1, p2);

    // funcao
    resultado = verificar(p1, p2);
    
    if (resultado)
    {
        printf("IGUAIS\n");
    }
    else
    {
        printf("DIFERENTES\n");
    }
    
    return 0;
}