/*
Descrição:
Fila de banco é sempre uma dor de cabeça. No Banco do Brasilo, existem apenas dois caixas para atender as pessoas. Porém, toda hora do almoço é um problema, pois existem duas filas de pessoas e um dos funcionários precisa ir comer. Então, as duas filas precisam ser integradas. Sempre dá confusão. Para minimizar o problema, o gerente do banco, muito sovina, ao invés de contratar mais um funcionário, propôs a seguinte solução. As pessoas da fila do funcionário que foi almoçar devem ser intercaladas com as pessoas da fila do funcionário que ficou trabalhando, a partir da segunda posição. E haja confusão!

Formato de entrada:
Consiste dos inteiros n, m e k (0<=n <=10000, 0<=m <=10000, 1<=k<=2) correspondendo, respectivamente, a quantidade de pessoas que existem em cada fila e qual foi à fila que o funcionário foi almoçar, sendo k=1 para a primeira fila e k=2 para a segunda fila. Seguidos de n inteiros representando as pessoas da primeira file e m inteiros representando as pessoas da segunda fila. Os inteiros nunca se repetem.

Formato de saída:
Consiste em uma sequência de inteiros, um em cada linha representando as pessoas da nova fila.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao para receber os elementos em cada arranjo.
*/
void receberElementos(int fila1[], int t1, int fila2[], int t2)
{
	int i;
	
	// Fila 1
	for (i = 0; i < t1; ++i)
	{
		scanf("%d", &fila1[i]);
	}
	
	// fila 2
	for (i = 0; i < t2; ++i)
	{
		scanf("%d", &fila2[i]);
	}
}

/*
	Funcao para intercalar duas arrays, com base em seus tamanhos.
	O array maior sempre ira ocupar as posicoes pares/impares, enquanto
	houverem elementos do menor array para serem alocados nas restantes.
	
	Quando os elementos do menor array acabam, entao os elementos do maior
	ocupam todas as posicoes possiveis.
	
	Os elementos do maior array sempre serao alocados primeiramente e por ultimo
	os do menor array.
	
	Se k = 1, entao o maior ficara nas posicoes impares. 
	Se k = 0, entao o maior ficara nas pares.
*/
void intercalarArrays(int maior[], int t1, int menor[], int t2, int k)
{
	int fila[t1 + t2], i;
	
	// Maior nos impares
	if (k == 1)
	{
		// Elementos do maior
		for (i = 0; i < t1; ++i)
		{
			// Enquanto houverem elementos do menor nos pares, o maior fica nas impares.
			if (i < t2)
			{
				fila[(2*i) + 1] = maior[i];
			}
			
			// Quando i > t2 o maior ocupa as restantes
			else
			{
				fila[i + t2] = maior[i];
			}
		}
		
		// elementos do menor
		for (i = 0; i < t2; ++i)
		{
			// Ocupa todas as pares
			fila[2*i] = menor[i];
		}
	}
	
	// Maior nos pares
	else
	{
		// Elementos do maior
		for (i = 0; i < t1; ++i)
		{
			// Enquanto houverem elementos do menor nas impares, o maior fica nas pares
			if (i < t2)
			{
				fila[2*i] = maior[i];
			}
			
			// Quando i > t2 o maior ocupa as posicoes restantes
			else
			{
				fila[i + t2] = maior[i];
			}
		}
		
		// Elementos do menor
		for (i = 0; i < t2; ++i)
		{
			// Fica nas impares
			fila[(2*i) + 1] = menor[i];
		}
	}
	
	// Imprimindo fila[]
	for (i = 0; i < (t1+t2); ++i)
	{
		printf("%d\n", fila[i]);	
	}
}

/*
    Funcao para gerar o resultado com base nas condicoes possiveis entre os tamanhos dos arrays.
*/
void resultado (int fila1[], int t1, int fila2[], int t2, int k)
{
	// Fila 1 eh maior ou igual
	if (t1 >= t2)
	{
		// Fila 1 na fila 2 - Maior nos impares = 1
		if (k == 1)
		{
			intercalarArrays(fila1, t1, fila2, t2, 1);
		}
		
		// Fila 2 na fila 1
		else
		{
			intercalarArrays(fila1, t1, fila2, t2, 0);
		}
	}
	
	// fila 2  eh maior
	else
	{
		// Fila 1 na fila 2 - Maior nos impares = 1
		if (k == 1)
		{
			intercalarArrays(fila2, t2, fila1, t1, 0);
		}
		
		// Fila 2 na fila 1
		else
		{
			intercalarArrays(fila2, t2, fila1, t1, 1);
		}
	}
}

int main() 
{
	// Variaveis
	int t1, t2, k;
	
	// Entrada de t1, t2 e k
	scanf("%d %d %d", &t1, &t2, &k);
	
	// arranjo de cada fila
	int fila1[t1], fila2[t2];
	
	// Funcao para receber os elementos de cada fila nas entradas
	receberElementos(fila1, t1, fila2, t2);
	
	// Funcao resultado
	resultado(fila1, t1, fila2, t2, k);
	
	return 0;
}