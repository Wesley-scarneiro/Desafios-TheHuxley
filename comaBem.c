/*
Descrição:
Faça um programa que leia um valor representando o gasto realizado por um cliente do restaurante COMABEM e imprima o valor total a ser pago, considerando os 10% do garçom.

Formato de entrada:
Consiste de um número real representando o valor gasto do cliente.

Formato de saída:
Consiste de um número real com duas casas decimais representando o total a ser pago considerando os 10% do garçom.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    // Variaeis - tipo real
    float gasto, total;
    
    // Entrada
    scanf("%f", &gasto);
    
    // Calculo
    total = gasto + 0.1*gasto;
    
    // Saida, com duas casas decimais
    printf("%.2f", total);
    
	return 0;
}