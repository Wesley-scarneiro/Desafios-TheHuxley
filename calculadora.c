/*
Descrição:
Ambrósio está ficando craque em matemática e para provar suas habilidades resolveu fazer uma calculadora. A calculadora deve ser capaz de efetuar as 04 operações aritméticas (adição, subtração, multiplicação e divisão).

Formato de entrada:
Consiste de 02 números reais, um em cada linha, seguidos de um caractere representando a operação a ser executada. Depois, consiste de uma sequência de um número real seguido de um caractere, também um em cada linha. A entrada termina quando o caractere & for lido.
Perceba que sempre o último número lido deve ser ignorado, pois ele precede o caractere &.

Formato de saída:
Consiste em uma sequencia de números reais, um em cada linha, representando o resultado da operação escolhida. A partir do terceiro número lido, o resultado deve ser obtido utilizando-se o valor da operação anterior. Caso a operação não seja possível, deve ser impresso "operacao nao pode ser realizada". Os números devem ser impressos com 03 casas decimais.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// calculadora - Recebe dois numeros e a operacao a ser realizada.
double calcular(double n1, double n2, char operacao)
{
    double resultado = 0;
    
    if (operacao == '+')
    {
        return resultado = n1 + n2;
    }
    
    if (operacao == '-')
    {
        return resultado = n1 - n2;
    }
    
    if (operacao == '*')
    {
        return resultado = n1 * n2;
    }
    
    if (operacao == '/')
    {   
        return resultado = n1/n2;
    }
}

int main() 
{
    // Variaveis
    double num1, num2, resultado;
    char operacao;
    
    // Primeira entrada - Dois numeros
    scanf("%lf %lf", &num1, &num2);
    
    // Identificando a operacao - \n antes para evitar a entrada do enter
    scanf("\n%c", &operacao);
    
    // Evitando divisao por zero
    if (operacao == '/' && num2 == 0)
    {
        printf("operacao nao pode ser realizada\n");
    }
    else
    {
        // Primeiro resultado
        resultado = calcular(num1, num2, operacao);
        printf("%.3lf\n", resultado);
        
        // Proximas entradas
        scanf("%lf\n%c", &num2, &operacao);
        
        while (operacao != '&')
        {
            // Evitando divisao por zero
            if (operacao == '/' && num2 == 0)
            {
                printf("operacao nao pode ser realizada\n");
            }
            else
            {
                resultado = calcular(resultado, num2, operacao);
                printf("%.3lf\n", resultado);
            }
            
            // Nova entrada
            scanf("%lf\n%c", &num2, &operacao);
        }
    }
    
	return 0;
}