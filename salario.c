/*
Descrição:
Escreva um programa que leia o número de um funcionário, seu número de horas trabalhadas, o valor que recebe por hora e calcula o salário desse funcionário. A seguir, mostre o número e o salário do funcionário, com duas casas decimais.

Formato de entrada:
O arquivo de entrada contém 2 números inteiros e 1 número com duas casas decimais, representando o número, quantidade de horas trabalhadas e o valor que o funcionário recebe por hora trabalhada, respectivamente.

Formato de saída:
Imprima o número e o salário do funcionário, conforme exemplo fornecido, com um espaço em branco antes e depois da igualdade. No caso do salário, também deve haver um espaço em branco após o $.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Variaveis
    int idFuncionario, horasTrabalhadas;
    double valorHora, salario;
    
    // Entrada
    scanf("%d%d%lf%lf", &idFuncionario, &horasTrabalhadas, &valorHora, &salario);
    
    // Calculo
    salario = horasTrabalhadas*valorHora;
    
    // Saida
    printf("NUMBER = %d\nSALARY = R$ %.2lf\n", idFuncionario, salario);
    
	return 0;
}