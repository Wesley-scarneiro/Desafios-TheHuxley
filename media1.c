/*
Descrição:
Leia 2 valores de ponto flutuante de dupla precisão A e B, que correspondem a 2 notas de um aluno. A seguir, calcule a média do aluno, sabendo que a nota A tem peso 3.5 e a nota B tem peso 7.5 (A soma dos pesos portanto é 11). Assuma que cada nota pode ir de 0 até 10.0, sempre com uma casa decimal.

Formato de entrada:
O arquivo de entrada contém 2 valores com uma casa decimal cada um.

Formato de saída:
Calcule e imprima a variável MEDIA conforme exemplo abaixo, com 5 dígitos após o ponto decimal. Utilize variáveis de dupla precisão (double) e como todos os problemas, não esqueça de imprimir o fim de linha após o resultado.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    // Variaveis - tipo double
    double a, b, media;
    
    // Entrada
    scanf("%lf%lf", &a, &b);
    
    // Calculo
    media = (a*3.5+b*7.5)/11;
    
    // Saida
    printf("MEDIA = %.5lf\n", media);
    
	return 0;
}