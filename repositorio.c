/*
Descrição:
Uma das boas práticas ao administrar um conjunto de computadores é manter os aplicativos sempre atualizados. Entretanto, em uma grande corporação com milhares de aplicativos instalados, a simples verificação do que precisa ser atualizado pode tornar-se uma tarefa bem complicada. Para facilitar isso, alguns fabricantes armazenam todos os aplicativos existentes em grandes bases de dados chamadas repositórios e um programa é responsável por verificar esse repositório e atualizar as versões dos aplicativos. 
Ambrósio, um administrador de sistemas e rapper nas horas vagas, trabalha em uma empresa que, infelizmente, não utiliza um sistema com repositórios. Para facilitar sua vida, ele decidiu que era a hora de ter o seu próprio sistema e pediu a sua ajuda. 
Periodicamente ele varre a Internet em busca das páginas que possam conter os aplicativos e constrói uma lista com as versões dos aplicativos que deseja instalar disponíveis em cada página. Um programa deve verificar então qual a versão de cada programa instalado nos computadores (todos eles possuem os mesmos aplicativos instalados e nas mesmas versões) e instalar todos aqueles que ainda não foram instalados ou cuja versão instalada seja anterior a versão mais recente. Como ele não sabe programar direito, ele pediu sua ajuda.
Dado uma lista de aplicativos instaladas nos computadores da empresa, com suas respectivas versões e uma lista de aplicativos disponíveis na internet que devem ser instalados, determinar quais devem ser instalados e em quais versões.

Formato de entrada:
A entrada contém um único conjunto de testes, que deve ser lido do dispositivo de entrada padrão (normalmente o teclado).
A primeira linha da entrada contém dois inteiros C (1 <= C <= 10.000) e N (1 <= N <= 1.000) que representam o número total de programas instalados na empresa e o número de total aplicativos disponíveis na internet, respectivamente.
As C linhas seguintes possuem dois inteiros cada, Pc (1 <= Pc <= 1.000.000.000) e Vc (1 <= Vc <= 1.000.000.000), representando o número do programa e o número da versão instalada nos computadores. Todo aplicativo está instalado uma única vez em cada máquina e em uma única versão.
Em seguida, as As N linhas seguintes possuem dois inteiros cada, Pn (1 <= Pn <= 1.000.000.000) e Vn (1 <= Vn <= 1.000.000.000), representando o número do programa e o número da versão disponível na internet.
Um dado programa pode estar disponível em mais de uma versão na internet. Nesse caso, você deve instalar somente a versão mais atual.
Se houver um programa disponível na Internet e que não esteja instalado no computador, você deve instalá-lo.

Formato de saída:
Seu programa deve imprimir, na saída padrão, diversas linhas, cada uma contendo dois inteiros, Ps e Vs com o número do programa e a versão que deve ser instalada.
A saída deve estar ordenada de acordo com o número do programa. Ou seja, mesmo que o programa 5 apareça primeiro que o programa 1, por exemplo, na saída você deve mostrar primeiro o programa 1 e sua versão e só depois o programa 5 com a sua versão.
Em todo caso de teste existe pelo menos um programa que deve ser instalado.
*/

#include <stdio.h>
#include <stdlib.h>

/*
    Estrutura de um programa instalado no repositorio ou disponivel para atualizacao/instalacao.
*/
typedef struct EstruturaPrograma
{
    long int id;
    long int versao;
} PROGRAMA;

/*
    Estrurura de um repositorio.
*/
typedef struct EstruturaRepositorio
{
    int total;
    PROGRAMA *programas;
} REPOSITORIO;

/*
    Estrutura para as atualizacao/instalacoes disponiveis.
*/
typedef struct EstruturaAtualizacao
{
    int total;
    PROGRAMA *programas;
} ATUALIZAR;

/*
    Estrutura especifica para os programas que serao atualizados ou instalados.
    A lista de programas gerenciara esta estrutura.
*/
typedef struct AtualizarInstalar
{
    long int id;
    long int versao;
    struct AtualizarInstalar *prox;
} ATUINST;

