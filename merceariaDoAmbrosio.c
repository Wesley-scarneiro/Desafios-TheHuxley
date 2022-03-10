/*
Descrição:
Ambrósio é amigo da vizinhança e resolveu dar descontos para agradar seus clientes. A mercearia de Ambrósio contém apenas 04 itens, cujos preços são dados pela tabela abaixo:
A regra de desconto é bem simples: se a quantidade de produtos comprados for igual ou maior que quinze, então o desconto é concedido. O desconto também é concedido caso o valor total da compra seja maior ou igual a 40 reais.
O valor do desconto é de 15%.
Sua missão é fazer um programa que leia o código do produto, a quantidade comprada e imprima o valor que o cliente deve pagar, já considerando o desconto quando aplicável.
Considere que o cliente só pode comprar um único tipo produto cada vez que usar o seu software.

Formato de entrada:
Um número inteiro correspondendo ao código do produto, seguido de um inteiro indicando a quantidade comprada.
Os inteiros são separados por um final de linha.

Formato de saída:
A saída deve conter o seguinte formato:
R$ x
Onde x corresponde a um número real formatado com duas casas decimais, indicando o valor a ser pago pelo cliente.
A sua saída deve ser seguida de um final de linha.
Obs.: perceba que existe um espaço entre o $ e o número x.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Variaveis
    int codigo, quantidade;
    double total;
    
    // Entrada do codigo e quantidade do produto
    scanf("%d%d", &codigo, &quantidade);
    
    // Identificao do produto comprado e do valor total
    if (codigo == 1)
    {
        total = quantidade * 5.30;
    }
    else if (codigo == 2)
    {
        total = quantidade * 6.0;
    }
    else if (codigo == 3)
    {
        total = quantidade * 3.20;
    }
    else // codigo 4
    {
        total =  quantidade * 2.50;
    }
    
    // Concessao do desconto
    if (quantidade >= 15 || total >= 40)
    {
        // Desconto de 15%
        total = total - (total * 0.15);
        
        printf("R$ %.2lf\n", total);
    }
    else
    {
        printf("R$ %.2lf\n", total);
    }
    
    return 0;
}