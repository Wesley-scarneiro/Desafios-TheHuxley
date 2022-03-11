/*
Descrição:
Bob trabalha no OBM (Órgão Brasileiro de Metereologia), que é a organização responsável
pela medição dos índices pluviométricos (quantidade de chuva acumulada) em todo o país.
Eles são muito eficientes no que fazem,mas estão com um problema: eles não sabem
como proceder para calcular a quantidade acumulada de chuva que caiu em cada região
em dois períodos consecutivos, muito embora eles saibam os dados de cada período
separadamente.
Como a chefia do Órgão estava muito ocupada, acabou ficando a cargo de Bob, o estagiário,
a tarefa de implementar um programa que some, para cada região, a quantidade de chuva
acumulada em dois períodos consecutivos.
O mapa que o OBM usa é dividido em N×N regiões, sendo que para cada região, a cada
período, é determinado um número inteiro indicando a quantidade de chuva acumulada.
A quantidade de chuva acumulada total em cada região em dois períodos consecutivos
é a soma das quantidades de chuva em cada um dos períodos.
Mas como Bob é só um estagiário e não está acostumado a fazer nada mais do que tirar
cópias de documentos, ele pediu sua ajuda para implementar o programa que calcula a
quantidade de chuva acumulada total nos dois períodos para cada uma das regiões, dadas
as quantidades de chuva acumulada em cada período para cada região.

Formato de entrada:
A primeira linha da entrada contém um inteiro N indicando a dimensão dos dois mapas que
devem ser lidos. Nas próximas 2N linhas são dados os dois mapas, cada mapa indicando a
quantidade de chuva acumulada nas regiões em um período. Cada mapa é descrito em N
linhas consecutivas, cada linha contendo N inteiros, sendo que cada inteiro indica a quantidade
de chuva acumulada, no período, em uma região.
Considere:
• 1 <= N <= 100.
• 0 <= quantidade de chuva acumulada em cada região de cada mapa <= 100.

Formato de saída:
A saída deverá conter N linhas, com N inteiros em cada linha, indicando a quantidade de
chuva acumulada total em cada uma das regiões nos dois períodos considerados.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Dimensao maxima da matriz
#define L 100
#define C 100

/*
    Funcao para receber as entradas em uma matriz de tamanho n.
*/
void entradas(int m[L][C], int n)
{
    int i, j;
    
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &m[i][j]);
        }
    }
}

/*
    Funcao que cria uma matriz de tamanho 'n' e guarda a soma de duas matrizes.
*/
void resultado(int p1[L][C], int p2[L][C], int n)
{
    int i, j, m[n][n];
    
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            m[i][j] = p1[i][j] + p2[i][j];
        }
    }
    
    // Imprimindo a matriz 'm'
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
}

int main() 
{
    // Variaveis
    int p1[L][C], p2[L][C], n;
    
    // Recebendo o tamanho da matriz
    scanf("%d", &n);
    
    // Entrada dos valores em cada matriz
    entradas(p1, n);
    entradas(p2, n);
    
    // Calculando e imprimindo o periodo acumulado
    resultado(p1, p2, n);
    
    return 0;
}