/*
    Estrutura de uma lista de programas a serem atualizados ou instalados (lista simplesmente ligada).
    Um pograma do tipo "LISTA", sera aquele que precisara ser atualizado ou instalado no repositorio.
*/
typedef struct EstruturaLista
{
    ATUINST *cabeca;             // no-cabeca aponta para o primeiro elemento da lista
} LISTA;

/*
    Funcao para inicializar a lista de programas a serem atualizados ou instalados.
    Inicializa o no-cabeca com valor nulo.
*/
void inicializarLista(LISTA *lista)
{
    lista->cabeca = (ATUINST*) malloc(sizeof(ATUINST));
    lista->cabeca->prox = NULL;
    lista->cabeca->id = -1;
}

/*
    Funcao para apagar os elementos da lista e liberar a memoria.
*/
void apagarLista(LISTA *lista)
{
    ATUINST *apagar, *prox;
    prox = lista->cabeca;
    
    while (prox != NULL)
    {
        apagar = prox;                  // Elemento atual
        prox = prox->prox;              // Elemento seguinte
        free(apagar);                   // Apaga o elemento atual
    }
}

/*
    Funcao para realizar a insercao de elementos de forma ordenada na lista.
    Ordena em relacao ao 'id' dos programas.
    A funcao recebe primeiramente um elemento do tipo PROGRAMA.
    Depois, fazemos a copia desse elemento para um do tipo ATUINST.
    Por fim, o elemento ATUINTS sera adicionado na lista.
*/
void inserirElementoLista(LISTA *lista, PROGRAMA *elemento)
{
    ATUINST *programa, *prox, *ant;
    programa = (ATUINST*) malloc(sizeof(ATUINST));
    programa->id = elemento->id;
    programa->versao = elemento->versao;

    prox = lista->cabeca;
    while (programa->id > prox->id)
    {
        ant = prox;
        prox = prox->prox;
        if (!prox) break;
    }

    programa->prox = ant->prox;
    ant->prox = programa;
}

/*
    Funcao para buscar um programa na lista de programas que serao atualizados/instalados.
    Retorna o endereco de memeria de um programa registrado na lista ou um valor NULL.
    Se a lista estiver vazia ou nao conter o elemento, retorna NULL.
    Caso ao contrario, verifica se o elemento informado esta na lista e retorna seu endereco.
    Devido a lista estar ordenada, a busca eh realizada enquanto o id do elemento buscado for
    sempre o maior ou igual que qualquer elemento da lista.
*/
ATUINST* buscarElementoLista(LISTA *lista, PROGRAMA *elemento)
{
    // Lista vazia
    if (lista->cabeca->prox == NULL) return NULL;

    ATUINST *prox = lista->cabeca->prox;
    while ((prox != NULL) && (elemento->id >= prox->id))
    {
        if (elemento->id == prox->id) return prox;
        prox = prox->prox;
    }
    return NULL;
}

/*
    Funcao para substituir um programa disponivel para atualizacao/instalacao na lista.
    Um programa da lista sera substituido, quando encontrarmos o mesmo programa em uma
    versao superior.
    Realiza a mudanca da versao do programa que esta na lista.
*/
void substituirVersaoLista(PROGRAMA *elemento, ATUINST *programa)
{
    if (elemento->versao > programa->versao)
    {
        programa->versao = elemento->versao;
    }
}

/*
    Funcao para imprimir a lista de programas a serem atualizados/instalados.
*/
void imprimirLista(LISTA *lista)
{
    ATUINST *prox = lista->cabeca->prox;
    while (prox != NULL)
    {
        printf("%ld %ld\n", prox->id, prox->versao);
        prox = prox->prox;
    }
}


/*
    Funcao particao, para ser utilizada pelo QuickSort.
*/
int particao(PROGRAMA *A, int i, int f)
{
    // Variaveis
    long int pivo, j, k;
    PROGRAMA temp;
    pivo = A[f].id;
    j = i-1;

    for (k = i; k < f; ++k)
    {
        if (A[k].id <= pivo)
        {
            ++j;
            temp = A[j];
            A[j] = A[k];
            A[k] = temp;
        }
    }

    temp = A[j+1];
    A[j+1] = A[f];
    A[f] = temp;
    return (j+1);
}

