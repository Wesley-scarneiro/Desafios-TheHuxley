/*
Descrição:
Leia 3 valores, no caso variáveis A, B e C, que são as três notas de um aluno. A seguir, calcule a média do aluno, sabendo que a nota A tem peso 2, a nota B tem peso 3 e a nota C tem peso 5. Considere que cada nota pode ir de 0 até 10.0, sempre com uma casa decimal.

Formato de entrada:
O arquivo de entrada contém 3 valores com uma casa decimal.

Formato de saída:
Você deve imprimir a string "MEDIA = " seguida do valor da média ponderada. Olhe o exemplo de entrada e saída para ter certeza do formato. O valor da média deve possuir apenas um dígito após o ponto decimal.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Declarando variaveis - tipo double
    double notaA, notaB, notaC, media;
    
    // Entranda
    scanf("%lf%lf%lf", &notaA, &notaB, &notaC);
    
    // Calculos
    media = (notaA*2+notaB*3+notaC*5)/10;
    
    // Saida
    printf("MEDIA = %.1lf", media);
    
	return 0;
}