/*
Descrição:
O Carnaval é um feriado celebrado normalmente em fevereiro, em muitas cidades brasileiras,
a principal atração são os desfiles de escolas de samba. As várias agremiações desfilam ao
som de seus sambas-enredos e são julgadas pela liga das escolas de samba para determinar
a campeã do Carnaval.
Cada agremiação é avaliada em vários quesitos; em cada quesito, cada escola recebe cinco
notas que variam de 5,0 a 10,0. A nota final da escola em um dado quesito é a soma das
três notas centrais recebidas pela escola, excluindo a maior e a menor das cinco notas.
Como existem muitas escolas de samba e muitos quesitos, o presidente da liga pediu que
você escrevesse um programa que, dadas as notas da agremiação, calcula a sua nota final
num dado quesito.

Formato de entrada:
A entrada contém uma única linha, contendo cinco números Ni (1 <= i <= 5), todos com uma
casa decimal, indicando as notas recebidas pela agremiação em um dos quesitos.
Considere:
5.0 <= Ni <= 10.0

Formato de saída:
Seu programa deve imprimir uma única linha, contendo um único número com exatamente
uma casa decimal, a nota final da escola de samba no quesito considerado.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    float nota[5], menor, maior, notaFinal;
    int i;
    
    scanf("%f %f %f %f %f", &nota[0], &nota[1], &nota[2], &nota[3], &nota[4]);
    
    // Hipotese
    menor = nota[0];
    maior = nota[4];
    
    // Encontrando a menor e maior nota
    for (i = 1; i < 5; ++i)
    {
        // Buscando a menor nota entre as informadas
        if (nota[i] < menor)
        {
            menor = nota[i];
        }
        
        if (nota[4 - i] > maior)
        {
            maior = nota[4 - i];
        }
    }
    
    // Soma das notas menos o maior e menor
    notaFinal = nota[0] + nota[1] + nota[2] +  nota[3] + nota[4] - (maior + menor);
    
    printf("%.1f\n", notaFinal);
    
	return 0;
}