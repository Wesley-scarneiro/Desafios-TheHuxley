/*
Descrição:
Faça um programa que leia um número inteiro e imprima o seu antecessor (inteiro anterior) e o seu sucessor (inteiro posterior).

Formato de entrada:
Um número inteiro.

Formato de saída:
O inteiro anterior e o sucessor, separados por um espaço.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int x, antecessor, sucessor;
    
    // Entrada
    scanf("%d", &x);
    
    // Operações
    antecessor = x-1;
    sucessor = x+1;
    
    // Resultado
    printf("%d %d", antecessor, sucessor);
    
	return 0;
}