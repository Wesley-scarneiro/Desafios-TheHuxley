/*
Descrição:
Faça um programa que leia 3 números inteiros e os imprima em ordem decrescente.
Desafio: tente utilizar apenas 4 comandos if.

Formato de entrada:
Consiste de 3 números inteiros.

Formato de saída:
Consiste dos 3 números de entrada ordenados do maior para o menor.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() 
{
    // Variaveis
    int maior, medio, menor, temp;
    
    // Entrada
    scanf("%d%d%d", &maior, &medio, &menor);
    
    /*
        Supondo que os tres numeros recebidos representam, em ordem,
        o maior, medio e menor; entao trocaremos os valores dessas
        variaveis somente quando estivermos errados.
    */
    
    if (medio > maior)
    {
        temp  = maior;
        maior = medio;
        medio = temp;
    }
    
    if (menor > maior)
    {
        temp  = maior;
        maior = menor;
        menor = temp;
    }
    
    if (menor > medio)
    {
        temp  = medio;
        medio = menor;
        menor = temp;
    }
    
    // Saida
    printf("%d\n%d\n%d\n", maior, medio, menor);
    
	return 0;
}