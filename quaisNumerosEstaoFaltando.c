/*
Descrição:
Dado dois arrays de números inteiros imprima os númeors do primeiro array que não estão presentes no segundo array.

Formato de entrada:
Serão dadas duas linhas, correspondendo aos dois arrays.
Nos números de cada linha são separados por espaços.

Formato de saída:
Imprima em ordem decrescente os números do primeiro array que não estão presentes no segundo array.
Os números devem ser impressos todos em uma única linha e separados por um espaço.
Depois do último número não deve existir um espaço.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Tamanho maximo dos arranjos
#define MAX 100

/*
    Algoritmo para particionar o arranjo e ordenar com QuickSort.
*/
int particao(int *A, int i, int f)
{
    // Variaveis
    int pivo, j, k, temp;
    pivo = A[f];
    j = i-1;

    for (k = i; k < f; ++k)
    {
        if (A[k] <= pivo)
        {
            ++j;
            temp = A[j];
            A[j] = A[k];
            A[k] = temp;
        }
    }

    temp = A[j+1];
    A[j+1] = A[f];
    A[f] = temp;
    return (j+1);
}

/*
    QuickSort para ordenar o arranjo.
*/
void quickSort(int *A, int i, int f)
{
    if (i < f)
    {
        int q = particao(A, i, f);
        quickSort(A, i, q-1);
        quickSort(A, q+1, f);
    }
}

/*
    Funcao para receber os dados.
    O primeiro arranjo eh recebido ate encontrar-se o '\n'.
    Por fim, o segundo arranjo eh recebido ate encontrar-se o fim de linha (EOF).
*/
void receberDados(int *a, int *b, int *ta, int *tb)
{  
    int i = 0;
    char c = ' ';
    
    // Arranjo a[]
    while (c != '\n')
    {
        scanf("%d%c", &a[i], &c);
        ++i;
    }
    
    *ta = i;
    i = 0;
    
    // Arranjo b[]
    while (scanf("%d", &b[i]) != EOF)
    {
        ++i;
    }
    
    *tb = i;
}

/*
    Funcao para verificar quais sao os elementos do primeiro arranjo 
    que nao estao no segundo.
    Os elementos encontrados serao copiados para um terceiro arranjo C.
    O arranjo C eh ordenado pelo QuickSort ao final do processo.
*/
int selecionar(int *A, int ta, int *B, int tb, int *C, int *tc)
{
    int i, j, k;

    k = 0;
    
    for (i = 0; i < ta; ++i)
    {
        for (j = 0; j < tb; ++j)
        {
            // Encerrar comparacao com o i-esimo elemento
            if (A[i] == B[j])
            {
                break;
            }
        }
        
        if (j == tb)
        {
            C[k] = A[i];
            ++k;
        }
    }
    
    *tc = k;
    quickSort(C, 0, k-1);
}


/*
    Funcao para imprimir um arranjo A de tamanho 'n'.
*/
void imprimir(int *A, int n)
{
    int i;
    
    for (i = n - 1; i >=0 ; --i)
    {
        printf("%d ", A[i]);
    }
    
    printf("\n");
}


int main()
{
    int a[MAX];
    int b[MAX];
    int c[MAX];
    int ta, tb, tc;
    
    receberDados(a, b, &ta, &tb);
    selecionar(a, ta, b, tb, c, &tc);
    imprimir(c, tc);
    
    return 0;
}