/*
    Funcao para ordenacao dos arranjos de REPOSITORIO e ATUALIZAR.
    Ordenacao realizada pelo algoritmo do QuickSort.
*/
void quickSort(PROGRAMA *A, int i, int f)
{
    if (i < f)
    {
        int q = particao(A, i, f);
        quickSort(A, i, q-1);
        quickSort(A, q+1, f);
    }
}


/*
    Funcao para verificar as atualizacao no repositorio, atraves da busca binaria.
    Um programa disponivel para atualizacao/instalacao sera buscado no arranjo de programas instalados.
    Retornos da busca:
        -1 : O programa nao esta instalado no repositorio
         0 : O programa esta instalado e nao precisa ser atualizado
         1 : O programa esta instalado e precisa ser atualizado
*/
int verificarAtualizacao(REPOSITORIO *repositorio, PROGRAMA *atualizacao)
{
    int i, m, f;
    i = 0;
    f = repositorio->total - 1;

    while (i <= f)
    {
        m = (i+f)/2;
        if (atualizacao->id == repositorio->programas[m].id)
        {
            if (atualizacao->versao > repositorio->programas[m].versao) return 1;
            else return 0;
        }
        else
        {
            if (atualizacao->id < repositorio->programas[m].id)
            {
                f = m - 1;
            }
            else i = m + 1;
        }
    }

    return -1;
}

/*
    Funcao para receber os dados dos arranjos do REPOSITORIO e da ATUALIZAR.
*/
void receberDados(REPOSITORIO *repositorio, ATUALIZAR *atualizar)
{
    int i;

    // Recebendo os dados dos programas instalados no repositorio
    for (i = 0; i < repositorio->total; ++i)
    {
        scanf("%ld %ld", &repositorio->programas[i].id, &repositorio->programas[i].versao);
    }

    // Recebendo os dados dos programas disponiveis para atualizacao/instalacao
    for (i = 0; i < atualizar->total; ++i)
    {
        scanf("%ld %ld", &atualizar->programas[i].id, &atualizar->programas[i].versao);
    }
}

/*
    Funcao para inicializar todas as estruturas e modelar a solucao do problema.
    Recebe somente o tamanho dos arranjos REPOSITORIO e ATUALIZAR.
*/
void resultado(int r, int a)
{
    REPOSITORIO repositorio;
    ATUALIZAR atualizar;
    repositorio.total = r;
    repositorio.programas = (PROGRAMA*) malloc(sizeof(PROGRAMA)*r);
    atualizar.total = a;
    atualizar.programas = (PROGRAMA*) malloc(sizeof(PROGRAMA)*a);

    // Recebendo os dados
    receberDados(&repositorio, &atualizar);

    // Ordenando os arranjos
    quickSort(repositorio.programas, 0, repositorio.total-1);
    
    // Iniciando a lista de atualizacoes/instalacoes
    LISTA lista;
    inicializarLista(&lista);

    // Verificando as atualizacoes
    int i, j;
    for (i = 0; i < atualizar.total; ++i)
    {
        j = verificarAtualizacao(&repositorio, &atualizar.programas[i]);

        // Nao instalado no repositorio
        if (j != 0)
        {
            ATUINST *programa = buscarElementoLista(&lista, &atualizar.programas[i]);
            if (programa != NULL) substituirVersaoLista(&atualizar.programas[i], programa);
            else inserirElementoLista(&lista, &atualizar.programas[i]);
        }
    }

    // Impressao da lista de programas a serem atualizados/instalados
    imprimirLista(&lista);

    // Liberando a memoria alocada dinamicamente
    free(repositorio.programas);
    free(atualizar.programas);
    apagarLista(&lista);
}

int main()
{
    int r, a;
    scanf("%d %d", &r, &a);
    resultado(r, a);

    return 0;
}