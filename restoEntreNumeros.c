/*
Descrição:
Escreva um programa leia 2 valores X e Y e que imprima todos os valores entre eles cujo resto da divisão dele por 5 for igual a 2 ou igual a 3.

Formato de entrada:
Contém 2 valores inteiros quaisquer, não necessariamente em ordem crescente.

Formato de saída:
Todos os inteiros entre x e y, um por linha, em ordem crescente, que satisfazem o enunciado deste problema.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Variaveis
    int x, y, i;
    
    // Entrada
    scanf("%d%d", &x, &y);
    
    // Verificando se a entrada foi dada em ordem crescente
    if (x > y)
    {
        float temp = y;
        y = x;
        x = temp;
    }
    
    // Percorrendo todos os numeros entre x e y
    for (i = x + 1; i < y; ++i)
    {
        // Verificando condicoes de saida dos numeros
        if ((i % 5 == 3) || (i % 5 == 2))
        {
            printf("%d\n", i);
        }
    }
    
	return 0;
}