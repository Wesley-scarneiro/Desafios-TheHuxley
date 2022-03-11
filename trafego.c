/*
Descrição:
Visando fazer um levantamento das atuais condições de tráfego de uma malha rodoviária e definir alternativas para um reformulação futura, foi realizada uma pesquisa de tráfego do tipo ORIGEM-DESTINO. Esta pesquisa submeteu aos motoristas que trafegavam pela região em estudo um questionário com as seguintes pergutas:
De onde veio (origem)
Belo Horizonte
São Paulo
Santos Dumont
Brasília
Para onde vai (destino)
Rio de Janeiro
Petrópolis
Juiz de Fora
Barbacena
Qual o tipo de veículo
automóvel
caminhão
ônibus
Seu programa deve calcular e imprimir:
A matriz origem-destino para cada tipo de veículo
O número de veículos que tem Belo Horizonte como Origem
A quantidade de ônibus que se originam de Brasília e se destinam a Petrópolis ou Barbacena

Formato de entrada:
Seu programa recebe três inteiros O, D e T indicando respectivamente a Origem, Destino e Tipo de veículo, onde 1 <= O, D <= 4 e 1 <= T <= 3
No formato das respostas do questionário como descrito anteriormente, a entrada acaba quando os três inteiros são iguais a zero

Formato de saída:
A saída deve imprimir uma linha contendo o tipo de veículo utilizado seguido da matriz origem x destino contendo a quantidade de pessoas que tomaram aquele percurso usando o veículo descrito, assim como no formato de saída
Depois das três matrizes seu programa deve imprimir a frase "Origem Belo Horizonte: x", sem aspas, onde x representa o número de pessoas que tem como origem Belo Horizonte e por último a linha "Onibus: Brasilia ? Petropolis ou Barbacena: y", sem aspas, onde y representa o número de ônibus com origem em Brasília e destino igual a Petrópolis ou Barbacena
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Dimensoes da matriz
#define L 4
#define C 4

/*
    Funcao para receber as entradas nas matrizes.
*/
void entradas(int a[L][C], int c[L][C], int o[L][C])
{
    int i, j, t;
    
    // Primeira entrada
    scanf("%d %d %d", &i, &j, &t);
    
    while (i + j + t != 0)
    {
        // Automovel
        if (t == 1) ++a[(i-1)][(j-1)];
        
        // Caminhao
        else if (t == 2) ++c[(i-1)][(j-1)];
        
        // Onibus
        else ++o[(i-1)][(j-1)];
        
        // Proxima entrada
        scanf("%d %d %d", &i, &j, &t);
    }
}

/*
    funcao que faz a contagens de algumas origens e destinos.
*/
void contar(int a[L][C], int c[L][C], int o[L][C])
{
    int i, j, cont;
    
    cont = 0;
    
    // Contando as viagens com origem em Belo horizonte
    for (j = 0; j < C; ++j)
    {
        cont += a[0][j];
        cont += c[0][j];
        cont += o[0][j];
    }
    printf("Origem Belo Horizonte: %d\n", cont);
    
    cont = 0;
    
    // Origem Brasilia para Petropolis ou Barbacena de onibus
    for (j = 0; j < C; ++j)
    {
        if (j == 1 || j == 3) cont += o[3][j];
    }
    printf("Onibus: Brasilia - Petropolis ou Barbacena: %d\n", cont);
}

/*
    Funcao para imprimir as matrizes.
*/
void imprimir(int a[L][C], int c[L][C], int o[L][C])
{
    int i, j;
    
    // Automovel
    printf("Automovel:\n");
    for (i = 0; i < L; ++i)
    {
        for (j = 0; j < C; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    // Caminhao
    printf("Caminhao:\n");
    for (i = 0; i < L; ++i)
    {
        for (j = 0; j < C; ++j)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    
    // Onibus
    printf("Onibus:\n");
    for (i = 0; i < L; ++i)
    {
        for (j = 0; j < C; ++j)
        {
            printf("%d ", o[i][j]);
        }
        printf("\n");
    }
    
    // Imprimindo contagem
    contar(a, c, o);
}

int main() 
{
    // Variaveis
    int automovel[L][C] = {0};
    int caminhao[L][C]  = {0};
    int onibus[L][C]    = {0};
    
    // Entrada dos dados
    entradas(automovel, caminhao, onibus);
    
    // Imprimir
    imprimir(automovel, caminhao, onibus);
    
    return 0;
}