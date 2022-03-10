/*
Descrição
Guido é um cientista, ele foi chamado para resolver um problema da usina do senhor Ambrósio. Senhor Ambrósio quer construir uma usina de tratamento de água onde o aproveitamento do espaço seja o melhor possível. Ele lhe deu uma folha que contém o raio dos locais onde pretende fazer os tanques redondos.
Ele espera receber de Guido dados que contenham a área de cada tanque o qual lhe deu o raio.
Porém Guido está muito atarefado e pediu sua ajuda para fazer um programa que possa calcular a área de cada tanque de forma mais rápida.
Considerando que para este problema π = 3.14159. 
- Efetue o cálculo da área.

Formato de entrada:
A entrada contém um valor de ponto flutuante que simboliza o raio. 
Obs.: O raio é dado em cm.

Formato de saída:
Apresentar a mensagem “Area = ” seguido pelo valor da variável área dada em m², conforme exemplo de saída, com 4 casas após o ponto decimal. Preste atenção nas unidades de medida usadas nos cálculos. Não esqueça de imprimir o fim de linha após o resultado.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    // Variáveis - Numéro Real
    double r, area;
    
    // Entrada - em centímetros(cm)
    scanf("%lf", &r);
    
    // Cálculo - converter medida para metros(m)
    area = 3.14159*(r/100)*(r/100);
    
    // Saída - 4 casas decimais
    printf("Area = %.4lf\n", area);
    
	return 0;
}