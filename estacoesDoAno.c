/*
Descrição:
As quatro estações do ano variam de acordo com as datas:
Primavera: 21 setembro até 20 dezembro
Verão: 21 dezembro até 20 março
Outono: 21 março até 20 junho
Inverno: 21 junho até 20 setembro
Escreva uma função chamada EstacaoAno que receba como entrada um dia e um mês e retorne o nome da estação correspondente.

Formato de entrada:
Dois valores inteiros, representando o dia e o mês nessa sequência

Formato de saída:
Um String em letras maiúsculas
Obs: Não use acento em VERAO
*/

#include <stdio.h>

/*
    Funcao para verificar a estacao climatica de uma data qualquer.
*/
void identificarEstacao(int dia, int mes)
{
	// VERAO
	if ((mes == 1 || mes == 2) || ((mes == 12 && dia >= 21) || (mes == 3 && dia <= 20)))
	{
		printf("VERAO\n");
	}
	
	// OUTONO
	else if ((mes == 4 || mes == 5) || ((mes == 3 && dia >= 21) || (mes == 6 && dia <= 20)))
	{
		printf("OUTONO\n");
	}
	
	// INVERNO
	else if ((mes == 7 || mes == 8) || ((mes == 6 && dia >= 21) || (mes == 9 && dia <= 20)))
	{
		printf("INVERNO\n");
	}
	
	// PRIMAVERA - SE AS TRES CONDICOES ANTERIORES FOREM FALSAS
	else
	{
		printf("PRIMAVERA\n");
	}
}

int main()
{
	// Variaveis
	int dia, mes;
	
	// Entrada
	scanf("%d %d", &dia, &mes);	
	
	// Chamar funcao
	identificarEstacao(dia, mes);
	
	return 0;
}