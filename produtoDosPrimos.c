/*
Descrição:
Dados 04 números inteiros, calcule o produto entre eles caso os 04 números digitados sejam números primos.
Se algum deles não for primo, imprima: SEM PRODUTO

Formato de entrada:
4 números inteiros

Formato de saída:
O resultado da multiplicação entre eles, caso os 04 sejam primos ou SEM PRODUTO, caso contrário.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao que veririca se um numero eh primo - 1 verdadeiro ou 0 falso.
*/
int verificarPrimo(int n)
{
	int i, resultado;
	
	// 0 e +-1 nao sao primos
	if (n <= 0 || n == 1)
	{
		return 0;
	}
	
	/*
		Um n?mero n?o ? primo, se ele for divis?vel por algum n?mero entre 2 e (n-1)
	*/
	
	for (i = 2; i <= (n-1); ++i)
	{
		// Se o resto ? zero, ent?o n n?o ? primo
		if (n % i == 0)
		{
			return 0;
		}
	}
	
	// Se n?o ocorreu retorno no 'for', ent?o ? primo
	return resultado = 1;
}


int main() 
{
	// Vari?veis
    int entrada, produto, primo, i;
	
	// Valor inicial
	produto = 1;
	primo  = 0;
	
	// Recebendo 4 n?meros e fazendo o produto entre eles
	for (i = 1; i <= 4; ++i)
	{
		// Entrada
		scanf("%d", &entrada);
		
		// Realizando produto
		produto = produto * entrada;
		
		// Verificando se ? primo e relizando a soma
		primo = primo + verificarPrimo(entrada);
	}
	
	// Quando primo == 4, significa que todos os 4 n?meros foram primos
	if (primo == 4)
	{
		printf("%d\n", produto);
	}
	else
	{
		printf("SEM PRODUTO\n");
	}
	
	return 0;
}