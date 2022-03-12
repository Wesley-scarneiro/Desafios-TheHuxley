/*
Descrição:
Inicialmente, preencha três arrays, Y, X e Z ambos de comprimento 10. (X[0]......[X[9]) , com valores pseudo-aleatórios da seguinte forma:
Y[0] = seedY
Y[i] = (Y[i - 1] * A + B) % modC
X[0] = seedX
X[i] = (X[i - 1] * B + C) % modA
Z[0] = seedZ
Z[i] = (Z[i - 1] * C + A) % modB
(seedY, seedX, seedZ, A, B ,C) dados de entrada !=0;
1)      Criar uma função que calcule todos esses elementos e que retorne o maior elemento de cada vetor.
2)      Some todos os elementos, (int Soma = MaxX + MaxY +MaxZ);
3)       Chame a função <tipo> Modulo( soma, A, B, C){....}
Que faz o valor da soma se tornar  = soma mod((A/B)+C);
E salva na mesma variável(soma).
(o tipo eh de sua escolha)
4)  imprima soma seguido de um (quebra/pular a linha)
OBS:
scanf("%d %d %d %d %d %d",&A,&B,&C,&seedX,&seedY,&seedZ);

Formato de entrada:
216  57  740  245  433  871
216  57  740  245  433  871

Formato de saída:
359
359
*/

#include <stdio.h>

// Tamanho dos arrays
#define T 10

/*
    Funcao para percorrer os arrays e guardar o maior elemento em 'soma'.
    Realiza uma busca simples, isto e, a sequencial.
*/
void somarMaiores(int x[], int y[], int z[], int *soma)
{
    int i, maior;

    maior = x[0];
    for (i = 1; i < T; ++i)
    {
        if (maior < x[i])
        {
            maior = x[i];
        }
    }

    *soma = maior;

    maior = y[0];
    for (i = 1; i < T; ++i)
    {
        if (maior < y[i])
        {
            maior = y[i];
        }
    }

    *soma += maior;

    maior = z[0];
    for (i = 1; i < T; ++i)
    {
        if (maior < z[i])
        {
            maior = z[i];
        }
    }

    *soma += maior;
}


/*
    Funcao para popular os arrays
*/
void popularArrays(int x[], int y[], int z[], int A, int B, int C)
{
    int i;

    // Para x[]
    for (i = 1; i < T; ++i)
    {
        x[i] = (x[i - 1] * B + C) % A;
    }

    // Para y[]
    for (i = 1; i < T; ++i)
    {
        y[i] = (y[i - 1] * A + B) % C;
    }

    // Para[z]
    for (i = 1; i < T; ++i)
    {
        z[i] = (z[i - 1] * C + A) % B;
    }
    
}

/*
    Funcao que agrega as outras para o resultado final.
*/
void resultado(int x[], int y[], int z[], int A, int B, int C, int *soma)
{
    popularArrays(x, y, z, A, B, C);
    somarMaiores(x, y, z, soma);

    // Operacao final em 'soma'
    *soma = *soma % ((A/B) + C);

    printf("%d\n", *soma);
    *soma = 0;
}

int main()
{
    // Variaveis
    int x[T], y[T], z[T], A, B, C, soma;
    
    // Recebe enquando scanf() nao retornar a contante EOF.
    while (scanf("%d %d %d %d %d %d", &A, &B, &C, &x[0], &y[0], &z[0]) != EOF)
    {
        resultado(x, y, z, A, B, C, &soma);
    }
    
    return 0;
}