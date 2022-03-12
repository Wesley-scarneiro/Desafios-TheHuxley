/*
Descrição:
Um palíndromo é uma palavra ou frase que tenha a propriedade de poder ser lida tanto da direita para a esquerda como da esquerda para a direita. Por exemplo, as strings "aaaaa", "1221", "bbaabb" são palíndromos, entretanto a string "chef" não é um palíndromo porque se lermos da direita para a esquerda, obtemos "fehc" que não é a mesma coisa que "chef".
Ignore as diferenças entre maiúsculas e minúsculas.
Para os casos onde é dada uma frase, você deve ignorar os espaços. Por exemplo, a frase "A base do teto desaba" é considerada um palíndromo. Ao lê-la da direita para a esquerda, você obterá: "abased otet od esab A". Perceba que, com exceção do espaço, a sequência de caracteres é a mesma da frase original.
Faça um programa que indique se uma string dada é um palíndromo ou não.

Formato de entrada:
A entrada consiste de um inteiro n seguido de n strings. Cada string contém no máximo 255 caracteres.

Formato de saída:
Para cada string, imprima "SIM" caso seja um palíndromo e "NAO" caso contrário.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Tamanho maximo das strings
#define T 255

/*
    Funcao que converte uma sring para minusculo
*/
void minusculo(char str[T])
{
    int i;
    
    for (i = 0; str[i] != '\0'; ++i)
    {
        // Caractere maiusculo
        if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] = (str[i] - 'A') + 'a';
        }
    }
}

/*
    Funcao que verifica se uma string eh palindromo ou nao.
*/
int verificarStr(char str[T])
{
    int i, j;
    i = 0;
    j = 0;
    
    // convertendo toda string para minusculo
    minusculo(str);
    
    // Descobrindo tamanho da string
    while (str[i] != '\0')
    {
        ++i;
    }
    --i; // Ultimo caractere.
    
    
    // Verificando se eh palindromo
    while (j <= i)
    {
        if (str[j] == ' ') ++j;
        if (str[i] == ' ') --i;
        
        if (str[j] != str[i])
        {
            return 0;
        }
        
        ++j;
        --i;
    }
    
    return 1;
}

int main() 
{
    // Variaveis
    int n;
    char str[T];
    
    // Recebendo 'n'
    scanf("%d\n", &n);
    
    while (n > 0)
    {
        // Recebendo a string
        gets(str);
        
        // Verificando se eh palindromo
        if (verificarStr(str))
        {
            printf("SIM\n");
        }
        
        else
        {
            printf("NAO\n");
        }
        --n;
    }
    
    return 0;
}