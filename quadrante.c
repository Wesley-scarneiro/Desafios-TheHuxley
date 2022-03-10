/*
Descrição:
Escreva um programa para ler as coordenadas (X, Y) de um ponto no sistema cartesiano. E escrever à qual quadrante ele pertence. 

Formato de entrada:
Dois números inteiros.

Formato de saída:
Imprima o quadrante correspondente que estas coordenadas pertencem, que pode ser:
primeiro
segundo
terceiro
quarto
eixo x
eixo y
origem
Será eixo x quando a coordenada y for zero.
Será eixo y quando a coordenada x for zero.
Os outros basta achar a localização do ponto no plano cartesiano.
A saida deve ser seguida de uma quebra de linha.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Variaveis
    int x, y;
    
    // Entrada
    scanf("%d%d", &x, &y);

    if(x == 0 || y == 0)
    {
        // origem
        if (x == y) 
        {
            printf("origem\n");
        }
        else if (x == 0)
        {
            printf("eixo y\n");
        }
        else 
        {
            printf("eixo x\n");
        }
    }
    else
    {
        if (x > 0)
        {
            // Primeiro quadrante
            if (y > 0)
            {
                printf("primeiro\n");
            }
            // Quarto quadrante
            else
            {
                printf("quarto\n");
            }
        }
        // (x < 0)
        else
        {
            // Segundo quadrante
            if (y > 0)
            {
                printf("segundo\n");
            }
            // Terceiro quadrante
            else
            {
                printf("terceiro\n");
            }
        }
    }
    
	return 0;
}