/*
Descrição:
Este ano tem Copa do Mundo! O país inteiro se prepara para torcer para a equipe canarinho conquistar mais um título, tornando-se hexacampeã.
Na Copa do Mundo, depois de uma fase de grupos, dezesseis equipes disputam a Fase Final, composta de quinze jogos eliminatórios. A figura abaixo mostra a tabela de jogos da Fase Final:
Dados os resultados dos quinze jogos da Fase Final, escreva um programa que determine a equipe campeã.

Formato de entrada:
A entrada é composta de quinze linhas, cada uma contendo o resultado de um jogo. A primeira linha contém o resultado do jogo de número 1, a segunda linha o resultado do jogo de número 2, e assim por diante. O resultado de um jogo é representado por dois números inteiros M e N separados por um espaço em branco, indicando respectivamente o número de gols da equipe representada à esquerda e à direita na tabela de jogos
0 ≤ M ≤ 20
0 ≤ N ≤ 20

Formato de saída:
Seu programa deve imprimir uma única linha, contendo a letra identificadora da equipe campeã, seguida de uma quebra de linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao para encontrar o time campeao.
*/
void campeao(char times[16], char g1[8],char g2[4],char g3[2])
{
    int i, t, gol1, gol2;
    
    t = 0;
    
    // Oitavas-de-final
    for (i = 0; i < 8; ++i)
    {
        // Entrada dos gols de time1 x time2
        scanf("%d %d", &gol1, &gol2);
        
        if (gol1 > gol2)
        {
            // Ganhador - O ganhador esta na mesma posicao em time[]
            g1[i] = times[t];
            t += 2;
        }
        
        // Se nao, entao o ganhador eh o t+1
        else
        {
            g1[i] = times[t+1];
            t += 2;
        }
    }
    
    t = 0;
    
    // Quartas-de-final
    for (i = 0; i < 4; ++i)
    {
        // Entrada dos gols
        scanf("%d %d", &gol1, &gol2);
        
        if (gol1 > gol2)
        {
            g2[i] = g1[t];
            t += 2;
        }
        
        else
        {
            g2[i] = g1[t+1];
            t += 2;
        }
    }
    
    // Semifinal
    t = 0;
    
    for (i = 0; i < 2; ++i)
    {
        // Entrada dos gols
        scanf("%d %d", &gol1, &gol2);
        
        if (gol1 > gol2)
        {
            g3[i] = g2[t];
            t += 2;
        }
        
        else
        {
            g3[i] = g2[t+1];
            t += 2;
        }
    }
    
    // final
    scanf("%d %d", &gol1, &gol2);
    
    if (gol1 > gol2)
    {
        printf("%c\n", g3[0]);
    }
    else
    {
        printf("%c\n", g3[1]);
    }
}

int main() 
{
    // Arranjo para guardar todos os times
    char times[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
    
    // Para guardar os ganhadores das oitavas-de-final
    char g1[8];
    
    // Para guardar os ganhadores das quartas-de-final
    char g2[4];
    
    // Para guardar os ganhadores das semifinais
    char g3[2];
    
    // Funcao para imprimir o ganhador
    campeao(times, g1, g2, g3);
    
    return 0;
}