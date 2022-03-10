/*
Descrição:
Toda apresentação de trabalho tem seus requisitos mínimos, que precisam ser atendidos, caso contrário, o trabalho não é aceito e o aluno fica com nota 0.
A apresentação de Programação 1 está chegando, e o Professor Baldoino deixou claro que se os trabalhos não passassem por todos os requisitos mínimos, ele não iria julgar o trabalho.
Eis os requisitos:
Requisito 1: Inferface gráfica OU Inteligência Artificial.
Requisito 2: Encapsulamento E Indentação.
Requisito 3: Uso de Structs
Dada a entrada, descubra se o aluno ficou com 0 ou o seu trabalho será avaliado.

Formato de entrada:
A entrada é composta de 5 números, representando respectivamente Interface Gráfica, Inteligência Artificial, Encapsulamento, Indentação e Structs.
Os números podem ser:
0 - Se o trabalho não possui tal quesito.
1 - Se o trabalho possui tal quesito.

Formato de saída:
Deve imprimir o número 0, se o aluno não atender aos requisistos e ficará com zero, e a frase "AVALIADO" se ele atendeu aos requisitos mínimos.
Seguidos de uma quebra de linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    /*  VARIÁEIS QUE REPRESENTAM CADA ITEM DE UM REQUISITO

        Requisito 1: 
            a = Interface gráfica 
            b = Inteligência artificial
    
        Requisito 2: 
            c = Encapsulamento
            d = Indentação
            
        Requisito 3: 
            e = Structs
    */
    int a, b, c, d, e;
    
    // Entrada
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    
    // Soma de todos os itens dos requisitos
    int soma = a + b + c + d + e;
    
    // Se todos os itens do requisito 1 forem atentidos
    if (a + b == 2)
    {
        // Requisitos 2 e 3 completamente atendidos
        if (soma == 5)
        {
            printf("AVALIADO\n");
        }
        else
        {
            printf("%d\n", 0);
        }
    }
    else
    {
        // Requisito 1 parcialmente atendido e requisitos 2 e 3 completamente atendidos
        if (soma == 4)
        {
            printf("AVALIADO\n");
        }
        else
        {
            printf("%d\n", 0);
        }
    }
    
	return 0;
}