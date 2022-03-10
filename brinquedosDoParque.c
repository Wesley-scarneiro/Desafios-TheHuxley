/*
Descrição:
Nos parques de diversão, alguns brinquedos tem idade e altura mínimas para poder andar neles.
O parque Ambrolândia possui 3 brinquedos que possuem essa limitação:
Barca Viking: 1,5m de altura e 12 anos.
Elevator of Death: 1,4m de altura e 14 anos.
Final Killer: 1,7m de altura ou 16 anos. 
Dada a altura e a idade de uma pessoa, faça um programa que identifique quantos brinquedos ele pode andar.

Formato de entrada:
Dois inteiros, F e I, representando a altura (em cm) e a idade, respectivamente.

Formato de saída:
O número de brinquedos que ele pode andar no parque, seguido de uma quebra de linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    // Variaeis - Altura, idade e soma
    int altura, idade, soma;
    
    // Entrada
    scanf("%d%d", &altura, &idade);
    
    // Quantidade de brinquedos que poderao ser utilizados
    soma = 0;
    
    // Verificao da altura e idade
    if (altura >= 150 && idade >= 12)
    {
        soma += 1;
    }
    if (altura >= 140 && idade >= 14)
    {
        soma += 1;
    }
    if (altura >= 170 || idade >= 16)
    {
        soma += 1;
    }
    
    // Retorno
    printf("%d\n", soma);
    
	return 0;
}