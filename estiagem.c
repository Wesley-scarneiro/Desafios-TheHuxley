/*
Descrição:
Devido às constantes estiagens que aconteceram nos últimos tempos em algumas regiões do Brasil, o governo federal criou um órgão para a avaliação do consumo destas regiões com finalidade de verificar o comportamento da população na época de racionamento. Este órgão responsável irá pegar algumas cidades (por amostragem) e verificará como está sendo o consumo de cada uma das pessoas da cidade e o consumo médio de cada cidade por habitante.

Formato de entrada:
A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um inteiro N (1 ≤ N ≤ 1*(10^6)), indicando a quantidade de imóveis. As N linhas contém um par de valores X (1 ≤ X ≤ 10) e Y (1 ≤ Y ≤ 20000), indicando a quantidade de moradores de cada imóvel e o respectivo consumo total de cada imóvel (em m3). Com certeza, nenhuma residência consome mais do que 20000 m3 por mês. O final da entrada é representado pelo número zero.

Formato de saída:
Para cada entrada, deve-se apresentar a mensagem “Cidade# n:”, onde n é o número da cidade seguindo a sequência (1, 2, 3, ...) e em seguida deve-se listar, por ordem crescente de consumo, a quantidade de pessoas seguido de um hífen e o consumo destas pessoas, arredondando o valor para baixo
Lembre-se que o objetivo é identificar quantas pessoas estão consumindo aquela quantidade de água. Sendo assim, a sua listagem deve agrupar a quantidade de pessoas de acordo com suas médias de consumo. Para ilustrar, considere a segunda cidade do exemplo de entrada e saída. Nela existem 05 residências:
5
1 25
2 20
3 31
2 40
6 70
, ou seja, na primeira casa mora um "gastador" que consome em média 25. Na segunda moram duas pessoas, logo a média de consumo é de 10. Na terceira moram 03 pessoas e a média de consumo arredondada para baixo é de 10 por pessoa. Na quarta, 2 pessoas com média de 20 e na quinta, 6 pessoas com média de 11. Sendo assim, teríamos:
1-25 2-10 3-10 2-20 e 6-11
Como o objetivo é agrupar por consumo, existem duas casas em que a média por pessoas é de 10, ou seja, existem 5 pessoas que consomem em média 10.
Logo, ordenando pelo consumo, você deverá imprimir: 
5-10 6-11 2-20 1-25
Finalmente, na terceira linha da saída deve-se mostrar o consumo médio por pessoa da cidade, com 2 casas decimais sem arredondamento, considerando o consumo real total. Imprimir uma linha em branco entre dois casos de teste consecutivos.
No fim da saída lembre-se da quebra de linha.
DICA: use o tipo com precisão dupla (double na maioria das linguagens) para evitar erros com o ponto flutuante.
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/*
    Estrutura para uma residencia.
*/
typedef struct estruturaResidencias
{
    int num_pessoas;
    int consumo_total;
    int consumo_pessoa;
    int ler;
}RESIDENCIAS;

/*
    Estrutura para uma cidade.
*/
typedef struct estruturaCidades
{
    int num_residencias;
    RESIDENCIAS *residencias;
    int num_pessoas;
    double consumo_total;
    double consumo_medio;
}CIDADES;

/*
    Inicializa as variaveis de uma Cidade.
*/
void inicializarCidade(CIDADES* cidade)
{
    cidade->num_pessoas = 0;
    cidade->consumo_total = 0;
}

/*
    Funcao que aloca um arranjo de RESIDENCIAS.
*/

void alocarResidencias(CIDADES* cidade)
{
    cidade->residencias = (RESIDENCIAS*) malloc(sizeof(RESIDENCIAS)*cidade->num_residencias);
}

