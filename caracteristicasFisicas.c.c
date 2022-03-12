/*
Descrição:
Uma pesquisa sobre algumas características físicas da população de uma determinada região coletou os seguintes dados, referentes a cada habitante, para serem analisados:
Sexo (masculino (m), feminino (f));
Cor dos olhos (azuis (a), verdes (v), castanhos (c));
Cabelos (louros (l), castanhos (c), pretos(p));
Idade em anos.
Para cada habitante, foram digitadas duas linhas, a primeira com a idade e a segunda os outros dados e a última linha, que não corresponde a ninguém, conterá o valor igual a -1.
Escreva um programa que dê a idade do habitante mais velho e a porcentagem de mulheres que tenham idade maior ou igual a 18 e menor ou igual a 35 anos, sejam louras e tenham olhos verdes.
O percentual deve ser calculado considerando-se o total de pessoas e não somente o total de mulheres.

Formato de entrada:
Um inteiro n indicando a idade e outra linha com sexo, cabelos e cor dos olhos.
Considere que serão dadas no máximo 100 pessoas.

Formato de saída:
Mais velho: i
Mulheres com olhos verdes, loiras com 18 a 35 anos: p%
"onde i é o inteiro indicando a idade do habitante mais velho e p é a percentagem de mulheres louras de olhos verdes entre 18 e 35 anos"
O percentual deve ser formatado com duas casas decimais.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Constantes
#define MAX 100
#define FEMININO 'f'
#define VERDES 'v'
#define CASTANHOS 'c'
#define LOUROS 'l'

/*
    Estrutura das caracteristicas dos habitantes
*/
typedef struct
{   
    int idade;
    char sexo;
    char cor_olhos;
    char cor_cabelos;
} HABITANTE;

/*
    Estrutura para o resultado do problema.
*/
typedef struct
{
    int maior_idade;
    double porcentagem_mulheres;
} RESULTADO;


/*
    Funcao que recebe as entradas dos dados.
    Recebe enquanto a idade informada for != -1
*/
void receber_dados(HABITANTE habitantes[], int *total)
{
    int i, idade;
    
    // Entrada da idade
    scanf("%d", &idade);
    getchar();
    
    for (i = 0; idade != -1 && i < MAX; ++i)
    {
        habitantes[i].idade = idade;
        scanf("%c %c %c", &habitantes[i].sexo, &habitantes[i].cor_cabelos, &habitantes[i].cor_olhos);
        ++(*total);
        
        // Nova entrada
        scanf("%d", &idade);
        getchar();
    }
}

/*
    Funcao para imprimir os resultados.
    Imprime a maior idade encontrada e a porcentagem
    de mulheres com  olhos verdes, loiras com 18 a 35 anos.
*/
void imprimir_resultados(HABITANTE habitantes[], int total, RESULTADO resultado)
{
    int i, total_mulheres;
    total_mulheres = 0;
    
    resultado.maior_idade = -1;
    
    for (i = 0; i < total; ++i)
    {
        // Maior idade
        if (habitantes[i].idade > resultado.maior_idade)
        {
            resultado.maior_idade = habitantes[i].idade;
        }
        
        // Mulheres com  olhos verdes, loiras com 18 a 35 anos
        if (habitantes[i].sexo == FEMININO)
        {
            if ((habitantes[i].idade >= 18 && habitantes[i].idade <= 35) && (habitantes[i].cor_olhos == VERDES && habitantes[i].cor_cabelos == LOUROS))
            {
                ++total_mulheres;
            }
        }  
    }
    
    // Imprimindo resultados
    resultado.porcentagem_mulheres = 100*(((double)total_mulheres)/ total);
    printf("Mais velho: %d\n", resultado.maior_idade);
    printf("Mulheres com olhos verdes, loiras com 18 a 35 anos: %.2f%\n", resultado.porcentagem_mulheres);

}

int main() 
{
    /*
        total : Total de registros realizados
        habitantes: arranjo de HABITANTES
    */
    int total = 0;
    HABITANTE habitantes[MAX];
    RESULTADO resultado;
    
    // Entrada dos dados
    receber_dados(habitantes, &total);
    
    // Resultado
    imprimir_resultados(habitantes, total, resultado);

	return 0;
}