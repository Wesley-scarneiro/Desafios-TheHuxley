/*
Descrição:
João e Maria são dois irmãos muito briguentos. Um belo dia, o pai deles, o Sr. Carlos, comprou várias figurinhas do álbum da copa. João disse que por ser menino tinha direito a mais figurinhas. Obviamente, Maria não concordou e propôs um acordo de risco. Eles iriam dividir as figurinhas da seguinte maneira:
João ficaria com todas as figurinhas cujo número de série for par e Maria com as ímpares. O Sr. Carlos gostou da idéia e propôs um pequeno bônus:
- Aquele que obtivesse o maior valor somando os números de séries das figurinhas ganharia como bônus mais R$10,00 reais para comprar figurinhas só para ele.

Formato de entrada:
Consiste de um número inteiro n indicando a quantidade de figurinhas a serem lidas, seguido de n inteiros correspondendo ao número de série de cada
figurinha. Todas as figurinhas possuem números de série diferentes. Note que as figurinhas podem ser repetidas. Neste caso, só devemos considerar na soma do número de série uma única vez, mas contamos na quantidade de figurinhas.
Considere:
 n <= 10.000
Cada inteiro <= 10.000

Formato de saída:
Consiste dos números inteiros J, M e S, indicando respectivamente, o número de figurinhas que ficaram com o João, o número de figurinhas que ficaram com Maria e a soma dos números de série do irmão que ganhou o bônus do Sr. Carlos.
Depois de cada número da saída coloque um final de linha.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao para verificar se ja existe um elemento guardado em um arranjo.
*/
int buscaRepetido(int arranjo[], int tamanho, int elemento)
{
    int i;
    int contador = 0;
    
    for (i = 0; i <= tamanho; ++i)
    {
        if (arranjo[i] == elemento)
        {
            ++contador;
        }
    }
    
    if (contador > 1)
    {
        return 1; 
    }
    else
    {
        return 0;
    }
}

int main() 
{
    // Variaveis
    int totalCartas, numSerie, totalSerieJ, totalSerieM, totalJ, totalM;
    int i, repetido;
    
    // Entrada - quantidade de cartas que ser?o informadas
    scanf("%d", &totalCartas);
    
    // Guardando as s?rie de castas de Joao e Maria
    int cartas[totalCartas];
    totalSerieJ = 0;
    totalSerieM = 0;
    totalJ = 0;
    totalM = 0;
    
    // Recebendo as series
    for (i = 0; i < totalCartas; i++)
    {
        // Recebendo as series
        scanf("%d", &numSerie);
        
        // contagem das series para o jo?o
        if (numSerie % 2 == 0)
        {
            // Guardando a serie
            cartas[i] = numSerie;
            ++totalJ;
            
            // Verifica se a carta ? repetida
            repetido = buscaRepetido(cartas, i, numSerie);
            
            if (repetido == 0) // 1 repetido, 0 nao repetido
            {
                totalSerieJ = totalSerieJ + numSerie;
            }
        }
        else // Contagem para Maria
        {
            // Guardando a serie
            cartas[i] = numSerie;
            ++totalM;
            
            // Verifica se a carta eh repetida
            repetido = buscaRepetido(cartas, i, numSerie);
            
            if (repetido == 0)
            {
                totalSerieM = totalSerieM + numSerie;
            }
        }
    }
    
    // Verificando o ganhador
    if (totalSerieJ > totalSerieM)
    {
        printf("%d\n%d\n%d\n", totalJ, totalM, totalSerieJ);
    }
    else
    {
        printf("%d\n%d\n%d\n", totalJ, totalM, totalSerieM);

    }
    
	return 0;
}