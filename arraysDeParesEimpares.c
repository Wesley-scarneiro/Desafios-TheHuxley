/*
Descrição:
Neste problema você deverá ler 15 valores colocá-los em 2 arrays conforme estes valores forem pares ou ímpares. Só que o tamanho de cada um dos dois arrays é de 5 posições. Então, cada vez que um dos dois arrays encher, você deverá imprimir todo o array e utilizá-lo novamente para os próximos números que forem lidos. Terminada a leitura, deve-se imprimir o conteúdo que restou em cada um dos dois arrays, imprimindo primeiro os valores do array ímpar. Cada array pode ser preenchido tantas vezes quantas for necessário.

Formato de entrada:
A entrada contém 15 números inteiros.

Formato de saída:
Imprima a saída conforme o exemplo de saída.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Tamanho dos arrays e da entrada
#define T 5
#define MAX 15

/*
    Funcao que imprime os elementos de um array ate uma dada posicao.
*/
void imprimir(int array[], int max, int tipo)
{
    int i;
    
    if (tipo == 1)
    {
        for (i = 0; i <= max; ++i)
        {
            printf("par[%d] = %d\n", i, array[i]);
        }
    }
    else
    {
        for (i = 0; i <= max; ++i)
        {
            printf("impar[%d] = %d\n", i, array[i]);
        }
    }
}


/*
    Funcao que ordena as operacoes para separar as entradas entre pares e impares.
*/
void receberSeparar(int pares[], int impares[], int *tP, int *tI)
{
    /*
        i: Quantidade maxima de entradas
        n: Onde sera recebida as entradas
    */
    int i, n;
    
    i = MAX;
    
    while (i > 0)
    {
        scanf("%d", &n);
        
        // Par
        if (n % 2 == 0)
        {
            if ((*tP) < 4)
            {
                pares[(*tP)] = n;
                ++(*tP);
            }
            else
            {
                pares[(*tP)] = n;
                imprimir(pares, (*tP), 1);
                (*tP) = 0;
            }
        }
        else
        {
            if ((*tI) < 4)
            {
                impares[(*tI)] = n;
                ++(*tI);
            }
            else
            {
                impares[(*tI)] = n;
                imprimir(impares, (*tI), 0);
                (*tI) = 0;
            }
        }
        --i;
    }
    
    imprimir(impares, (*tI)-1, 0);
    imprimir(pares, (*tP)-1, 1);
}

int main() 
{
    /*
        pares[]: Onde serao recebido os pares
        impares[]: Onde serao recebido os impares
        tP: Indice de pares recebidos de 0 a 4
        tI: Indice de impares recebidos de 0 a 4
    */
    int pares[T], tP, tI, impares[T];
    
    tP = 0;
    tI = 0;
    
    // Funcao
    receberSeparar(pares, impares, &tP, &tI);
    
    return 0;
}