/*
Descrição:
Dado um número n na base decimal, escreva uma função recursiva que converte este número para binário. 

Formato de entrada:
Um número inteiro decimal N (0 <= N <= 1.000.000.000)

Formato de saída:
O número N em binário, onde cada linha representa um algarismo binário (0 ou 1) do número transformado.
Obs.: cada linha representa um algarismo binário (0 ou 1) da esquerda para direita do número binário.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao que representa um numero em sua forma binaria.
*/
void binario(long int n)
{
    if (n > 1)
    {
        binario(n/2);
    }
    
    if (n == 1)
    {
        printf("%ld\n", n);
    }
    else
    {
        printf("%ld\n", n%2);
    }
}


int main() 
{
    long int n;
    scanf("%ld", &n);
    binario(n);
    
    return 0;
}