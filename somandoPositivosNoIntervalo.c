/*
Descrição:
Escreva um programa que receba como entrada dois números inteiros e retorne a soma dos números positivos no intervalo definido por eles, considerando inclusive os extremos.
Obs: o intervalo pode ser crescente ou decrescente

Formato de entrada:
Dois números inteiros
Dica: os números podem ser informados em qualquer ordem (não necessariamente o primeiro será menor que o segundo)

Formato de saída:
Um número inteiro
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao recursiva para somar os numeros positivos de um intervalo numerico.
    Extremos positivos entrarao na soma.
*/
int somandoPositivos(int a, int b)
{
    if (a <= b)     // Intervalo crescente
    {
        if (a >= 0 )
        {
            if (a == b)     // Caso base
            {
                return a;   
            }
            else
            {
                return a + somandoPositivos(a+1, b);
            }
        }
        else
        {
            if (a == b)
            {
                return 0;       // Caso base
            }
            else
            {
                return somandoPositivos(a+1, b);
            }
        }
    }
    else            // Intervalo decrescente
    {
        return somandoPositivos(b, a);      // Convertendo para crescente
    }
}

int main() 
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", somandoPositivos(a, b));
    
    return 0;
}