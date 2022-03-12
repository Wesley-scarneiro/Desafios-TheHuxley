/*
Descrição:
"Steve Trabalhos" é um rapaz americano que gostou muito do Brasil e resolveu morar aqui. Ele descolou um trabalho de tradutor de textos. Entretanto, Steve ainda está um pouco atrapalhado com o português e cometeu alguns erros de tradução. O chefe disse a lista de palavras que estão erradas, seguidas da escrita correta. Assim, ajude o Steve a corrigir a lambança que ele fez.

Formato de entrada:
Consiste de dois inteiros n e m, indicando o número de regras de substituições, e o número de linhas do texto, respectivamente. Da segunda linha em diante, está uma sequência de n linhas indicando quais devem ser as substituições (estas são as regras de substituição) a serem realizadas e por fim, uma sequência de m linhas correspondendo ao texto errado que Steve gerou. As substituições estão no formato: STRING_A_SER_SUBSTITUIDA -> STRING_SUBSTITUTA. (perceba que existe um espaço antes e depois da string  "->" ).
A substituição pode ser somente de algumas letras em uma palavra. Por exemplo:
2 1
a -> o
rei -> rainha
O rato roeu A roupa do rei de roma
Neste caso, a resposta correta seria:
O roto roeu A roupo do rainha de romo
A substituição deve distinguir maiúsculas de minúsculas.
A entrada termina quando n=0 e m=0

Formato de saída:
O texto corrigido.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Dimensoes das matrizes
#define T1 100
#define T2 50

/*
    Funcao que concatena strings.
*/
void concatenar(char correcoes[T2][T2], char texto[T1][T1], int i, int j, char* p, int t)
{
    char temp[T1] = "\0";
    int pos;

    // Posicao do primeiro caractere da errada e o tamanho da errada
    pos = p - texto[j];

    // Copiando os 'pos' primeiros caracteres
    strncpy(temp, texto[j], pos);

    // Concatenando a correcao
    strcat(temp, correcoes[i+1]);

    // Concatenando o restando da string
    strcat(temp, p+t);

    // Corrigindo a linha do texto
    strcpy(texto[j], temp);

}


/*
    Funcao para realizar as substituicoes, atraves da funcao concatenar.
*/
void substituir(char correcoes[T2][T2], char texto[T1][T1], int t1, int t2)
{
    int i, j, k, t;
    k = 0;

    char* p;

    // Percorre as correcoes
    for (i = 0; i < 2*t1; i += 2)
    {
        // Percorre o texto
        for (j = 0; j < t2; ++j)
        {
            // Quantidade total de caracteres da linha atual do texto
            k = strlen(texto[j]);
            t = strlen(correcoes[i]);

            while (k > 0)
            {
                // Localiza a substituicao
                p = strstr(texto[j], correcoes[i]);
            
                if (p != NULL)
                {
                    concatenar(correcoes, texto, i, j, p, t);
                }
                else
                {
                    break;
                }
                
                t = strlen(correcoes[i+1]);
                --k;
            }
        }
    }
}

/*
    Funcao que recebe as entradas e chama outras funcoes para a correcao do texto.
*/
void resultado(char correcoes[T2][T2], char texto[T1][T1], int t1, int t2)
{
    int i;
    
    // Rebendo as correcoes
    for (i = 0; i < 2*t1; i += 2)
    {
        scanf("%s -> %s\n", correcoes[i], correcoes[i+1]);
    }
    
    // Rebendo o texto
    for (i = 0; i < t2; ++i)
    {
        gets(texto[i]);
    }

    // Substituindo
    substituir(correcoes, texto, t1, t2);

    // Imprimindo texto
    for (i = 0; i < t2; ++i)
    {
        puts(texto[i]);
    }
}

int main()
{
    // Matriz para receber as correcoes e o texto
    char correcoes[T2][T2];
    char texto[T1][T1];
    
    // Numero de correcoes e linhas do texto
    int t1, t2;

    // Primeira entrada de t1 e t2
    scanf("%d %d", &t1, &t2);
    
    while (t1 != 0 && t2 != 0)
    {
        resultado(correcoes, texto, t1, t2);

        // Nova entrada
        scanf("%d %d", &t1, &t2);
    }

    return 0;
}