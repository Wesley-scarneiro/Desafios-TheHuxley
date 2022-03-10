/*
Descrição:
Faça um programa que leia 3 números inteiros e imprima o menor deles.

Formato de entrada:
03 números inteiros separados por um final de linha.

Formato de saída:
O menor dos números digitados.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int a, b, c, menor;
    scanf("%d%d%d", &a, &b, &c);
    menor = a;
    
    if(b < menor)
    {
        menor = b;
    }
    if (c < menor)
    {
        menor = c;
    }
    
    printf("%d\n",menor );
    
    return 0;
}