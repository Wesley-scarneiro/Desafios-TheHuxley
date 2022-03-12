/*
Descrição:
Dois números naturais sempre têm divisores comuns. Por exemplo: os divisores comuns de 12 e 18 são 1,2,3 e 6. Dentre eles, 6 é o maior. Então chamamos o 6 de máximo divisor comum de 12 e 18 e indicamos m.d.c.(12,18) = 6.
Desenvolva uma função recursiva para calcular o m.d.c de dois inteiros.

Formato de entrada:
Dois inteiros positivos.

Formato de saída:
Um inteiro positivo.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao recursiva para calcular o MDC de dois numeros.
    Eh utilizado o algoritmo de Euclides.
*/
int mdc(int a, int b)
{
    if (a > b)
    {
        int r = a % b;
        if (r == 0) return b;
        else return mdc(b, r);
    }
    else
    {
        int r = b % a;
        if (r == 0) return a;
        else return mdc(a, r);
    }
}

int main() 
{
        
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", mdc(a,b));
        
	return 0;
}