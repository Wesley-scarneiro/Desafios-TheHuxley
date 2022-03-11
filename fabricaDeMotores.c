/*
Descrição:
A multiplicação de duas matrizes A e B só é possível se o número de colunas da matriz A for igual ao número de linhas da matriz B. Assim, se A é uma matriz m X n e B, uma matriz n X p, a multiplicação será possível e o produto será uma matriz C, m X p.
O produto matricial pode ser muito útil em várias aplicações como, por exemplo, na fábrica de motores a seguir.
Uma certa fábrica produziu dois tipos de motores: M0 e M1, nos meses de janeiro a dezembro. O número de motores produzidos foi registrado na tabela superior esquerda.
O setor de controle de vendas tem uma tabela do custo e do lucro (em reais) obtidos com cada motor. Esta tabela é a inferior esquerda.
Para saber o custo e o lucro nos meses de janeiro a dezembro, basta que se faça o produto matricial das duas tabelas.
Sua missão é fazer um programa que receba as duas tabelas e imprima os custos e lucros mensais de cada motor e também os custos e lucros anuais de cada motor.

Formato de entrada:
Primeiramente, serão fornecidos os dados de produção. Serão dados 12 pares de inteiros, representando a produção dos motores M0 e M1, respectivamente, mês a mês.
Depois são dados dois pares de números reais, representando o custo e o lucro de cada um dos motores.

Formato de saída:
Seja f um número real formatado com duas casas decimais, você deve imprimir:
Motor[0], Mes[1], custo=[f], lucro=[f]
Motor[0], Mes[2], custo=[f], lucro=[f]
...
Motor[0], Mes[12], custo=[f], lucro=[f]
Motor[1], Mes[1], custo=[f], lucro=[f]
...
Motor[1], Mes[12], custo=[f], lucro=[f]
Motor[0], anual, custo=[f], lucro=[f]
Motor[1], anual, custo=[f], lucro=[f]
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Matriz das producoes dos motores
#define LIN1 12
#define COL1 2

// Matriz dos custos e lucros
#define LIN2 2
#define COL2 2

/*
    Funcao para receber os valores das producoes, custos e lucros.
*/
void entradas(double p[LIN1][COL1], double cl[LIN2][COL2])
{
    int i;
    
    // Producao
    for (i = 0; i < LIN1; ++i)
    {
        // Entradas
        scanf("%lf %lf", &p[i][0], &p[i][1]);
    }
    
    // Custos e lucros
    for (i = 0; i < LIN2; ++i)
    {
        // Entradas
        scanf("%lf %lf", &cl[i][0], &cl[i][1]);
    }
}

/*
    Funcao para multiplicar as matrizes.
*/
void multiplicar(double p[LIN1][COL1], double cl[LIN2][COL2])
{
    // Matrizes de custos e lucros de cada motor
    double m0[LIN1][COL2], m1[LIN1][COL2];
    
    int i, j;
    
    for (i = 0; i < LIN1; ++i)
    {
        // Custo e lucro para M0
        m0[i][0] = p[i][0] * cl[0][0]; // --> custo
        m0[i][1] = p[i][0] * cl[0][1]; // --> lucro
        
        // Custo e lucro para M1
        m1[i][0] = p[i][1] * cl[1][0]; // --> custo
        m1[i][1] = p[i][1] * cl[1][1]; // --> lucro
    }
    
    // Funcao para imprimir as matrizes
    imprimir(m0, m1);
}

/*
    Funcao para formatar a impressao das matrizes m0 e m1.
*/
void imprimir(double m0[LIN1][COL2], double m1[LIN1][COL2])
{
    int i;
    double total[2][2] = {0};
    
    // Imprimindo M0
    for (i = 0; i < LIN1; ++i)
    {
        printf("Motor[0], Mes[%d], custo=[%.2lf], lucro=[%.2lf]\n", (i+1), m0[i][0], m0[i][1]);
        
        // Soma dos custos e lucros
        total[0][0] += m0[i][0];
        total[0][1] += m0[i][1];
    }
    
    // Imprimindo M1
    for (i = 0; i < LIN1; ++i)
    {
        printf("Motor[1], Mes[%d], custo=[%.2lf], lucro=[%.2lf]\n", (i+1), m1[i][0], m1[i][1]);
        
        // Soma dos custos e lucros
        total[1][0] += m1[i][0];
        total[1][1] += m1[i][1];
    }
    
    // Total anual para M0 e M1
    printf("Motor[0], anual, custo=[%.2lf], lucro=[%.2lf]\n", total[0][0], total[0][1]);
    printf("Motor[1], anual, custo=[%.2lf], lucro=[%.2lf]\n", total[1][0], total[1][1]);    
}

int main() 
{
    double producao[LIN1][COL1], custoLucro[LIN2][COL2];
    
    // Recebendo os dados das producoes dos motores
    entradas(producao, custoLucro);
    
    // Multiplicar as matrizes e imprimir os resultados
    multiplicar(producao, custoLucro);
    
    return 0;
}