/*
Descrição:
Escreva um programa que calcule a soma de duas frações, fornecendo o resultado em forma de fração, seu programa deve verificar se as frações são válidas.

Formato de entrada:
Consiste de quatro números inteiros da forma a/b + c/d

Formato de saída:
Consiste de uma fração no formato a/b seguida por um fim de linha.
Deve imprimr "entrada invalida!" caso uma das frações tenha denominador 0.
A saída deve ser simplificada. Por exemplo, se o resultado for 9/6, você deve imprimir 3/2. Entretanto, se o resultado for 2/1, o resultado deve continuar sendo 2/1 e não 2.
obs:Imprimir sem as aspas.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
	Dado uma fracao qualquer, esta funcao busca encontrar o MDC entre um numerador e denominador dado.
*/
void fracaoIrredutivel(int numerador, int denominador)
{
	// Variaveis para auxilio no calculo do MDC
	int dividendo, divisor, resto, mdc;
	
	if (numerador >= denominador)
	{
		// Guardando o primeiro resto da divisao
		resto = numerador % denominador;
		
		// Se o resto = 0, o numerador eh um multiplo do denominador e portanto, o denominador = MDC
		if (resto == 0)
		{
			// MDC = denominador
			mdc = denominador;
			
			// Simplificando as fracoes
			numerador   = numerador / mdc;
			denominador = denominador / mdc;
			
			// Saida
			printf("%d/%d\n", numerador, denominador);
		}
		// Se resto != 0, o 'proximo dividendo' sera o 'divisor anterior' e o 'proximo divisor' o 'resto anterior'
		else
		{
			dividendo = denominador;
			divisor   = resto;
			
			// O divisor que gerar um resto = 0, sera o MDC procurado para a fracao
			while (resto != 0)
			{
				// O divisor deve guardar o resto atual, antes da atualizacao
				divisor = resto;
				
				// Proximo resto
				resto = dividendo % divisor;
				
				// Proximo dividendo
				dividendo = divisor;
				
			}
			
			// Se o loop termina, entao o divisor encontrado eh o MDC
			mdc = divisor;
			
			// Simplificando as fracoes
			numerador   = numerador / mdc;
			denominador = denominador / mdc;
			
			// Saida
			printf("%d/%d\n", numerador, denominador);
		}
		
	}
	// (denominador > numerador e != 0)
	else if (numerador != 0)
	{
		// Guardando o primeiro resto da divisao
		resto = denominador % numerador;
		
		// O denominador eh um multiplo do numerador e portanto, o numerador = MDC
		if (resto == 0)
		{
			// O MDC = numerador
			mdc = numerador;
			
			// Simplificando a fracao
			numerador 	= numerador / mdc;
			denominador = denominador / mdc;
			
			// Saida
			printf("%d/%d\n", numerador, denominador);
			
		}
		// Se resto != 0, o 'proximo dividendo' sera o 'divisor anterior' e o 'proximo divisor' o 'resto anterior'
		else
		{
			dividendo = numerador;
			divisor   = resto;
			
			// O divisor que gerar um resto = 0, ser� o MDC procurado para a fracao
			while (resto != 0)
			{
				// O divisor deve guardar o resto atual, antes da atualizacao
				divisor = resto;
				
				// Proximo resto
				resto = dividendo % divisor;
				
				// Proximo dividendo
				dividendo = divisor;
				
			}
			// Se o loop termina, entao o divisor encontrado eh o MDC
			mdc = divisor;
			
			// Simplificando as fracao
			numerador   = numerador / mdc;
			denominador = denominador / mdc;
			
			// Saida
			printf("%d/%d\n", numerador, denominador);
			
		}
	}
	// Para numerador = 0
	else
	{
		printf("%d/%d", numerador, denominador);
	}
	
}

int main() 
{
	// Variaveis
	int a, b, c, d, numerador, denominador;
	
	// Entrada: a/b e c/d
	scanf("%d/%d + %d/%d", &a, &b, &c, &d);

	if (b != 0 && d != 0)
	{
		if (b == d)
		{
			numerador   = a + c;
			denominador = b;
			
			// Saida
			fracaoIrredutivel(numerador, denominador);
		}
		else
		{
			numerador   = (a * d) + (c * b);
			denominador = b * d;
			
			// Saida
			fracaoIrredutivel(numerador, denominador);
		}
	}
	else
	{
		printf("entrada invalida!\n");
	}
	
	return 0;
}