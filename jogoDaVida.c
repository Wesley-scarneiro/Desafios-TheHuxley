/*
Descrição:
 O Jogo da Vida é um jogo sem jogadores, todos os eventos ocorridos são consequências
do estado inicial do campo, esse campo é uma matriz formada por células vivas ou mortas
(1 ou 0 respectivamente), o estado dessas células é alterado ou mantido dependendo das
condições ao seu redor, as condições estão descritas abaixo:
Qualquer célula viva com menos de dois vizinhos vivos morre de solidão.
Qualquer célula viva com mais de três vizinhos vivos morre de superpopulação
Qualquer célula morta com exatamente três vizinhos vivos se torna uma célula
viva.
Qualquer célula viva com dois ou três vizinhos vivos continua no mesmo estado
para a próxima geração.
Para cada alteração no campo(todas ocorrem simultaneamente) temos uma geração.
Exemplo com 2 gerações(Células pretas estão vivas, as brancas estão mortas):
Oberve que na próxima geração o estado do campo voltará ao mesmo estado anterior,
e assim sucessivamente, porém não é sempre que isso acontece.
O problema é, dados um campo n x m, as posições onde há células vivas inicialmente,
e um número de gerações, imprimir o campo de cada geração seguindo o formato de
saída. Considere que qualquer célula fora do campo está sempre morta.

Formato de entrada:
Na primeira linha de entrada temos quatro números inteiros N,M,V e G representando
respectivamente o número de linhas do campo, o número de colunas do campo,
o números de células vivas no campo inicial, e o número de gerações a serem
computadas. Considere 1 <= N,M <= 45
A partir daí seguem V linhas com dois inteiros Y e X representando a posição da matriz (linha e coluna) onde há uma célula viva.

Formato de saída:
Primeiro é impresso o campo inicial e logo após os G campos de cada geração,
G maior ou igual a 1.
Os estados nos campos são representados por números, 0 representa célula morta,
1 representa uma célula viva.
Os campos são impressos linha a linha, cada uma com um espaço antes de cada número
e uma quebra de linha. No final de cada campo deve haver mais uma quebra de linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Dimensao maxima da matriz
#define L 45
#define C 45

// Funcao que determina o estado de uma elemento da matriz copia
void estados(int m[L][C], int c[L][C], int ql, int qc, int i, int j)
{
    int soma = 0;
    
    // Antecessor e sucessor central
    if (j - 1 >= 0)  soma += m[i][j-1];
    if (j + 1 < qc)  soma += m[i][j+1];
    
    // Linha superior e inferior central
    if (i - 1 >= 0)  soma += m[i-1][j];
    if (i + 1 < ql)  soma += m[i+1][j];
    
    // Extremos da esquerda e direita
    if ((i - 1 >= 0) && (j - 1 >= 0))   soma += m[i-1][j-1];
    if ((i + 1 < ql) && (j - 1 >= 0))   soma += m[i+1][j-1];
    if ((i - 1 >= 0) && (j + 1 < qc))   soma += m[i-1][j+1];
    if ((i + 1 < ql) && (j + 1 < qc))   soma += m[i+1][j+1];
    
    /*
        Determinando o estado de c[i][j]
    */
    
    // Morre de solidao
    if (soma < 2 && m[i][j] == 1)
    {
        c[i][j] = 0;
    }
    
    // Morre por superpopulacao
    if (soma > 3 && m[i][j] == 1)
    {
        c[i][j] = 0;
    }
    
    // Se torna viva
    if (soma == 3 && m[i][j] == 0)
    {
        c[i][j] = 1;
    }
    
    // Se soma = 2 ou soma = 3, a celula mantem o seu estado se viva. Se morta e soma = 2, mantem-se morta.
    if ((soma == 2 || soma == 3) && m[i][j] == 1)
    {
        c[i][j] = 1;
    }
}

// Funcao que copia os elementos de uma matriz em outra
void fazerCopia(int m[L][C], int c[L][C], int ql, int qc)
{
    int i, j;
    
    for (i = 0; i < ql; ++i)
    {
        for (j = 0; j < qc; ++j)
        {
            m[i][j] = c[i][j];
        }
    }
}

// Funcao para percorrer a matriz e verificar seus estados
void analisarGeracao(int m[L][C], int ql, int qc)
{
    int i, j;
    
    // Copia da matriz do jogo para determinar os resultados
    int c[L][C] = {0};
    
    // Percorrendo a matriz
    for (i = 0; i < ql; ++i)
    {
        for (j = 0; j < qc; ++j)
        {
            // Verificando estado da vizinhanca e determinando m[i][j]
            estados(m, c, ql, qc, i, j);
        }
    }
    
    // Guardando os resultados da copia em jogo
    fazerCopia(m, c, ql, qc);

    // Imprimindo estado da geracao atual
    printf("\n");
    
    for (i = 0; i < ql; ++i)
    {
        for (j = 0; j < qc; ++j)
        {
            printf(" %d", m[i][j]);
        }
        printf("\n");
    }
}


int main() 
{
    // Variaveis
    int n, m, v, g, i, j;
    
    // Entrada do tamanho da matriz, numero de celulas vivas e a quantidade de geracoes.
    scanf("%d %d %d %d", &n, &m, &v, &g);
    
    // Matriz do jogo
    int jogo[L][C] = {0};
    
    // Recebendo as posicoes das celulas vivas
    while (v > 0)
    {
        scanf("%d %d", &i, &j);
        jogo[i][j] = 1;
        --v;
    }
    
    // Imprimindo o campo inicial do jogo
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            if (i == 0 && j == m-1) printf("%d", jogo[i][j]);
            else if (i == 0) printf("%d ", jogo[i][j]);
            else printf(" %d", jogo[i][j]);
        }
        printf("\n");
    }

    // Funcao para variar as geracoes
    while (g > 0)
    {
        // Funcao
        analisarGeracao(jogo, n, m);
        --g;
    }
    
	return 0;
}