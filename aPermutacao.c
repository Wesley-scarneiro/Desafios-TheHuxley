/*
Descrição:
Bob está brincando com números inteiros, ele pega um número X e permuta os dígitos desse número criando assim um número Y, Bob faz isso várias vezes até que Y seja o maior possível.
Por exemplo, se X = 690, Bob poderia criar Y's: {069, 096, 609, 690, 906, 960}; o maior deles é 960, então para X = 690, Bob está interessado no Y = 960.
Sua tarefa é criar um programa para ajudar Bob, dado um X, qual o maior Y que Bob consegue criar?

Formato de entrada:
A primeira linha da entrada contém T, o número de casos de teste.
Cada caso de teste consiste de uma linha contendo o inteiro X.
Limites:
1 <= T <= 100
0 <= X <= 10^100

Formato de saída:
Para cada caso de teste imprima em uma única linha:
Caso A: Y
onde A é o número do caso atual, começando em 1, e Y é o maior número que Bob consegue formar fazendo uma permutação de X.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Funcao que ordena a string.
    Algoritmo equivalente ao Selection sort.
*/
void buscarMaior(char n[], int c)
{
    int i, j, maior;
    
    for (i = 0; n[i] != '\0'; ++i)
    {
        for (j = i; n[j] != '\0'; ++j)
        {
            if (n[i] < n[j])
            {
                maior = n[j];
                n[j] = n[i];
                n[i] = maior;
            }
        }
    }
    
    printf("Caso %d: %s\n", c, n);
}

int main() 
{
    int casos, i;
    
    // Tamanho maximo dos numeros
    char numero[100];
    
    // Quantidade de casos
    scanf("%d", &casos);
    
    for (i = 0; i < casos; ++i)
    {
        // Numeros
        scanf("%s", numero);
        buscarMaior(numero, (i+1));
    }
    
    return 0;
}