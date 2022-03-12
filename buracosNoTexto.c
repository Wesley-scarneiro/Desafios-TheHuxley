/*
Descrição:
O senhor Huxley, amigo do Ambrósio, escreveu um texto em um pedaço de papel e quer saber quantos buracos existem no texto. Mas o que é um buraco? Imagine, por exemplo, que as letras "A", "D", "O", "P", "R" possuem apenas um buraco. Da mesma forma, a letra "B" possui dois buracos. Já as letras "C", "E", "F", "K" não possuem buracos. Nós devemos considerar que o número de buracos em um texto é igual ao número total de buracos nas letras do texto. Ajude o sr. Huxley a determinar quantos buracos existem no texto.

Formato de entrada:
A primeira linha contém um inteiro simples T <= 40 que indica o número de casos de testes. Depois, seguem-se T casos de teste. Cada linha do caso de teste contém um texto não vazio composto somente de caracteres maiúsculos do alfabeto inglês. O tamanho de cada texto é menor ou igual a 100. Não existem espaços na entrada.

Formato de saída:
Para cada caso de teste, a saída consiste de uma linha contendo o número de buracos encontrado no caso de teste.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define T 100

/*
    Funcao que recebe uma string e verifica a quantidade de buracos que existem.
*/
void contarBuracos(char str[T])
{
    int i, cont;
    
    cont = 0;
    
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == 'B')
        {
            cont += 2;
        }
        
        if ((str[i] == 'A' || str[i] == 'D') || str[i] == 'Q')
        {
            ++cont;
        }
        
        if ((str[i] == 'O' || str[i] == 'P') || str[i] == 'R')
        {
            ++cont;
        }
    }
    
    printf("%d\n", cont);
}

int main() 
{
    // Casos de teste
    int t;
    
    // String
    char str[T];
    
    // Entrada de 't'
    scanf("%d\n", &t);
    
    // Entrada dos casos de teste
    while (t > 0)
    {
        gets(str);
        
        // Funcao
        contarBuracos(str);
        --t;
    }
    
    return 0;
}