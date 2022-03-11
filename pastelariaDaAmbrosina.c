/*
Descrição:
Ambrosina virou empresária. Decidiu vender pastéis, empadas e kibes. O problema é que de uns tempos pra cá, os preços dos ingredientes se alteram bastante e isso reflete no custo do produto final. 
Logo ambrosina contratar você para escrever um programa para calcular automaticamente o custo de cada produto assim que o preço do ingrediente for alterado.
Seguem os exemplos das tabelas que a Ambrosina fez.

Formato de entrada:
Consiste de 4 linhas. Da linha 1 a 3, serão dados quatro números reais por linha, correspondendo a quantidade de ingredientes utilizados em cada produto.
A sequência de ingredientes é sempre: ovo, farinha, açúcar e carne. E os produtos são na sequência: pastel, empada e kibe.
A quarta linha consiste de quatro números reais correspondendo ao preço do ovo, farinha, açúcar e carne, respectivamente.

Formato de saída:
A saída consiste de 03 números reais formatados com duas casas decimais. Cada número consiste do custo do pastel, empada e kibe, respectivamente. Cada número deve ser impresso em uma linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Dimensoes das matrizes dos produtos e dos precos
#define L1 3
#define C1 4
#define L2 4
#define C2 1

// Funcao para receber a quantidade de igredientes e dos precos
void receberValores(int m1[L1][C1], int m2[L2][C2])
{
    int i, j;
    
    // Recebendo as quantidades dos igredientes
    for (i = 0; i < L1; ++i)
    {
        for (j = 0; j < C1; ++j)
        {
            scanf("%d", &m1[i][j]);
        }
    }
    
    // Recebendo os precos
    for (i = 0; i < L2; ++i)
    {
        for (j = 0; j < C2; ++j)
        {
            scanf("%f", &m2[i][j]);
        }
    }
}

// Funcao para obter o custo total dos produtos
void imprimirCustos(int m1[L1][C1], float m2[L2][C2])
{
    int i, j;
    float custos[L1][C2] = {0};
    
    // Calculando os custos totais
    for (i = 0; i < L1; ++i)
    {
        for (j = 0; j < C1; ++j)
        {
            custos[i][0] += (m1[i][j] * m2[j][0]);
        }
    }
    
    // Imprimindo
    for (i = 0; i < L1; ++i)
    {
        printf("%.2f\n", custos[i][0]);
    }
    
}

int main() 
{
    // Varivaveis
    int produtos[L1][C1];
    float precos[L2][C2];
    
    // Recebendo a quantidade de igredientes e dos precos de cada um
    receberValores(produtos, precos);
    
    // Obtendo e imprimindo os custos de cada produto
    imprimirCustos(produtos, precos);
    
    return 0;
}