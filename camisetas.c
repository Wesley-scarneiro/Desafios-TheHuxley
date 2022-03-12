/*
Descrição:
O professor Rolien organizou junto às suas turmas de Ciência da Computação a confecção de uma camiseta polo que fosse ao mesmo tempo bonita e barata. Após algumas conversas, ficou decidido com os alunos que seriam feitas somente camisetas da cor preta, o que facilitaria a confecção. Os alunos poderiam escolher entre o logo do curso e os detalhes em branco ou vermelho. Assim sendo, Rolien precisa de sua ajuda para organizar as listas de quem quer a camiseta em cada uma das turmas, relacionando estas camisetas pela cor do logo do curso, tamanho (P, M ou G) e por último pelo nome.

Formato de entrada:
A entrada contém vários casos de teste. Cada caso de teste inicia com um valor N, (1 ≤ N ≤ 60) inteiro e positivo, que indica a quantidade de camisetas a serem feitas para aquela turma. As próximas N*2 linhas contém informações de cada uma das camisetas (serão duas linhas de informação para cada camiseta). A primeira linha irá conter o nome do estudante e a segunda linha irá conter a cor do logo da camiseta ("branco" ou "vermelho") seguido por um espaço e pelo tamanho da camiseta "P" "M" ou "G". A entrada termina quando o valor de N for igual a zero (0) e esta valor não deverá ser processado.

Formato de saída:
Para cada caso de entrada deverão ser impressas as informações ordenadas pela cor dos detalhes em ordem ascendente, seguido pelos tamanhos em ordem descendente (as letras dos tamanhos e não os tamanhos em si, ou seja, P, M e G) e por último por ordem ascendente de nome, conforme o exemplo abaixo.
Obs.: Deverá ser impressa uma linha em branco entre dois casos de teste.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tamanho das strings
#define MAX_nome 100
#define MAX_cor 9 // BRANCO OU VERMELHO; Cuidado com o fim de linha ('\0')!!!

/*
    Estrutura das camisetas
*/
typedef struct estruturaCamisetas
{
    char cor[MAX_cor];
    char tamanho;
} CAMISETAS;

/*
    Estrutura dos alunos.
*/
typedef struct estruturaAlunos
{
    char nome[MAX_nome];
    CAMISETAS camiseta;
} ALUNOS;

/*
    Estrutura das turmas de alunos.
*/
typedef struct estruturaTurmas
{
    int num_camisetas;
    ALUNOS* alunos;
} TURMAS;


/*
    Funcao que ordena um arranjo de alunos em ordem alfabetica por nome.
    A funcao strcmp() e utilizada, com uma implementacao do Bubble Sort.
*/
void ordenarAlunosNome(TURMAS* turma)
{
    int i, j;
    ALUNOS temp;

    for (i = turma->num_camisetas - 1; i >= 1; --i)
    {
        for (j = 0; j < i; ++j)
        {
            if (strcmp(turma->alunos[j].nome, turma->alunos[j+1].nome) > 0)
            {
                temp = turma->alunos[j];
                turma->alunos[j] = turma->alunos[j+1];
                turma->alunos[j+1] = temp;
            }
        }
    }

}

/*
    Funcao que ordena um arranjo de alunos em ordem decrescente por tamanho da camiseta.
    A funcao strcmp() e utilizada, com uma implementacao do Bubble Sort.
*/
void ordenarAlunosTamanho(TURMAS* turma)
{
    int i, j;
    ALUNOS temp;

    for (i = turma->num_camisetas - 1; i >= 1; --i)
    {
        for (j = 0; j < i; ++j)
        {
            if (turma->alunos[j].camiseta.tamanho < turma->alunos[j+1].camiseta.tamanho)
            {
                temp = turma->alunos[j];
                turma->alunos[j] = turma->alunos[j+1];
                turma->alunos[j+1] = temp;
            }
        }
    }
}

/*
    Funcao que ordena um arranjo de alunos em ordem alfabetica pela cor da camiseta.
    A funcao strcmp() e utilizada, com uma implementacao do Bubble Sort.
*/
void ordenarAlunosCor(TURMAS* turma)
{
    int i, j;
    ALUNOS temp;

    for (i = turma->num_camisetas - 1; i >= 1; --i)
    {
        for (j = 0; j < i; ++j)
        {
            if (strcmp(turma->alunos[j].camiseta.cor, turma->alunos[j+1].camiseta.cor) > 0)
            {
                temp = turma->alunos[j];
                turma->alunos[j] = turma->alunos[j+1];
                turma->alunos[j+1] = temp;
            }
        }
    }
}

/*
    Esta funcao realiza a chamada das outras funcoes que irao ordenar o arranjo de alunos.
    Dessa forma, e possivel combinar diferentes formas de ordenar o arranjo.
*/
void ordenarAlunos(TURMAS* turma)
{   
    ordenarAlunosNome(turma);
    ordenarAlunosTamanho(turma);
    ordenarAlunosCor(turma);
}

void dados(TURMAS* turma, int i)
{
        // Recebendo o nome do aluno atual
        gets(turma->alunos[i].nome);
        
        // Cor e tamanho da camiseta
        scanf("%s %c", turma->alunos[i].camiseta.cor, &turma->alunos[i].camiseta.tamanho);
        getchar();
}

/*
    Funcao para receber a entrada dos dados: Nome dos alunos, cor da camiseta e o tamanho dela.
*/
void receberDados(TURMAS* turma)
{
    int i;

    for (i = 0; i < turma->num_camisetas; ++i)
    {
        dados(turma, i);
    }
}

/*
    Funcao que imprime os dados de acordo com a formatacao pedida.
*/
void imprimirDados(TURMAS* turma)
{
    int i;

    for (i = 0; i < turma->num_camisetas; ++i)
    {
        printf("%s %c %s\n", turma->alunos[i].camiseta.cor, turma->alunos[i].camiseta.tamanho, turma->alunos[i].nome);
    }
    printf("\n");
}

/*
    Esta funcao realiza a chamada de outras funcoes para resolver o problema de uma estrada de teste.
    Necessita receber somente a quantidade de alunos de uma entrada.
*/
void resultado(int n)
{
    TURMAS turma;
    turma.num_camisetas = n;
    turma.alunos = (ALUNOS*) malloc(sizeof(ALUNOS)*n);

    // Recebendo a entrada dos dados
    receberDados(&turma);

    // Ordenando os dados
    ordenarAlunos(&turma);

    // Imprimindo os dados
    imprimirDados(&turma);

    // Liberando memoria
    free(turma.alunos);
}

int main()
{
    int n;

    // Primeira entrada
    scanf("%d", &n);
    getchar();

    while (n != 0)
    {   
        resultado(n);

        // Pr�xima entrada
        scanf("%d", &n);
        getchar();
    }

    return 0;
}