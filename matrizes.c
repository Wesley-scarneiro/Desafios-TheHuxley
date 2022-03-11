/*
Descrição:
Isquesildo é um rapaz muito criativo e inventou um novo jogo para ensinar matemática aos seus filhos. Ele desenha em uma folha de papel um tabuleiro de dimensões n X m. Depois numera cada um das células do tabuleiro da esquerda para a direita, de cima para baixo, começando com o valor 1. Então ele pede ao seus filhos que executem as seguintes operações: 
Some todos os valores de todas as células do tabuleiro, chame esse valor de t;
Some todos os valores da diagonal superior direita da célula 1, incluindo a própria célula, chame esse valor de x;
Some os valores da primeira e da última coluna do tabuleiro e chame-os de a e b, respectivamente;
Some todos os valores da primeira e da última linha e chame-os de c e d, respectivamente;
Some todos os valores da diagonal superior esquerda da ultima célula da última linha (linha mais abaixo) do tabuleiro , chame esse valor de y;
Qual o resultado da expressão ( t - (x+y) + (a *b) - (c*d) ) / (n*m) ?

Formato de entrada:
Consiste de 02 números inteiros n e m (n>=0, m>=0) representando, respectivamente, o número de linhas e colunas do tabuleiro. A entrada acaba quando n=0 e m =0.

Formato de saída:
Consiste de um número real, arredondado para duas casas decimais, resultado da expressão destacada na descrição.
Para o caso onde n = 0 ou m = 0 a resposta deve ser 0.00
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao para realizar todas as operacoes no tabuleiro.
*/
float operacoesTabuleiro(int n, int m)
{
    // Evitando divisao por zero
    if (n == 0 || m == 0)
    {
        return 0;
    }
    
    int i, j, k;
    float t, a, b, c, d, x, y, resultado;
    
    // Matriz de dimensao n x m
    int matriz[n][m];
    
    k = 1;
    t = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    x = 0;
    y = 0;
    
    // Somando as enumeracoes de cada posicao do tabuleiro
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            matriz[i][j] = k;
            t += k;
            ++k;
        }
    }
    
    // Somando os elementos da primeira e ultima coluna
    for (i = 0; i < n; ++i)
    {
        // Primeira coluna
        a += matriz[i][0];
        
        // Ultima coluna
        b += matriz[i][m-1];
    }
    
    // Somando os elementos da primeira e ultima linha
    for (j = 0; j < m; ++j)
    {
        // Primeira linha
        c += matriz[0][j];
        
        // Ultima linha
        d += matriz[n-1][j];
    }

    // Somando os elemento da diagonal superior direita
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            if (i == j)
            {
                x += matriz[i][j];
            }
        }
    }
    
    // Somando os elementos da diagonal superior esquerda
    i = n-1;
    j = m-1;
    
    while (i >= 0 && j >= 0)
    {
        y += matriz[i][j];
        --i;
        --j;
    }
    
    // Operacao final
    resultado = (t - (x+y) + (a*b) - (c*d) ) / (n*m);
    
    return resultado;
}

int main() 
{
    int n, m;
    float resultado;
    
    // Primeira entrada das dimensoes da matriz
    scanf("%d %d", &n, &m);
    
    while (n != 0 || m != 0)
    {
        // Chamando funcao
        resultado = operacoesTabuleiro(n, m);
        printf("%.2f\n", resultado);
        
        // Nova entrada
        scanf("%d %d", &n, &m);
    }
    
    return 0;
}