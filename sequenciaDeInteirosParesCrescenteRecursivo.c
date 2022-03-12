/*
Descrição:
Faça uma função recursiva que receba um número inteiro positivo par N e imprima todos os números pares de 0 até N em ordem crescente. 

Formato de entrada:
Um inteiro positivo N.

Formato de saída:
Uma sequência de números de 0 à N linha à linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao que imprime todos os numeros pares entre '0' e 'n'.
*/
void imprimePares(int n, int i)
{
    printf("%d\n", n-i);
    if (i > 1) return imprimePares(n, i-2);
}

int main() 
{
    int n;
    scanf("%d", &n);
    imprimePares(n, n);
    
    return 0;
}