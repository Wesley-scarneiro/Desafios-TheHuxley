/*
Descrição:
Leia um valor inteiro N. Depois, imprima uma mensagem dizendo que se este valor for ímpar, par, positivo, negativo ou nulo.
A mensagem deve estar em letras maiúsculas.

Formato de entrada:
Um número N.
Considere que o maior inteiro que você poderá receber é 10^12 (10 elevado a 12)

Formato de saída:
Uma frase, informando se o número é POSITIVO PAR, POSITIVO IMPAR, NEGATIVO PAR, NEGATIVO IMPAR ou NULO.
Seguido de uma quebra de linha.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Variavel
    long int n;
    
    // Entrada
    scanf("%ld", &n);
    
    // Analise do numero informado
    
    if (n > 0)
    {
        // numero par
        if (n % 2 == 0)
        {
            printf("POSITIVO PAR");
        }
        else
        {
            printf("POSITIVO IMPAR");
        }
    }
    else
    {   // Menor do que zero
        if (n != 0)
        {
            if (n % 2 == 0)
            {
                printf("NEGATIVO PAR");
            }
            else
            {
                printf("NEGATIVO IMPAR");
            }
        }
        else
        {
            printf("NULO");
        }
    }
    
	return 0;
}