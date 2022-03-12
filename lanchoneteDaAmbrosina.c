/*
Descrição:
Ambrosina é de lua. Quase todo dia ela quer mudar o cardápio de sua lanchonete. Ambrósio, o programador do sistema, não agüenta mais alterar o código do programa todas as vezes que Ambrosina muda o humor. Então Ambrósio resolveu mudar o software de forma que Ambrosina possa cadastrar o cardápio todas as manhãs, ao iniciar o software.
O software lê a quantidade de produtos a serem cadastrados, e depois o código de LED instalada na lanchonete seguidos pela descrição e preço do produto. Os clientes escolhem os produtos pelo código.
Se o cliente pede um produto não cadastrado ou uma quantidade negativa o pedido é considerado inválido.
O sistema calcula quantos itens o cliente escolheu de cada código e imprime o total da conta, sem descontos! Eita Ambrosina sovina !!

Formato de entrada:
Consiste de um inteiro n, representando o número de produtos a serem cadastrados.
Depois, segue o cadastro dos n produtos, onde serão lidos para cada produto:
um inteiro representando o código de LED,
uma descrição do produto
e um número real representando o preço.
Depois, são lidos os pedidos.
O pedido consiste do código do produto e da quantidade de itens daquele produto que será pedido. O pedido se encerra quando o código lido é igual a 0.

Formato de saída:
O valor que o cliente deve pagar, formatado com duas casas decimais. Pedidos inválidos são ignorados.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Constantes
#define T 100

/*
    Estrutura dos pedidos
*/
typedef struct
{
    int codigo;
    double preco;
    char nome[100];
} PRODUTOS;

/*
    Funcao para cadastrar os produtos.
*/
void cadastrar_produtos(PRODUTOS *produto)
{
    // Codigo
    scanf("%d", &produto->codigo);
    getchar();
    
    // Nome
    gets(produto->nome);
    
    // Preco
    scanf("%lf", &produto->preco);
}

/*
    Funcao que busca um pedido no registro
    e retornar o indice da sua posicao.
*/
int buscar_produto(PRODUTOS produto[], int codigo, int m)
{
    int i;
    
    for (i = 0; i < m; ++i)
    {
        if (produto[i].codigo == codigo)
        {
            return i;
        }
    }
    
    return -1;
}

/*
    Funcao para calcular o total do pedido.
    Chama a funcao buscar_pedido() para verificar
    se o produto informado existe no registro.
*/
void total_compra(PRODUTOS produto[], int codigo, int qtd, int m, double *total)
{
    // Verificanfo se o produto existe
    int pos = buscar_produto(produto, codigo, m);
    
    if (pos != -1 && (qtd != 0 && qtd > 0))
    {
        *total += produto[pos].preco * qtd;
    }
}

int main() 
{
    /*
        VARIAVEIS
        produto : Arranjo de PRODUTOS
        i, m       : Quantidade de cadastros
        codigo  : codigo do produto a ser comprado
        qtd     : quantidade do produto a ser comprado
        total   : Total da compra
    */
    PRODUTOS produto[T];
    int i, m, qtd, codigo;
    
    double total = 0;
    
    // Recebendo os cadastros
    scanf("%d", &m);
    
    // funcao
    for (i = 0; i < m; ++i)
    {
        cadastrar_produtos(&produto[i]);
    }
    
    // Relizando os pedidos
    scanf("%d", &codigo);
    
    while (codigo != 0)
    {
        // Quantidade
        scanf("%d", &qtd);
        total_compra(produto, codigo, qtd, m, &total);

        // Proxima entrada
        scanf("%d", &codigo);
    }
    
    // Imprimindo o total da compra
    printf("%.2lf\n", total);
    
    return 0;
}