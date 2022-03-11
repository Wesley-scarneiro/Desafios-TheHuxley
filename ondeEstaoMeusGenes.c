/*
Descrição:
Uma forma que os cientistas ppossuem para medir como uma espécie evoluiu para outra é encontrar como o genoma do ancestral mudou até a espécie atual. Espécies próximas possuem vários genes em comum e, logo, uma boa mandeira de compará-las é comparar como seus genes trocaram de lugar.
Uma das mutações mais comuns que mudam a ordem dos genes é a "reversa". Se modelarmos um genoma como uma sequência de N genes, onde cada um é um inteiro de 1 a N, então a "reversa" é uma mutação que muda o genoma revertendo a ordem de um bloco consecutivo de genes.
Uma reversa pode ser descrita por dois índices (i. j), onde: 1 <=i <=j <=N. Os índices idicam que ele reverte a ordem dos genes de i a j. Então, quando aplicado a um genoma [g1, ... gi-1, gi, gi+1,  ... ,gj-1, gj, gj+1, ... , gN], obtemos o genoma: [g1, ..., gi−1, gj , gj−1, . . . , gi+1, gi , gj+1, . . . , gN]. Como um exemplo, a reversa (3,6) aplicada ao genoma [1, 2, 3, 4, 5, 6, 7] tem como resultado: [1, 2, 6, 5, 4, 3, 7]. Se após essa primeira reversa, nós aplicarmos novamente uma reversa (1,3), então o genoma será: [6, 2, 1, 5, 4, 3, 7].
Um cientista estudando a evolução das espécies quer simular uma série de reversas em um genoma.  Depois ele vai querer saber a posição final de vários genes.

Formato de entrada:
São vários casos de testes.
A primeira linha de um caso de teste contém um inteiro N indicando o número de genes de um genoma (1 <= N <= 50000). Você pode assumir que a ordem inicial dos genes é uma sequência de inteiros de 1 a N em ordem crescente.
A segunda linha contém um inteiro R (0<=R<=1000) indicando o número de reversas. Então seguirão R linhas, cada uma contendo dois inteiros i,j separados por um espaço e indicando os índices da reversa. Lembre-se que nesse caso, i <=1 <= j <= N.
Depois das reversas, existe uma linha contendo um inteiro Q indicando o número de consultas que serão feitas para os genes. Seguirão Q linhas, onde cada linha contém um inteiro representando um gene cuja posição final você deve determinar.
A entrada termina quando N for 0.

Formato de saída:
Para cada caso de teste, o seu programa produzirá Q+1 linhas de saída.
A primeira linha contém a string "Genome" seguida pelo número do caso de teste.
As Q linhas seguintes contém um inteiro cada, representando a resposta das consultas.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao para percorrer um array e guardar numeros de 1 ate 'n'.
*/
void criarGenes(int genoma[], int n)
{
    int i;
    
    for (i = 0; i < n; ++i)
    {
        genoma[i] = i + 1;
    }
}

/*
    Funcao para fazer a reversao de um intervalo de elementos consecutivos.
    Os pares (i, j) devem ser informados no parametro como (i-1, j-1).
*/
void reversao(int array[], int i, int j)
{
	int temp;
	
    while(i < j)
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        ++i;
        --j;
    }
}

/*
    Funcao que recebe um elemento a ser buscado em uma array e retorna a posicao dele.
    Realiza uma busca sequencial.
*/
void procurarElemento(int array[], int t, int e)
{
    int i;
    
    for (i = 0; i < t; ++i)
    {
        if (array[i] == e)
        {
            printf("%d\n", (i+1));
        }
    }
}

/*
    Funcao que agrega todas as outras para permitir multiplas entradas.
*/
void resultado(int n)
{
    // Variaveis
    int r, i, j, q, buscar;
    
    // Caso atual de teste
    
    int genoma[n];
    
    // Criando um arranjo de 'n' numeros
    criarGenes(genoma, n);
    
    // Segunda entrada: A quantidade de pares de reservas
    scanf("%d", &r);
    
    // Recebendo 'r' pares de reservas que sao os (i, j)
    while(r > 0)
    {
        // Pares (i, j)
        scanf("%d %d", &i, &j);
        
        // Fazendo a reversao com o par atual recebido
        reversao(genoma, (i-1), (j-1));
        --r;
    }
    
    // Recebendo a quantidade de consultas que serao realizadas.
    scanf("%d", &q);
    
    while (q > 0)
    {
        // Recebendo os elementos a serem buscados no arranjo
        scanf("%d", &buscar);
        
        // Buscando
        procurarElemento(genoma, n, buscar);
        --q;
    }
}


int main() 
{
    // Variaveis
    int n, teste;
    
    // Primeira entrada: Recebendo o tamanho do array
    scanf("%d", &n);

    // Havera outros casos de teste, enquanto n != 0.
    for (teste = 1; n != 0; ++teste)
    {
        printf("Genome %d\n", teste);
        
        // Funcao global que imprime o resultado para cada teste
        resultado(n);
        
        // Novo caso de teste
        scanf("%d", &n);
    }
    
    return 0;
}