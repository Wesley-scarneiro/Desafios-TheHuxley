/*
Descrição:
Você está fazendo o banco de dados do seu projeto de P1, que será um jogo, que vai conter informações de inúmeros monstros e personagens, mas não possui nenhum conhecimento de SQL, logo, precisará aproveitar algum recurso da linguagem C para fazer o banco de dados.

Formato de entrada:
Um inteiro X, representando a quantidade de personagens/monstros que constarão no banco.
Os dados a serem colocados no banco:
Uma sequencia de caracteres, que poderá ter no máximo 20 caracteres, representando um nome.
5 inteiros, representando ID, Level, Vida, Ataque e Defesa.

Formato de saída:
Uma impressão do seu banco de dados, com os dados organizados como o modelo de saida.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Estrutura dos monstros(inimigos)
*/
typedef struct
{
    char nome[20];
    int id;
    int level;
    int vida;
    int ataque;
    int defesa;
}INIMIGOS;

/*
    Funcao para receber os dados de um registro.
    Um inteiro X, representando a quantidade de personagens/monstros que constarao no banco.
    Os dados a serem colocados no banco:
    Uma sequencia de caracteres, que podera ter no maximo 20 caracteres, representando um nome.
    5 inteiros, representando ID, Level, Vida, Ataque e Defesa.
    Uso do gets(), devido as entradas serem controladas.
*/
void registrar(INIMIGOS *inimigo)
{
    // Nome
    gets(inimigo->nome);
    
    // Id, level, vida, ataque e defesa
    scanf("%d", &inimigo->id);
    scanf("%d", &inimigo->level);
    scanf("%d", &inimigo->vida);
    scanf("%d", &inimigo->ataque);
    scanf("%d", &inimigo->defesa);
    getchar();
}

/*
    Funcao para imprimir os registros de um inimigo.
Nome: Orc
ID: 1
Level: 10
Vida: 100
Ataque: 15
Defesa: 10
*/
void imprimir(INIMIGOS inimigo)
{
    printf("Nome: %s\n", inimigo.nome);
    printf("ID: %d\n", inimigo.id);
    printf("Level: %d\n", inimigo.level);
    printf("Vida: %d\n", inimigo.vida);
    printf("Ataque: %d\n", inimigo.ataque);
    printf("Defesa: %d\n", inimigo.defesa);
}

int main() 
{
    /*
        VARIAVEIS
        inimigos: Registro de INIMIGOS
        t, i    : Quantidade de registros 
    */
    int t, i;
    
    // Entrada de 'n'
    scanf("%d", &t);
    getchar();
    
    INIMIGOS inimigos[t];
    
    for (i = 0; i < t; ++i)
    {
        registrar(&inimigos[i]);
    }
    
    // Imprimindo registros
    for (i = 0; i < t; ++i)
    {
        imprimir(inimigos[i]);
    }
    
    return 0;
}