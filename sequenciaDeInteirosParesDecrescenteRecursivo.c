/*
Descrição:
Faça uma função recursiva que receba um número inteiro positivo par N e imprima todos os números pares de 0 até N em ordem decrescente.

Formato de entrada:
Um inteiro positivo N.

Formato de saída:
Uma sequência de pares de 0 a N linha à linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao que imprime todos os pares entre '0' e 'n'
    de forma decrescente.
*/
void paresD(int n, int i, int j)
{
    if (n % 2 == 0)
    {
        printf("%d\n", n-i);
        if (i < n) return paresD(n, i+2, j);
    }
    else
    {
        printf("%d\n", n-j);
        if (j < n) return paresD(n, i, j+2);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    paresD(n, 0, 1);
    
    
	return 0;
}