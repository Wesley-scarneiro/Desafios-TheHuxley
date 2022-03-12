/*
Descrição:
Faça um progrma para ler uma string e um caracter qualquer e imprima as posições (índices) de onde ocorre o caracter na string. Por exemplo, seja a string "abracadabra!!!" e o caracter 'a', então a sua saída deve ser:
0
3
5
7
10
-1
O valor -1 indica o final, ou seja, não existem mais ocorrências. Caso não exista nenhuma ocorrência, deve ser impresso o valor -1. 
Considere também que o 0 representa o índice do primeiro caracter em uma string.

Formato de entrada:
Você receberá duas linhas. A primeira linha contém a string e a segunda linha contém um caracter. O tamanho máximo da string é 50.

Formato de saída:
Imprima os índices, sendo um por linha.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Tamanho da string
#define T 50

/*
    Funcao que recebe uma string e um caractere, imprimindo as posicoes que
    o caractere em questao aparece na string.
*/
void imprimirPosicoes(char str[T], char caract)
{
    int i;
    
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == caract)
        {
            printf("%d\n", i);
        }
    }
    
    printf("%d\n", -1);
}

int main() 
{
    char str[T+1], caract;
    
    // Recebendo a string e o caractere
    fgets(str,(T+1), stdin);
    scanf("%c", &caract);
    
    imprimirPosicoes(str, caract);
    
    return 0;
}