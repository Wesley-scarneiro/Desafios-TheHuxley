/*
Descrição:
Um belo hotel na praia tem apartamentos especialmente decorados e cobra os valores indicados na tabela a seguir. Com o fim do verão, o movimento caiu e o hotel resolver oferecer 15% de desconto para hospedagens de 3 ou mais dias.
Tipo de Apartamento   Valor Diária
Individual            R$ 125
Suíte Dupla           R$ 140
Suíte Tripla          R$ 180
Escreva uma função chamada CalculaHospedagem que receba por parâmetro o tipo de apartamento desejado e a quantidade de diárias, e calcule e retorne o valor total a ser pago.

Formato de entrada:
Um string indicando o tipo de apartamento e um inteiro indicando a quantidade de dias.

Formato de saída:
Um valor float com duas casas decimais
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
    Funcao para calcular o total da diaria em um hotel.
*/
float calcularHospedagem(char tipo[13], int dias)
{
    float total = 0;
    
    // Individual
    if (tipo[0] == 'i')
    {
        if (dias >= 3)
        {
            return total = (125*dias) - (125*dias*0.15);
        }
        
        return total = 125*dias;
    }
    // Dupla
    else if (tipo[0] == 's' && tipo[7] == 'd')
    {
        if (dias >= 3)
        {
            return total = (140*dias) - (140*dias*0.15);
        }
        
        return total = 140*dias;
    }
    
    // tripla
    else if (tipo[0] == 's' && tipo[7] == 't')
    {
        if (dias >= 3)
        {
            return total = (180*dias) - (180*dias*0.15);
        }
        
        return total = 180*dias;
    }
    
	return total;
}


int main()
{
    
    /*
        Variaveis:
        tipo[11] - Guarda 11 caraceteres + '\0'
        dias - Quantidade de dias que ficarah no hotel
        total - Valor a ser pago para a hospedagem
    */
    char tipo[13];
    int dias;
    float total;
    
    gets(tipo);
    scanf("%d", &dias);
    
    int i;
    for (i = 0; tipo[i] != '\0'; ++i)
    {
    	tipo[i] = tolower(tipo[i]);
	}
    
    // Chamar funcao
    total = calcularHospedagem(tipo, dias);
    printf("%.2f\n", total);
    
    return 0;
}