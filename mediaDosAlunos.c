/*
Descrição:
Faça um programa que leia três notas (valores reais) de um aluno, calcule sua média aritmética e imprima uma mensagem dizendo se o aluno foi aprovado, reprovado ou deverá fazer prova final. O critério de aprovação é o seguinte: 
Aprovado (média >= 7);
Reprovado (média < 3);
Prova final ( 3 <= média < 7).

Formato de entrada:
03 números reais separados por um final de linha.

Formato de saída:
Uma mensagem que pode ser: 
aprovado
reprovado
prova final
Dependendo da situação do aluno.
A saída deve terminar com uma quebra de linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Variaveis - tres notas
    double n1, n2, n3, media;
    
    // Entrada das notas
    scanf("%lf%lf%lf", &n1, &n2, &n3);
    
    // Calculo da media aritmetica simples
    media = (n1 + n2 + n3)/3;
    
    // Analise da media e resultados
    if (media >= 7)
    {
        printf("aprovado\n");
    }
    else
    {
        if (media >=3 && media < 7)
        {
            printf("prova final\n");
        }
        else
        {
            printf("reprovado\n");
        }
    }
    
	return 0;
}