/*
Descrição:
Escreva uma função recursiva chamada ContaDigitosPares que receba como entrada um número e retorne a quantidade de dígitos pares que o compõem.
Ex: 234 tem 3 dígitos, mas apenas 2 são pares

Formato de entrada:
Um número inteiro

Formato de saída:
Um número inteiro
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao que conta a quantidade de digitos pares em um numero 'n'.
    Funcao recursiva.
*/
int digitosPares(int n)
{
    int d = n % 10;         // Ultimo digito
    int i = (n - d)/10;     // Numero sem o ultimo digito
    
    if (d % 2 == 0)
    {
        if (i != 0)
        {
            return 1 + digitosPares(i);
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (i != 0)
        {
            return digitosPares(i);
        }
        else
        {
            return 0;
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    printf("%d\n", digitosPares(n));
    
    return 0;
}