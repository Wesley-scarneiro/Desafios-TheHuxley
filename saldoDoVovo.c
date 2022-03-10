/*
Descrição:
Vovô João tem uma banca de jornais; ele tem muitos clientes, e diariamente recebe muito dinheiro, mas também faz muitos pagamentos para manter o seu estoque de jornais e revistas. Todo dia ele vai ao banco realizar um depósito ou uma retirada de dinheiro. Em alguns dias, o saldo de sua conta no banco fica negativo, mas Vovô João tem um acordo com o banco que garante que ele somente é cobrado se o saldo for menor do que um valor pré-estabelecido.
Dada a movimentação diária da conta do banco do Vovô João, você deve escrever um programa que calcule o menor saldo da conta, no período dado.

Formato de entrada:
A primeira linha da entrada contém dois números inteiros N e S que indicam respectivamente o número de dias do período de interesse e o saldo da conta no início do período. Cada uma das N linhas seguintes contém um número inteiro indicando a movimentação de um dia (valor positivo no caso de depósito, valor negativo no caso de retirada). A movimentação é dada para um período de N dias consecutivos: a primeira das N linhas corresponde ao primeiro dia do período de interesse, a segunda linha corresponde ao segundo dia, e assim por diante.
1 ≤ N ≤ 30
-10^5 ≤ S ≤10^5
-10^5 ≤ cada movimentação ≤10^5

Formato de saída:
Seu programa deve imprimir uma única linha, contendo um único número inteiro, o menor valor de saldo da conta no período dado.
Perceba que você deve sempre esperar o final do dia para verificar o saldo. Ou seja, embora o problema informe o saldo inicial, você precisa realizar a primeira operação para verificar o saldo ao final do dia.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Variaveis
    int periodo, saldo, entrada, menorSaldo, i;
    
    // Primeira entrada
    scanf("%d %d", &periodo, &saldo);
    
    // Enquanto o per?odo de movimenta??o n?o terminar
    for (i = 1; i <= periodo; ++i)
    {
        // Nova entrada - Dep?sito(+) ou retirada(-)
        scanf("%d", &entrada);
        
        // Atualizando o saldo
        saldo = saldo + (entrada);
        
        // Registrando o saldo da primeira movimentacao
        if (i == 1)
        {
            menorSaldo = saldo;
        }
        
        // Registrando o menor saldo encontrado quando i != 1
        if (saldo < menorSaldo)
        {
            menorSaldo = saldo;
        }
        
    }
    
    // Imprimindo o menor saldo encontrado no per?odo
    printf("%d", menorSaldo);
    
    return 0;
}