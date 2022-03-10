/*
Descrição:
Escreva um programa que receba como entrada 5 números inteiros positivos, e exiba a soma dos fatoriais daqueles que são múltiplos de 3.

Formato de entrada:
Números inteiros

Formato de saída:
Um número inteiro
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao recursiva para calcular o fatorial de 'n'.
*/
int calcularFatorial(long int n)
{
    int resultado;
    
    if (n == 0 || n == 1)
    {
        resultado = 1;
    }
    else
    {
        // Chama a propria funcao - Recursividade
        resultado = n * calcularFatorial((n-1));
    }
    
    return resultado;
}

int main() 
{
    // Variaveis
    long int numero, resultado;
    int i;
    
    // Estado inicial
    resultado = 0;

    for (i = 1; i <= 5; ++i)
    {
        scanf("%ld", &numero);
        
        // chama funcao que calcula o fatorial
        if (numero % 3 == 0)
        {
            resultado =  resultado + calcularFatorial(numero);
        }
        
    }
    
    printf("%ld", resultado);
    
	return 0;
}