/*
    Funcao que ordena um arranjo de RESIDENCIAS em ordem crescente de consumo/pessoa.
    O algoritmo utilizado e o Bubble Sort.
*/
void ordenarResidencias(CIDADES* cidade)
{
    int i, j;
    RESIDENCIAS temp;

    for (i = (cidade->num_residencias - 1); i > 0; --i)
    {
        for (j = 0; j < i; ++j)
        {
            if (cidade->residencias[j].consumo_pessoa > cidade->residencias[j+1].consumo_pessoa)
            {
                temp = cidade->residencias[j];
                cidade->residencias[j] = cidade->residencias[j+1];
                cidade->residencias[j+1] = temp;
            }
        }
    }
}

/*
    Funcao para receber as entradas das residencias e realizar os calculos necessarios.
*/
void receberResidencias(CIDADES* cidade)
{
    int i;

    for (i = 0; i < cidade->num_residencias; ++i)
    {
        // Qtd de pessoas
        scanf("%d %d", &cidade->residencias[i].num_pessoas, &cidade->residencias[i].consumo_total);

        // Realizando alguns calculos
        cidade->residencias[i].consumo_pessoa = cidade->residencias[i].consumo_total/cidade->residencias[i].num_pessoas;
        cidade->residencias[i].ler = TRUE;
        cidade->num_pessoas += cidade->residencias[i].num_pessoas;
        cidade->consumo_total += cidade->residencias[i].consumo_total;
    }

    // Consumo medio da cidade
    cidade->consumo_medio = cidade->consumo_total/cidade->num_pessoas;
}

/*
    Funcao que agrupa as residencias com o mesmo consumo/pessoa e as imprime.
*/
void agruparResidencias(CIDADES* cidade)
{
    int i, j, k, t;
    t = cidade->num_residencias;
    k = -1;
    RESIDENCIAS agrupadas[t];

    for (i = 0; i < cidade->num_residencias; ++i)
    {
        if (cidade->residencias[i].ler == TRUE)
        {
            ++k;
            agrupadas[k].num_pessoas = cidade->residencias[i].num_pessoas;
            agrupadas[k].consumo_pessoa = cidade->residencias[i].consumo_pessoa;
        }

        for (j = i + 1; (j < cidade->num_residencias) && (cidade->residencias[i].ler == TRUE); ++j)
        {
            if (cidade->residencias[i].consumo_pessoa == cidade->residencias[j].consumo_pessoa)
            {
                agrupadas[k].num_pessoas += cidade->residencias[j].num_pessoas;
                --t;
                cidade->residencias[j].ler = FALSE;
            }
        }
    }

    // Imprimindo as residencias agrupadas
    for (i = 0; i < t; ++i)
    {
        if (i != t - 1)
        {
            printf("%d-%d ", agrupadas[i].num_pessoas, agrupadas[i].consumo_pessoa);
        }
        else
        {
            printf("%d-%d\n", agrupadas[i].num_pessoas, agrupadas[i].consumo_pessoa);
        }
    }
}

/*
    Esta funcao cria uma cidade, chama outras funcoes e imprime o resultado final.
    Recebe como parametro a quantidade de residencias de uma cidade.
*/
void imprimirCidade(int t)
{
    CIDADES cidade;
    inicializarCidade(&cidade);
    cidade.num_residencias = t;

    // Alocando um arranjo de RESIDENCIAS
    alocarResidencias(&cidade);
    
    // Recebendo os dados das residencias
    receberResidencias(&cidade);

    // Ordenando as residencias
    ordenarResidencias(&cidade);

    // Agrupando as residencias e imprimindo os resultados
    agruparResidencias(&cidade);

    // Imprimindo consumo medio da cidade
    printf("Consumo medio: %.2lf m3.\n\n", cidade.consumo_medio);

    // Liberando memoria alocada
    free(cidade.residencias);
}

int main()
{
    /*
        Variaveis:
            - caso: Numero do caso de teste.
            - n : Numero de residencias.
    */
    int caso, n;
    caso = 0;

    // Primeira entrada
    scanf("%d", &n);

    while (n != 0)
    {
        ++caso;
        printf("Cidade# %d:\n", caso);

        imprimirCidade(n);

       // Proxima entrada
       scanf("%d", &n);
    }
    
    return 0;
}