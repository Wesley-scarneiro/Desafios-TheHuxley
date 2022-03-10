/*
Descrição:
Faça um programa que leia 3 números inteiros e imprima um (e apenas um) dos seguintes números:
1 (Se todos os números são iguais)
2 (Se todos os números são diferentes)
3 (Se apenas dois números são iguais)

Formato de entrada:
Consiste de 3 números inteiros.

Formato de saída:
Consiste de um número indicando uma das 3 situações de igualdade entre os valores de entrada conforme demonstrado na descrição
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    // Variaveis - inteiros
    int a, b, c;
    
    // Entrada
    scanf("%d%d%d", &a, &b, &c);
    
    /*
    1 - se todos os numeros sao iguais
    2 - se todos os numeros sao diferentes
    3 - se apenas dois numeros sao iguais
    */
    
    // Supondo dois numeros iguais
    if ((a == b || a == c) || b == c)
    {
        // Supondo tres numero iguais
        if (a == c)
        {
            printf("1\n");
        }
        // Somente dois iguais
        else
        {
            printf("3\n");
        }
        
    }
    // Todos os numeros sao diferentes
    else
    {
       printf("2\n"); 
    }
    
    return 0;
}